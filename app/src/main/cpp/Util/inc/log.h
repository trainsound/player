//
// Created by train on 2018-04-04.
//

#ifndef PLAYER_LOG_H
#define PLAYER_LOG_H

#include <android/log.h>

#define LOGV(...)   __android_log_print(ANDROID_LOG_VERBOSE, "medialibrary", __VA_ARGS__)
#define LOGD(...)   __android_log_print(ANDROID_LOG_DEBUG, "medialibrary", __VA_ARGS__)
#define LOGI(...)   __android_log_print(ANDROID_LOG_INFO, "medialibrary", __VA_ARGS__)
#define LOGW(...)   __android_log_print(ANDROID_LOG_WARN, "medialibrary", __VA_ARGS__)
#define LOGE(...)   __android_log_print(ANDROID_LOG_ERROR, "medialibrary", __VA_ARGS__);

#endif //PLAYER_LOG_H
