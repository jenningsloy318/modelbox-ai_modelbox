#
# Copyright 2022 The Modelbox Project Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.10)

set(UNIT_DEVICE "rockchip")
set(UNIT_NAME "local_camera")

project(modelbox-flowunit-${UNIT_DEVICE}-${UNIT_NAME})

file(GLOB_RECURSE UNIT_SOURCE *.cpp *.cc *.c)
group_source_test_files(MODELBOX_UNIT_SOURCE MODELBOX_UNIT_TEST_SOURCE "_test.c*" ${UNIT_SOURCE})

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${LIBMODELBOX_INCLUDE})
include_directories(${LIBMODELBOX_BASE_INCLUDE})
include_directories(${LIBMODELBOX_DEVICE_ROCKCHIP_INCLUDE})
include_directories(${ROCKCHIP_MPP_INCLUDE})
include_directories(${ROCKCHIP_RGA_INCLUDE})
include_directories(${NLOHMANN_INCLUDE_DIR})

set(MODELBOX_UNIT_SHARED libmodelbox-unit-${UNIT_DEVICE}-${UNIT_NAME}-shared)
set(MODELBOX_UNIT_SOURCE_INCLUDE ${CMAKE_CURRENT_LIST_DIR})

add_library(${MODELBOX_UNIT_SHARED} SHARED ${MODELBOX_UNIT_SOURCE})
set(LIBMODELBOX_FLOWUNIT_LOCALCAM_ROCKCHIP_SHARED ${MODELBOX_UNIT_SHARED})

set_target_properties(${MODELBOX_UNIT_SHARED} PROPERTIES
        SOVERSION ${MODELBOX_VERSION_MAJOR}
        VERSION ${MODELBOX_VERSION_MAJOR}.${MODELBOX_VERSION_MINOR}.${MODELBOX_VERSION_PATCH}
)

target_link_libraries(${MODELBOX_UNIT_SHARED} pthread)
target_link_libraries(${MODELBOX_UNIT_SHARED} rt)
target_link_libraries(${MODELBOX_UNIT_SHARED} dl)
target_link_libraries(${MODELBOX_UNIT_SHARED} ${LIBMODELBOX_DEVICE_ROCKCHIP_SHARED})
target_link_libraries(${MODELBOX_UNIT_SHARED} ${LIBMODELBOX_SHARED})

set_target_properties(${MODELBOX_UNIT_SHARED} PROPERTIES OUTPUT_NAME "modelbox-unit-${UNIT_DEVICE}-${UNIT_NAME}")

install(TARGETS ${MODELBOX_UNIT_SHARED}
        COMPONENT rockchip-device-flowunit
        RUNTIME DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
        OPTIONAL)
install(DIRECTORY ${HEADER}
        DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}
        COMPONENT rockchip-device-flowunit-devel)

set(LIBMODELBOX_FLOWUNIT_LOCALCAM_ROCKCHIP_SHARED ${MODELBOX_UNIT_SHARED} CACHE INTERNAL "")
set(LIBMODELBOX_FLOWUNIT_LOCALCAM_ROCKCHIP_INCLUDE ${MODELBOX_UNIT_SOURCE_INCLUDE} CACHE INTERNAL "")
set(LIBMODELBOX_FLOWUNIT_LOCALCAM_ROCKCHIP_SOURCES ${MODELBOX_UNIT_SOURCE} CACHE INTERNAL "")
set(LIBMODELBOX_FLOWUNIT_LOCALCAM_ROCKCHIP_SO_PATH ${CMAKE_CURRENT_BINARY_DIR}/libmodelbox-unit-${UNIT_DEVICE}-${UNIT_NAME}.so CACHE INTERNAL "")

# driver test
list(APPEND DRIVER_UNIT_TEST_SOURCE ${MODELBOX_UNIT_TEST_SOURCE})
list(APPEND DRIVER_UNIT_TEST_TARGET ${MODELBOX_UNIT_SHARED})
list(APPEND DRIVER_UNIT_TEST_LINK_LIBRARIES ${RKMPP_MPP_LIBRARY})
set(DRIVER_UNIT_TEST_SOURCE ${DRIVER_UNIT_TEST_SOURCE} CACHE INTERNAL "")
set(DRIVER_UNIT_TEST_TARGET ${DRIVER_UNIT_TEST_TARGET} CACHE INTERNAL "")
set(TEST_INCLUDE ${TEST_INCLUDE} CACHE INTERNAL "")
set(DRIVER_UNIT_TEST_LINK_LIBRARIES ${DRIVER_UNIT_TEST_LINK_LIBRARIES} CACHE INTERNAL "")
