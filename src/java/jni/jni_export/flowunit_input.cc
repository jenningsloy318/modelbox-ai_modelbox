
/*
 * Copyright 2021 The Modelbox Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <modelbox/base/log.h>
#include <modelbox/flowunit.h>

#include <memory>

#include "com_modelbox_FlowUnitInput.h"
#include "jni_native_object.h"
#include "scoped_jvm.h"
#include "throw.h"
#include "utils.h"

/*
 * Class:     com_modelbox_FlowUnitInput
 * Method:    FlowUnitInput_New
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL
Java_com_modelbox_FlowUnitInput_FlowUnitInput_1New__Ljava_lang_String_2(
    JNIEnv *env, jobject j_this, jstring j_name) {
  auto name = modelbox::jstring2string(env, j_name);
  return modelbox::JNINativeObject::NewHandle(
      j_this, std::make_shared<modelbox::FlowUnitInput>(name));
}

/*
 * Class:     com_modelbox_FlowUnitInput
 * Method:    FlowUnitInput_New
 * Signature: (Ljava/lang/String;Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL
Java_com_modelbox_FlowUnitInput_FlowUnitInput_1New__Ljava_lang_String_2Ljava_lang_String_2(
    JNIEnv *env, jobject j_this, jstring j_name, jstring j_device_type) {
  auto name = modelbox::jstring2string(env, j_name);
  auto device_type = modelbox::jstring2string(env, j_device_type);
  return modelbox::JNINativeObject::NewHandle(
      j_this, std::make_shared<modelbox::FlowUnitInput>(name, device_type));
}

/*
 * Class:     com_modelbox_FlowUnitInput
 * Method:    FlowUnitInput_New
 * Signature: (Ljava/lang/String;J)J
 */
JNIEXPORT jlong JNICALL
Java_com_modelbox_FlowUnitInput_FlowUnitInput_1New__Ljava_lang_String_2J(
    JNIEnv *env, jobject j_this, jstring j_name, jlong j_device_flags) {
  auto name = modelbox::jstring2string(env, j_name);

  return modelbox::JNINativeObject::NewHandle(
      j_this, std::make_shared<modelbox::FlowUnitInput>(name, j_device_flags));
}

/*
 * Class:     com_modelbox_FlowUnitInput
 * Method:    FlowUnitInput_New
 * Signature: (Ljava/lang/String;Ljava/lang/String;J)J
 */
JNIEXPORT jlong JNICALL
Java_com_modelbox_FlowUnitInput_FlowUnitInput_1New__Ljava_lang_String_2Ljava_lang_String_2J(
    JNIEnv *env, jobject j_this, jstring j_name, jstring j_device_type,
    jlong j_device_flags) {
  auto name = modelbox::jstring2string(env, j_name);
  auto device_type = modelbox::jstring2string(env, j_device_type);
  return modelbox::JNINativeObject::NewHandle(
      j_this, std::make_shared<modelbox::FlowUnitInput>(name, device_type,
                                                        j_device_flags));
}