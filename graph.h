#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <list>
#include <fstream>
#include <iostream>

class Graph {
	private:
		uint32_t size;
		std::vector<char> vertex_labels;
		std::vector<std::list<char>> adjacency_list;

		std::vector<bool> visited;
		std::vector<char> edges;
		
	public:
		Graph(const char*);
		~Graph();
		void print();
		void setSize(uint32_t);
		uint32_t getSize() const;
		void completeWalk();
		void depthFirstSearch(uint32_t);
};

#endif
