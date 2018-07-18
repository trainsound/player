//
// Created by lena on 2018. 4. 24..
//

#ifndef MEDIA_THREAD_H
#define MEDIA_THREAD_H

#include<pthread.h>

class Thread {
    private:
        pthread_t thread;
        bool runFlag;
    public :
        Thread(void *arg);
        ~Thread();
        virtual void run();

        bool getRunnableFlag();
        int threadStop();
        int threadPause();
        int threadResume();
};


#endif //MEDIA_THREAD_H
