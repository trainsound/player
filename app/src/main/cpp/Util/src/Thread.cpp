//
// Created by lena on 2018. 4. 24..
//

#include "../inc/Thread.h"

void* pthreadCreate(void* arg){
    Thread *thread = (Thread*)arg;
    thread->run();
}

Thread::Thread(void* arg){
    this->runFlag = true;
    if(!pthread_create(&(this->thread), NULL, pthreadCreate, arg)){
        //exit
        this->runFlag = false;
    }
}

Thread::~Thread(){
    
}

bool Thread::getRunnableFlag(){
    return runFlag;
}

int Thread::threadStop(){
    this->runFlag = false;
}

void Thread::run(){

}