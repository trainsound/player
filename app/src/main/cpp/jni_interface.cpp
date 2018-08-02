//
// Created by train on 2018-04-04.
// medialibrary
// 1. nativestart
// 2. nativestop
//

#include<jni.h>
#include"Util/inc/log.h"
#include "media/inc/BasePlayer.h"
#include "media/inc/AndroidMediaPlayer.h"
#include <stdio.h>
#include <string>

using namespace std;

BasePlayer *player = NULL;

int setDataSource(JavaVM *jvm, jstring url){
    FUNCTION_IN();
    LOGE("setDataSource", url);
    player = new AndroidMediaPlayer();

//    BasePlayer *player = new AndroidMediaPlayer();
//    player->play();

    FUNCTION_OUT();

    return 0;
}

int stop(){
    FUNCTION_IN();
player->stop();
    FUNCTION_OUT();
    return 0;
}

int play(){
    FUNCTION_IN();
    FUNCTION_OUT();
    return 0;
}

int start(){
    FUNCTION_IN();
    FUNCTION_OUT();

    return 0;
}


static JNINativeMethod sMethod[] = {
        {"nativeSetDataSource", "(Ljava/lang/String;)I", (void*)setDataSource},
        {"nativePlay", "()I",(void*)play},
        {"nativeStop", "()I",(void*)stop}

};

JNIEXPORT int JNI_OnLoad(JavaVM* vm, void* reserved) {
    FUNCTION_IN();

    JNIEnv* env = NULL;
    jint result = -1;

    if(vm->GetEnv((void**) &env, JNI_VERSION_1_6) != JNI_OK){
        return result;
    }

        //함수 사이즈 제대로 받게끔 수정해야함
#define GetMethod(className, sMethod) \
        jclass clazz = env->FindClass(className); \
        if(clazz == NULL){ \
            return -1; \
        } \
        if(env->RegisterNatives(clazz, sMethod, 3) < 0){ \
            return -1; \
        } \

    GetMethod("medialibrary/Medialibrary", sMethod);

//    MediaPlayerInit(env);

    FUNCTION_OUT();

    return JNI_VERSION_1_6;
}


