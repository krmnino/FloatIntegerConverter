TARGET=converter
CC=gcc
CCFLAGS = -Wall
HEADERS = converter.h 

$(TARGET): converter.o
	$(CC) $(CCFLAGS) -o $@ converter.o

main.o: converter.c $(HEADERS)
	$(CC) $(CCFLAGS) -O -c converter.c

clean:
	rm converter.o $(TARGET)