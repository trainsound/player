
//
// Created by media on 2018. 7. 26..
//

#include <jni.h>
#include "../../Util/inc/log.h"
#include "../inc/AndroidMediaPlayer.h"

#define BUFFER_FLAG_CODEC_CONFIG  2
#define BUFFER_FLAG_END_OF_STREAM 4
#define INFO_OUTPUT_BUFFERS_CHANGED -3
#define INFO_OUTPUT_FORMAT_CHANGED  -2
#define INFO_TRY_AGAIN_LATER        -1

static void registerMethod(JNIEnv *env, jobject obj);

AndroidMediaPlayer::AndroidMediaPlayer() : BasePlayer(this){
//    registerMethod();
}

AndroidMediaPlayer::~AndroidMediaPlayer() {

}

static void registerMethod(JNIEnv *env, jobject obj){
    FUNCTION_IN();
    static jclass MediaExtractor = env->FindClass("android.media.MediaExtractor");
    static jmethodID extractor_setDataSource = env->GetMethodID(MediaExtractor, "setDataSource", "(Ljava/lang/String)V");
    static jmethodID extractor_getTrackCount = env->GetMethodID(MediaExtractor, "getTrackCount", "()I");
    static jmethodID extractor_getTrackFormat = env->GetMethodID(MediaExtractor, "getTrackFormat", "(I)Landroid/media/MediaFormat;");
    static jmethodID extractor_selectTrack = env->GetMethodID(MediaExtractor, "selectTrack", "(I)V");
    static jmethodID extractor_readSampleData = env->GetMethodID(MediaExtractor, "readSampleData", "(Ljava/nio/ByteBuffer;I)I");
    static jmethodID extractor_advance = env->GetMethodID(MediaExtractor, "advance", "()Z");
    static jmethodID extractor_release = env->GetMethodID(MediaExtractor, "release", "()V");

    static jclass mediaCodec = env->FindClass("android.media.MediaCodec");
    static jmethodID mediaCodec_createDecoderByType = env->GetMethodID(mediaCodec, "createDecoderByType", "(Ljava/io/FileDescriptor;JJ)V");
    static jmethodID mediaCodec_configure = env->GetMethodID(mediaCodec, "configure", "(Landroid/media/MediaFormat;Landroid/view/Surface;Landroid/media/MediaCrypto;I)V");
    static jmethodID mediaCodec_start = env->GetMethodID(mediaCodec, "start", "()V");
    static jmethodID mediaCodec_getInputBuffers = env->GetMethodID(mediaCodec, "getInputBuffers", "()[Ljava/nio/ByteBuffer;");
    static jmethodID mediaCodec_dequeueInputBuffer = env->GetMethodID(mediaCodec, "dequeueInputBuffer", "(J)I");
    static jmethodID mediaCodec_queueInputBuffer = env->GetMethodID(mediaCodec, "queueInputBuffer", "(IIIJI)V");
    static jmethodID mediaCodec_getOutputBuffers = env->GetMethodID(mediaCodec, "getOutputBuffers", "()[Ljava/nio/ByteBuffer;");
    static jmethodID mediaCodec_dequeueOutputBuffer = env->GetMethodID(mediaCodec, "dequeueOutputBuffer", "(Landroid/media/MediaCodec$BufferInfo;J)I");
    static jmethodID mediaCodec_getOutputFormat = env->GetMethodID(mediaCodec, "getOutputFormat", "()Landroid/media/MediaFormat;");
    static jmethodID mediaCodec_releaseOutputBuffer = env->GetMethodID(mediaCodec, "releaseOutputBuffer", "(IZ)V");
    static jmethodID mediaCodec_stop = env->GetMethodID(mediaCodec, "stop", "()V");
    static jmethodID mediaCodec_release = env->GetMethodID(mediaCodec, "release", "()V");

    static jclass mediaFormat = env->FindClass("android.media.MediaFormat");

    /* Get String field from OtherClass */
    jfieldID fidStringOtherClass = env->GetFieldID(mediaFormat, "KEY_MIME", "Ljava/lang/String;");
    jobject sValOtherClass = env->GetObjectField(obj, fidStringOtherClass);

    // we have to get string bytes into C string
    const char *c_str_oc;
    c_str_oc = env->GetStringUTFChars((jstring )sValOtherClass, NULL);
    if(c_str_oc == NULL) {
        return;
    }

    static jclass mediaBufferInfo = env->FindClass("android.media.MediaCodec.BufferInfo");
    jfieldID jl= env->GetFieldID(mediaBufferInfo, "presentationTimeUs", "J");
    jlong presentationTimeUs_long = env->GetLongField(obj, jl);

    jfieldID ji = env->GetFieldID(mediaBufferInfo, "flags", "I");
    jint flag_long = env->GetIntField(obj, ji);
    FUNCTION_IN();
}

void AndroidMediaPlayer::setDatasource(string url) {
    this->url = url;
}

void AndroidMediaPlayer::prepare() {

}

void AndroidMediaPlayer::play() {
    run();
}

void AndroidMediaPlayer::stop() {
    threadStop();
}

void AndroidMediaPlayer::run() {
    FUNCTION_IN();
    while(getRunnableFlag()){
        LOGE("runnñ1n1nn1n1n1nnnnnnnnnnnnnn-----------------");
    }
    FUNCTION_OUT();
}