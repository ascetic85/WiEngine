/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_wiyun_engine_chipmunk_Space */

#ifndef _Included_com_wiyun_engine_chipmunk_Space
#define _Included_com_wiyun_engine_chipmunk_Space
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    nativeGetBodies
 * Signature: ([I)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_nativeGetBodies
  (JNIEnv *, jobject, jintArray);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    addPostStepCallback
 * Signature: (Lcom/wiyun/engine/chipmunk/Space/IPostStepCallback;Ljava/lang/Object;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_addPostStepCallback
  (JNIEnv *, jobject, jobject, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    addCollisionHandler
 * Signature: (IILcom/wiyun/engine/chipmunk/ICollisionHandler;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_addCollisionHandler
  (JNIEnv *, jobject, jint, jint, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    removeCollisionHandler
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_removeCollisionHandler
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    addShape
 * Signature: (Lcom/wiyun/engine/chipmunk/Shape;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_addShape
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    removeShape
 * Signature: (Lcom/wiyun/engine/chipmunk/Shape;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_removeShape
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    addStaticShape
 * Signature: (Lcom/wiyun/engine/chipmunk/Shape;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_addStaticShape
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    removeStaticShape
 * Signature: (Lcom/wiyun/engine/chipmunk/Shape;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_removeStaticShape
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    addBody
 * Signature: (Lcom/wiyun/engine/chipmunk/Body;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_addBody
  (JNIEnv *, jobject, jobject);


/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    removeBody
 * Signature: (Lcom/wiyun/engine/chipmunk/Body;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_removeBody
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    prepareShapesOfBody
 * Signature: (Lcom/wiyun/engine/chipmunk/Body;)I
 */
JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Space_prepareShapesOfBody
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    cleanShapesOfBody
 * Signature: (Lcom/wiyun/engine/chipmunk/Body;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_cleanShapesOfBody
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    getShapeOfBody
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Space_getShapeOfBody
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    nativeGetAnyShape
 * Signature: (Lcom/wiyun/engine/chipmunk/Body;)I
 */
JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Space_nativeGetAnyShape
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    removeAndDestroyBody
 * Signature: (Lcom/wiyun/engine/chipmunk/Body;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_removeAndDestroyBody
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    removeAndDestroyShapesOfBody
 * Signature: (Lcom/wiyun/engine/chipmunk/Body;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_removeAndDestroyShapesOfBody
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    scheduleRemoveAndDestroyShapeAndBody
 * Signature: (Lcom/wiyun/engine/chipmunk/Shape;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_scheduleRemoveAndDestroyShapeAndBody
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    addConstraint
 * Signature: (Lcom/wiyun/engine/chipmunk/Constraint;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_addConstraint
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    removeConstraint
 * Signature: (Lcom/wiyun/engine/chipmunk/Constraint;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_removeConstraint
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    getBodyCount
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Space_getBodyCount
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    destroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_destroy
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    visitBody
 * Signature: (Lcom/wiyun/engine/chipmunk/Space/IBodyVisitor;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_visitBody
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    resizeActiveHash
 * Signature: (FI)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_resizeActiveHash
  (JNIEnv *, jobject, jfloat, jint);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    resizeStaticHash
 * Signature: (FI)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_resizeStaticHash
  (JNIEnv *, jobject, jfloat, jint);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    setIterations
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_setIterations
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    setElasticIterations
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_setElasticIterations
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    step
 * Signature: (F)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_step
  (JNIEnv *, jobject, jfloat);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    setGravity
 * Signature: (FF)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_setGravity
  (JNIEnv *, jobject, jfloat, jfloat);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    getGravityX
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Space_getGravityX
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    getGravityY
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Space_getGravityY
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    querySegmentFirst
 * Signature: (FFFFIILcom/wiyun/engine/chipmunk/Space/SegmentQueryInfo;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_querySegmentFirst
  (JNIEnv *, jobject, jfloat, jfloat, jfloat, jfloat, jint, jint, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    rehashStatic
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_rehashStatic
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    getStamp
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Space_getStamp
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    isLocked
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_chipmunk_Space_isLocked
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    getDamping
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Space_getDamping
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    setDamping
 * Signature: (F)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_setDamping
  (JNIEnv *, jobject, jfloat);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    nativeQueryPointFirst
 * Signature: (FFII)I
 */
JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Space_nativeQueryPointFirst
  (JNIEnv *, jobject, jfloat, jfloat, jint, jint);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    queryPoint
 * Signature: (FFIILcom/wiyun/engine/chipmunk/Space/IPointQueryCallback;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_queryPoint
  (JNIEnv *, jobject, jfloat, jfloat, jint, jint, jobject, jobject);

/*
 * Class:     com_wiyun_engine_chipmunk_Space
 * Method:    querySegment
 * Signature: (FFFFIILcom/wiyun/engine/chipmunk/Space/ISegmentQueryCallback;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_querySegment
  (JNIEnv *, jobject, jfloat, jfloat, jfloat, jfloat, jint, jint, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif