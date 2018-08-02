//
// Created by lena on 2018. 4. 24..
//

#include "../inc/Thread.h"
#include "../inc/log.h"

static void* pthreadCreate(void* arg){
    Thread *thread = (Thread*)arg;
    thread->run();
    return NULL; // must return void pointer
}

Thread::Thread(void* arg){
    FUNCTION_IN();
    this->runFlag = true;
    //if to create, to save id in thread that return value 0.
    if(pthread_create(&(this->thread), NULL, pthreadCreate, arg) < 0){
        //exit
        this->runFlag = false;
    }
    FUNCTION_OUT();
}

Thread::~Thread(){
    FUNCTION_IN();
    FUNCTION_OUT();
}

bool Thread::getRunnableFlag(){
    return runFlag;
}

int Thread::threadStop(){
    FUNCTION_IN();
    this->runFlag = false;
    FUNCTION_OUT();
    return 0;
}