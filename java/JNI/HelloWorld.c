#include <stdio.h>
#include <jni.h>

#include "test_TestJni.h"

JNIEXPORT jint JNICALL Java_test_TestJni_displayHelloWorld(JNIEnv * env, jobject obj)
{
    printf("%s", "Hello World");
    return 0;
}

