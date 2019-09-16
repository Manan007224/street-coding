#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1,-1,0,0}, dy = {0,0,-1,1};
#define INF 0x3f3f3f3f 

class Solution {
public:
  void wallsAndGates(vector<vector<int>>& rooms) {
  	queue<pair<int,int>> q;
  	int x=rooms.size(), y=rooms[0].size();
  	for(int i=0; i<x; i++) {
  		for(int j=0; j<y; j++) {
  			if(rooms[i][j] == 0) q.push({i,j});
  		}
  	}   
  	while(!q.empty()) {
  		int k = q.front().first, v = q.front().second;
  		q.pop();
  		for(int i=0; i<4; i++) {
  			int xx=dx[i]+k, yy=dy[i]+v;
  			if(xx>=0 && xx<x && yy>=0 && yy<y && rooms[xx][yy]!=0 && rooms[xx][yy]!=-1) {
  				if(rooms[xx][yy]>rooms[k][v]+1) {
  					q.push({xx,yy});
  					rooms[xx][yy]=rooms[k][v]+1;
  				}
  			}
  		}
  	}
  }
};

int main() {
	vector<vector<int>> t = {{INF,-1,0,INF},{INF,INF,INF,-1},{INF,-1,INF,-1},{0,-1,INF,INF}};
	Solution sln;
	sln.wallsAndGates(t);
	for(auto rr: t) {
		for(auto r: rr) cout << r << "  ";
		cout << endl;
	}
	return 0;
}