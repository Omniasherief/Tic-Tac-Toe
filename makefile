main.obj: main.c functions.h STD_TYPES.h
    gcc -c main.c -o main.obj

game.obj: game.c functions.h STD_TYPES.h
    gcc -c game.c -o game.obj

all: game.obj main.obj
    gcc game.obj main.obj -o out.exe
	