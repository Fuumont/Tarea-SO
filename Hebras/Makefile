CC = g++
CFLAGS = -Wall -std=c++11 `pkg-config --cflags opencv4`
LDFLAGS = `pkg-config --libs opencv4`

NUM_THREADS ?= 4

all: hebras

hebras: hebras.cpp
	$(CC) $(CFLAGS) -o hebras hebras.cpp $(LDFLAGS)

.PHONY: clean

clean:
	rm -f hebras