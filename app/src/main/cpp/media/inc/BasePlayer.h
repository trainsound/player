//
// Created by media on 2018. 7. 24..
//

#ifndef PLAYER_NATIVEPLAYER_H
#define PLAYER_NATIVEPLAYER_H

#include <string.h>
#include <iostream>
#include "../../Util/inc/Thread.h"

using namespace std;

class BasePlayer : public Thread{

public:
    BasePlayer(void *arg) : Thread(arg){};

    virtual void setDatasource(string url) = 0;
    virtual void prepare() = 0;
    virtual void play() = 0;
    virtual void stop() = 0;
    virtual void run() = 0;
};


#endif //PLAYER_NATIVEPLAYER_H
