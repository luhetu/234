OB=main.o perimeter.o visualiser.o
CC=gcc
CFLAGS+=-c -Wall -g
all:
	$(CC) lantong.c main.c visualiser.c -o lantong 
main:$(OB)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@

test: tests/test.c
	$(CC) lantong.c tests/test.c -o test

clean:
	$(RM) *.o .exe main -r

