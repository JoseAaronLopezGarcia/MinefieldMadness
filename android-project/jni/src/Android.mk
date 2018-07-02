LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

LOCAL_C_INCLUDES := $(LOCAL_PATH)/headers/

# Add your application source files here...
LOCAL_SRC_FILES := $(LOCAL_PATH)/SDL_android_main.c \
	$(LOCAL_PATH)/main.c \
	$(LOCAL_PATH)/c_src/cbcstd.c \
	$(LOCAL_PATH)/c_src/savedata.c \
	$(LOCAL_PATH)/c_src/difficulty.c \
	$(LOCAL_PATH)/c_src/map.c \
	$(LOCAL_PATH)/c_src/common.c \
	$(LOCAL_PATH)/c_src/image.c \
	$(LOCAL_PATH)/c_src/screen.c \
	$(LOCAL_PATH)/c_src/font.c \
	$(LOCAL_PATH)/c_src/sound.c \
	$(LOCAL_PATH)/c_src/floor.c \
	$(LOCAL_PATH)/c_src/keyboard.c \
	$(LOCAL_PATH)/c_src/mouse.c \
	$(LOCAL_PATH)/c_src/character.c \
	$(LOCAL_PATH)/c_src/pathfinder.c \
	$(LOCAL_PATH)/c_src/astar.c \
	$(LOCAL_PATH)/c_src/menu.c \
	$(LOCAL_PATH)/c_src/game.c \
	$(LOCAL_PATH)/c_src/missil.c \
	$(LOCAL_PATH)/c_src/grenade.c \
	$(LOCAL_PATH)/c_src/lawnmower.c \
	$(LOCAL_PATH)/c_src/teleporter.c \
	$(LOCAL_PATH)/c_src/minedetector.c \
	$(LOCAL_PATH)/c_src/flamethrower.c \
	$(LOCAL_PATH)/c_src/lifeup.c \
	$(LOCAL_PATH)/c_src/cow.c \
	$(LOCAL_PATH)/c_src/napalm.c \
	$(LOCAL_PATH)/c_src/magnet.c \
	$(LOCAL_PATH)/c_src/laser.c \
	$(LOCAL_PATH)/c_src/ads.c \
	$(LOCAL_PATH)/c_src/anim.c \
	$(LOCAL_PATH)/c_src/notification.c \
	$(LOCAL_PATH)/c_src/pause.c \
	$(LOCAL_PATH)/c_src/help.c \
	$(LOCAL_PATH)/c_src/timer.c \


LOCAL_LDLIBS := -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lSDL2 -lm -lz -landroid -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
