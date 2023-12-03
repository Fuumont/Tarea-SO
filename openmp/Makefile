CXX = g++
CXXFLAGS = -std=c++11 -fopenmp
OPENCV = `pkg-config --cflags --libs opencv4`

all: mp

mp: mp.cpp
	$(CXX) $(CXXFLAGS) -o mp mp.cpp $(OPENCV)

clean:
	rm -f mp imagengris.jpg