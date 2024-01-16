#include "graph.h"
Graph::Graph(const char* directory_file) {
	std::ifstream in_file;
	in_file.open(directory_file);
	if (!directory_file) {
		std::cerr << "Error opening file" << std::endl;
		exit(1);
	}
	std::string line, size_str = "";
	getline(in_file, line);
	for (uint32_t i = 0; i < line.size(); i++) {
		if (!std::isdigit(line[i])) 
			break;
		size_str += line[i];
	}
	setSize(std::atoi(size_str.c_str()));
	if (getSize() > 26) { //could add additional error checking for duplicate labels using an O(1) hash table here or in above input loop;
		std::cerr << "Only 26 vertices currently supported." << std::endl;
		exit(1);
	}

	std::list<char> tempList;
	//initialize sizes
	for (uint32_t i = line.size() - getSize(); i < line.size(); i++) {
		vertex_labels.push_back(line[i]);
		adjacency_list.push_back(tempList);
		visited.push_back(false);
	}
	int current_vertex = 0;
	while (getline(in_file, line)){
		for (uint32_t i = 0; i < getSize()+1; i++) {
			if (i > 0) {	
				if (line[i] - '0') { // or (if line[i] == '1')
					adjacency_list[current_vertex].push_back(vertex_labels[i-1]); //-1 accounting for row label column
				}
			}
		}
		current_vertex++;
	}
	in_file.close();
}
void Graph::print() {
	std::cout << "Graph has " << getSize() << " vertices." << std::endl;
	for (std::vector<std::list<char>>::iterator it = adjacency_list.begin(); it != adjacency_list.end(); it++) {
		if (!(*it).empty()) {
			std::cout << vertex_labels[it - adjacency_list.begin()] << ": ";
			for (char &j : (*it)) {
				std::cout << j;
				&j != &it->back() ? std::cout << ", " : std::cout << '.'; //print comma if not last element
			}
		}
		std::cout << std::endl;
	}
}
void Graph::completeWalk() {
	std::cout << "Starting Depth-First Search" << std::endl;
	for (uint32_t i = 0; i < getSize(); i++) {
		if (!visited[i]) {
			std::cout << vertex_labels[i] << ' ';
			edges.push_back(vertex_labels[i]);
			depthFirstSearch(i);
		}
	}		
	std::cout << std::endl << "Ending Depth-First Search" << std::endl;
	std::fill(visited.begin(), visited.end(), false);
}
void Graph::depthFirstSearch(uint32_t label_pos) {
	visited[label_pos] = true;
	for (std::list<char>::iterator it = adjacency_list[label_pos].begin(); it != adjacency_list[label_pos].end(); it++) {
		if (!visited[(*it-64)-1]) { //get alphabet position based on ASCII value then -1 for 0 based array. could also use int based adjacency matrix
			std::cout << vertex_labels[(*it-64)-1] << ' ';
			edges.push_back(vertex_labels[(*it-64)-1]);
			depthFirstSearch((*it-64)-1);
		}
	}
}
uint32_t Graph::getSize() const {
	return size;
}
void Graph::setSize(uint32_t new_sz) {
	size = new_sz;
}
Graph::~Graph() {}
