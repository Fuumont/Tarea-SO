CXX = g++
CXXFLAGS = -std=c++11
OPENCV = `pkg-config --cflags --libs opencv4`

all: gris

gris: gris.cpp
	$(CXX) $(CXXFLAGS) -o gris gris.cpp $(OPENCV)

clean:
	rm -f gris 