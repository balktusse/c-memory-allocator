CC = gcc
CFLAGS = -Wall -Wextra -g

HEADERS = gahook.h
OBJECTS = gahook.o test.o
TARGET = test

.PHONY: default clean

default: $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)