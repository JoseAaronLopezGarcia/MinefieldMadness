CC = gcc
TARGET = MinefieldMadness
INC_DIR = -Iheaders
LD_FLAGS = -lpthread -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm
SRC = main.c \
	c_src/cbcstd.c \
	c_src/ads.c \
	c_src/anim.c \
	c_src/astar.c \
	c_src/character.c \
	c_src/common.c \
	c_src/cow.c \
	c_src/difficulty.c \
	c_src/flamethrower.c \
	c_src/floor.c \
	c_src/font.c \
	c_src/game.c \
	c_src/grenade.c \
	c_src/help.c \
	c_src/image.c \
	c_src/keyboard.c \
	c_src/laser.c \
	c_src/lawnmower.c \
	c_src/lifeup.c \
	c_src/magnet.c \
	c_src/map.c \
	c_src/menu.c \
	c_src/minedetector.c \
	c_src/missil.c \
	c_src/mouse.c \
	c_src/napalm.c \
	c_src/notification.c \
	c_src/pathfinder.c \
	c_src/pause.c \
	c_src/savedata.c \
	c_src/screen.c \
	c_src/sound.c \
	c_src/teleporter.c \
	c_src/timer.c \

all:
	$(CC) $(INC_DIR) -o $(TARGET) $(SRC) $(LD_FLAGS)

m32:
	$(CC) -m32 $(INC_DIR) -L/usr/lib/i386-linux-gnu -o $(TARGET)_x86 $(SRC) $(LD_FLAGS)

clean:
	rm -f $(TARGET)

