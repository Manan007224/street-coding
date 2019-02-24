#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unordered_map<int,vi> ump;
typedef unordered_set<int> ust;

class Solution {
private:
	ump row,col;
	ust rs,cs;
public:
	void dfs_r(int x){
    	rs.insert(x);
    	vi adj = row[x];
    	for(auto& a:adj){ if(cs.find(a)==cs.end()) dfs_c(a); }
    }

    void dfs_c(int x){
    	cs.insert(x);	
    	vi adj = col[x];
    	for(auto& a:adj){ if(rs.find(a)==rs.end()) dfs_r(a); }
    }

    int removeStones(vector<vector<int>>& stones) {
    	int ll=stones.size(), cmp{0};
    	if(ll==0) return 0;
        for(auto& s:stones){
        	int x{s[0]}, y{s[1]};
        	auto ix=row.find(x), iy=col.find(y);
        	if(ix==row.end()) {vi tx; row.insert({x,tx});}
        	if(iy==col.end()) {vi ty; col.insert({y,ty});}
        	row[x].push_back(y);
        	col[y].push_back(x);
        }
        for(auto& s:stones){
        	int x{s[0]}, y{s[1]};
        	if(rs.find(x)==rs.end()){
        		cmp++;
        		dfs_r(x);
        		dfs_c(y);
        	}
        }
        return ll-cmp;
    }
};

int main(){
	Solution sln;
	vvi stones={{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
	vvi stones1={{0,0},{0,2},{1,1},{2,0},{2,2}};
	cout<<sln.removeStones(stones)<<endl;
	return 0;
}