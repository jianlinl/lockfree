#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include "timer.h"

#define mySpinLock(lock) do{\
    while(!__sync_bool_compare_and_swap(lock,0,1)){ \
        sched_yield();\
    }\
}while(0)

#define mySpinUnlock(lock) do{\
    *lock = 0;\
}while(0)

int lock = 0;
static volatile int count = 0;

void *test_func(void *argc){
    int i;
    for(i=0; i<2000000; i++){
        mySpinLock(&lock);
        count++;
        mySpinUnlock(&lock);
    }
    return NULL;
}

int main(int argc, const char * argv[]){

    Timer timer;
    timer.Start();
    pthread_t thread_ids[10];
    int i =0, size = sizeof(thread_ids) / sizeof(pthread_t);
    for(i=0; i<size; i++){
        pthread_create(&thread_ids[i], NULL, test_func, NULL);
    }

    for(i=0; i<size; i++){
        pthread_join(thread_ids[i], NULL);
    }

    timer.Stop();
    timer.Cost_time();
    printf("result: count = %d\n", count);
    return 0;
}
