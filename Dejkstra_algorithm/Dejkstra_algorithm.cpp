#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <exception>
using namespace std;

struct Node {
	string node_name;
	map<Node, int> neighbors_and_weights;
	map<int, Node> weight_sort;
};

class Graph {
	set<Node> full_graph;
public:
	Graph() {}
	Graph(const Node&);
	Graph(const Graph&);
	int GetEdgeWeight(Node&, const Node&) const;
	//Greedy algorithm
	void Print_greedy_way(Node start, const Node& end) const;

};

Graph::Graph(const Node& new_Node) {
	full_graph.insert(new_Node);
}

Graph::Graph(const Graph& new_Graph) {
	*this = new_Graph;
}

bool operator<(const Node& lhs, const Node& rhs) {
	if (lhs.node_name < rhs.node_name)
		return true;
	else return false;
}

bool operator!=(const Node& lhs, const Node& rhs) {
	if (lhs.node_name != rhs.node_name)
		return true;
	else return false;
}

bool operator==(const Node& lhs, const Node& rhs) {
	if (lhs.node_name == rhs.node_name)
		return true;
	else return false;
}

int Graph::GetEdgeWeight(Node& from, const Node& to) const{
	int result;
	if (from.neighbors_and_weights.count(to) != 0)
		return from.neighbors_and_weights[to];
	else 
		throw logic_error("No way from " + from.node_name + " to " + to.node_name);

}

void Graph::Print_greedy_way(Node start, const Node& end) const {
	vector<string> final_way;
	do {
		final_way.push_back(start.node_name);
		auto i = start.weight_sort.begin();
		start = i->second;
	} while (start != end);
	

}

int main()
{
	try {


	}
	catch (const logic_error& er) {
			cout << er.what() << endl;

			return 0;
}

