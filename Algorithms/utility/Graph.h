#include <bits/stdc++.h>
#ifndef GRAPH_H
#define GRAPH_H

using namespace std;

class Graph{
public:
	int v;
	list<int> *neighbours;
	Graph(int num);
	void edge(int i, int j);
};

#endif