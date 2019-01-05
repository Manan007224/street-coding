#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef vector<string> vs;	
typedef vector<unordered_map<string,int>> VMP;

vs split(string input){
	vs v;  stringstream ts(input); string tk;
	while(getline(ts,tk,' ')) v.push_back(tk);
	return v;
}

void textQueries(vector<string> sentences, vector<string> queries){
	int ll = sentences.size(), lq = queries.size();
	VMP dict(ll);
	vector<vector<int>> res(lq);
	for(int i=0; i<ll; i++){
		vs v = split(sentences[i]);
		for(int j=0; j<v.size(); j++){
			if(dict[i].find(v[j])==dict[i].end()) dict[i].insert({v[j],1});
			else dict[i][v[j]]++;
		}
	}
	for(int i=0; i<lq; i++){
		vs query = split(queries[i]);
		for(int d=0; d<ll; d++){
			int mc {INF};
			for(auto& q:query){
				if(dict[d].find(q)==dict[d].end()){mc=min(mc,0);}
				else mc=min(mc,dict[d][q]);
			}
			for(int x=0;x<mc;x++) res[i].push_back(d);
		}
	}
	for(int i=0; i<lq; i++){
		for(int j=0; j<res[i].size(); j++) cout<<res[i][j]<<" ";
		cout<<endl;
	}
}	

int main(){
	vs t={"bob and alice like to text to each other",
			"bob does not like to ski but does not like to fall",
			"alice likes to ski"};
	vs q={"bob alice","alice","likes"};
	vs t1 = {"jim likes marry", "kate likes tom", "tom does not like jim"};
	vs q1 = {"jim tom", "likes"};
	textQueries(t1,q1);
	return 0;
}