LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm
LOCAL_CFLAGS := -O3 -DNDEBUG --all-warnings --extra-warnings

LOCAL_MODULE    := iovyroot
LOCAL_SRC_FILES := main.c getroot.c flex_array.c sid.c offsets.c

include $(BUILD_EXECUTABLE)
