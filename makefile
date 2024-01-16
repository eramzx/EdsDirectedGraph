# ed ramos - directed graph make
CXX 	 = g++
CXXFLAGS = -std=c++11 -Wall -Werror

graph: main.o graph.o
	$(CXX) $(CXXFLAGS) -o graph $^

main.o: main.cpp

graph.o: graph.cpp graph.h

clean:
	rm -f graph *.o
