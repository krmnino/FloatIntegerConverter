TARGET=converter
CC=gcc
CCFLAGS = -Wall
HEADERS = converter.h 

$(TARGET): main.o
	$(CC) $(CCFLAGS) -o $@ main.o

main.o: main.c $(HEADERS)
	$(CC) $(CCFLAGS) -O -c main.c

clean:
	rm main.o $(TARGET)