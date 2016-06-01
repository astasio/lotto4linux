all: main.c
	gcc -ansi -std=c99 -pedantic main.c -o lotto4linux -O3 -ggdb -Wall -fomit-frame-pointer -lcurl -lsqlite3 `pkg-config --cflags --libs gtk+-2.0`  
