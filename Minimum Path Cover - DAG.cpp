
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>

using namespace std;

class node {
public:
	node() {}
	node(int _nodeId, bool dirty);
	int nodeId;
	bool dirty;
	void operator=(node rhs);
	bool operator==(node rhs);
};

class edge {
public:
	edge(node *_startNode, node *_endNode) : startNode(_startNode), endNode(_endNode) {}
	node *startNode, *endNode;
};



node::node(int _nodeId, bool _dirty) {
	nodeId = _nodeId;
	dirty = _dirty;
}

void node :: operator=(node rhs) {
	this->dirty = rhs.dirty;
	this->nodeId = rhs.nodeId;
}

bool node :: operator==(node rhs) {
	if (this->nodeId == rhs.nodeId) {
		return true;
	}
	return false;
}



class graph {
public:
	void print();
	void addEdge(node startNode, node endNode);
	void addNode(node n);
	void dfs(node s);
private:
	vector<edge> edges;
	vector<node> nodes;
};

void graph::addNode(node n) {
	// only add this node if it does not exist in the graph
	if (find(nodes.begin(), nodes.end(), n) == nodes.end()) {
		//print();
		cout << "Pushing :" << n.nodeId << endl;
		nodes.push_back(n);
	}
	print();
	cout << endl;
}

void graph::dfs(node s) {
	// Search node s and mark it as dirty


}
void graph::print() {
	cout << "print called\n";
	vector<edge>::iterator itr = edges.begin();
	while (itr != edges.end()) {
		cout << itr->startNode->nodeId << "(" << itr->startNode->dirty << ") --> ";
		cout << itr->endNode->nodeId << "(" << itr->endNode->dirty << ")" << endl;
		++itr;
	}

	cout << "Nodes are:\n";
	for (size_t i = 0; i < nodes.size(); ++i) {
		cout << nodes.at(i).nodeId << endl;
	}
}

void graph::addEdge(node startNode, node endNode) {
	vector<node>::iterator itrStartNode;
	itrStartNode = find(nodes.begin(), nodes.end(), startNode);
	vector<node>::iterator itrEndNode;
	itrEndNode = find(nodes.begin(), nodes.end(), endNode);
	edge e(&(*itrStartNode), &(*itrEndNode));
	edges.push_back(e);
}


void main(int argc, char *argv[]) {
	graph g;
	// Read the file here
	ifstream file;
	file.open("test.txt", ios::in);
	string line;
	while (getline(file, line)) {
		int startNodeId, endNodeId;
		istringstream is(line);
		is >> startNodeId >> endNodeId;
		node startNode(startNodeId, false);
		node endNode(endNodeId, false);
		g.addNode(startNode);
		g.addNode(endNode);
		g.addEdge(startNode, endNode);
	}
	file.close();
	g.print();
	_getch();
}
