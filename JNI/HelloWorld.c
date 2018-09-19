#include <stdio.h>
#include <jni.h>

#include "hellojni_HelloJNI.h"

JNIEXPORT jint JNICALL Java_hellojni_HelloJNI_displayHelloWorld(JNIEnv *envP, jobject jObj){
    printf("Hello World");
    return 0;
}

