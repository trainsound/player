//
// Created by media on 2018. 7. 26..
//

#ifndef PLAYER_ANDROIDMEDIAPLAYER_H
#define PLAYER_ANDROIDMEDIAPLAYER_H

#include "BasePlayer.h"

class AndroidMediaPlayer : public BasePlayer{
private:
    string url;

public:
    AndroidMediaPlayer();
    ~AndroidMediaPlayer();

    //MediaCodec, MediaExtractor
    void registerMethod();

    virtual void setDatasource(string url);
    virtual void prepare();
    virtual void play();
    virtual void stop();
    virtual void run();

};
#endif //PLAYER_ANDROIDMEDIAPLAYER_H
