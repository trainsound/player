//
// Created by train on 2018-04-04.
// medialibrary
// 1. nativestart
// 2. nativestop
//

#include<jni.h>
#include"../inc/log.h"
#include <stdio.h>

jint init(JavaVM *jvm, jstring url){
    LOGI("nativeInit ");

//    JNI_CreateJavaVM
    return 0;
}

int nativeSetSurface(JavaVM *jvm, jobject surface){
    LOGI("set surface");
    return 0;
}
static JNINativeMethod sMethod[] = {
        {"nativeInit", "(Ljava/lang/String;)I", (void*)init},
        {"nativeSetSurface", "(Ljava/lang/Object;)I",(void*)nativeSetSurface}
};

JNIEXPORT int JNI_OnLoad(JavaVM* vm, void* reserved) {
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

    return JNI_VERSION_1_6;
}
