#include "graph.h"
int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "No input file name provided" << std::endl;
		return 1;
	}
	Graph g(argv[1]);
	g.print();
	g.completeWalk();
	return 0;
}
