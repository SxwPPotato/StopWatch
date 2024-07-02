#include "stop_watch.h"

stop_watch::stop_watch(){

    ms = 0;
    s = 0;
    m = 0;
    tx_ms = 0;
    tx_s = 0;
    tx_m = 0;
    timer = new QTimer();
    tx_timer = new QTimer();

}

void stop_watch::circle_tx_timer()
{
    tx_ms++;
    if(tx_ms >= 10){
        tx_ms = 0;
        tx_s++;
    }

    if(tx_s >= 60){
        tx_s = 0;
        tx_m++;
    }

}

void stop_watch::circle_timer()
{
    ms++;
    if(ms >= 10){
        ms = 0;
        s++;
    }

    if(s >= 60){
        s = 0;
        m++;
    }

}

void stop_watch::clear(){

    ms = 0;
    s = 0;
    m = 0;
    tx_m  = 0 ;
    tx_s = 0;
    tx_ms = 0;
    count = 1;

}

void stop_watch::timer_start(){
    timer->start(100);
    tx_timer->start(100);
}

void stop_watch::timer_stop(){
    timer->stop();
    tx_timer->stop();
}
