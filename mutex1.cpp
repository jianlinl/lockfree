#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "timer.h"

pthread_mutex_t mutex_lock;
static volatile int count = 0;
void *test_func(void *argc){

    int i = 0;
    for(i=0; i<2000000; i++){
        pthread_mutex_lock(&mutex_lock);
        count++ ;
        pthread_mutex_unlock(&mutex_lock);
    }
    return NULL;
}

int main(int argc, const char * argv[]){

    Timer timer;
    timer.Start();
    pthread_mutex_init(&mutex_lock, NULL);
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
