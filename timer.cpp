#include "timer.h"
#include <stdio.h>

Timer::Timer(){

    b1 = false;
    b2 = false;
}

void Timer::Start(){

    gettimeofday(&t1, NULL);
    b1 = true;
    b2 = false;
}

void Timer::Stop(){

    if(b1 == true){
        gettimeofday(&t2, NULL);
        b2 = true;
    }
}

void Timer::Reset(){

    b1 = false;
    b2 = false;
}

void Timer::Cost_time(){

    if( !b1 || !b2){
        printf("wnring: timer fail");
    }
    else{
        int usec, sec;
        bool borrow = false;
        if (t2.tv_usec > t1.tv_usec) {
            usec = t2.tv_usec - t1.tv_usec;        
        }
        else{
            borrow = true;
            usec = t2.tv_usec + 1000000 - t1.tv_usec;
        }

        if(borrow){
            sec = t2.tv_sec - 1 - t1.tv_sec;
        }
        else{
            sec = t2.tv_sec - t1.tv_sec;
        }
        printf("timer: cost time: %d sec, %d usec.\n", sec, usec);
    }
}

