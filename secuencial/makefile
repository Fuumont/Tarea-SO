CXX = g++
CXXFLAGS = -std=c++11
OPENCV = `pkg-config --cflags --libs opencv`

all: gris

gris: gris.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(OPENCV)

clean:
	rm -f gris imagengris.jpg