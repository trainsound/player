//
// Created by train on 2018-04-04.
// medialibrary
// 1. nativestart
// 2. nativestop
//

#include<jni.h>
#include"../inc/log.h"
#include <stdio.h>
#include <string>

using namespace std;

jint init(JavaVM *jvm, jstring url){
    FUNCTION_IN();
    FUNCTION_OUT();
    return 0;
}

int nativeSetSurface(JavaVM *jvm, jobject surface){
    FUNCTION_IN();
    FUNCTION_OUT();
    return 0;
}

int setDataSource(JavaVM *jvm, jstring url){
    FUNCTION_IN();
    FUNCTION_OUT();
}

int start(){
    FUNCTION_IN();
    FUNCTION_OUT();
}

int stop(){
    FUNCTION_IN();
    FUNCTION_OUT();
}

static JNINativeMethod sMethod[] = {
        {"nativeInit", "(Ljava/lang/String;)I", (void*)init},
        {"nativeSetSurface", "(Ljava/lang/Object;)I",(void*)nativeSetSurface}

};

void MediaPlayerInit(JNIEnv* env){
    FUNCTION_IN();
    static jclass mediaCls = env->FindClass("android/media/MediaPlayer");
    static jmethodID setDataSourceId = env->GetMethodID(mediaCls, "setDataSource", "(Ljava/io/FileDescriptor;JJ)V");
    static jmethodID setDisplayId = env->GetMethodID(mediaCls, "setDisplay", "(Landroid/view/SurfaceHolder;)V");
    static jmethodID prepareId = env->GetMethodID(mediaCls, "prepare", "()V");
    static jmethodID stopId = env->GetMethodID(mediaCls, "stop", "()V");
    FUNCTION_OUT();
}

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
        if(env->RegisterNatives(clazz, sMethod, 2) < 0){ \
            return -1; \
        } \

    GetMethod("medialibrary/Medialibrary", sMethod);

    MediaPlayerInit(env);

    FUNCTION_OUT();

    return JNI_VERSION_1_6;
}


