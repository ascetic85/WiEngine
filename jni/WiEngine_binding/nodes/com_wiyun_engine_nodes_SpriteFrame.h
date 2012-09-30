/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_wiyun_engine_nodes_SpriteFrame */

#ifndef _Included_com_wiyun_engine_nodes_SpriteFrame
#define _Included_com_wiyun_engine_nodes_SpriteFrame
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_wiyun_engine_nodes_SpriteFrame
 * Method:    nativeInit
 * Signature: (FLcom/wiyun/engine/opengl/Texture2D;Lcom/wiyun/engine/types/WYRect;Lcom/wiyun/engine/types/WYPoint;Lcom/wiyun/engine/types/WYSize;Z)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_nativeInit
  (JNIEnv *, jobject, jfloat, jobject, jobject, jobject, jobject, jboolean);

/*
 * Class:     com_wiyun_engine_nodes_SpriteFrame
 * Method:    nativeGetTexture
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_nativeGetTexture
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_nodes_SpriteFrame
 * Method:    nativeGetRect
 * Signature: (Lcom/wiyun/engine/types/WYRect;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_nativeGetRect
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_nodes_SpriteFrame
 * Method:    nativeGetSourceColorRect
 * Signature: (Lcom/wiyun/engine/types/WYRect;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_nativeGetSourceColorRect
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_nodes_SpriteFrame
 * Method:    nativeGetOffset
 * Signature: (Lcom/wiyun/engine/types/WYPoint;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_nativeGetOffset
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_nodes_SpriteFrame
 * Method:    nativeGetOriginalSize
 * Signature: (Lcom/wiyun/engine/types/WYPoint;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_nativeGetOriginalSize
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_nodes_SpriteFrame
 * Method:    setRotated
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_setRotated
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     com_wiyun_engine_nodes_SpriteFrame
 * Method:    isRotated
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_isRotated
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_nodes_SpriteFrame
 * Method:    setTexture
 * Signature: (Lcom/wiyun/engine/opengl/Texture2D;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_setTexture
  (JNIEnv *, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif