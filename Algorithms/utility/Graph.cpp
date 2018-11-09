#include <bits/stdc++.h>
#include <iostream>
#include "Graph.h"

using namespace std;

Graph::Graph(int num){
	v=num;
	neighbours=new list<int>[num];
}

void Graph::edge(int i, int j){
	neighbours[i].push_back(j);
}