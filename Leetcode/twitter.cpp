#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef unordered_map<string,vector<int>> VMP;
vi find_text(VMP& dict, string query);

vs split(string input){
	vector<string> v;  stringstream ts(input); string tk;
	while(getline(ts,tk,' ')) v.push_back(tk);
	return v;
}

void textQueries(vector<string> sentences, vector<string> queries) {
	VMP dict;
	vector<vi> res;
	for(int i=0; i<sentences.size(); i++){
		vs tp = split(sentences[i]);
		for(auto t:tp){
			if(dict.find(t)==dict.end()) {vi now = {i}; dict.insert({t,now});}
			else dict[t].push_back(i); 
		}
	}
	for(auto q:queries) res.push_back(find_text(dict,q));
	for(auto rr:res){
		if(rr.size()==0) cout<<"-1"<<endl;
		else{
			for(auto r:rr) cout<<r<<" ";
			cout<<endl;
		}
	}
}

vi find_text(VMP& dict, string query){
	vs temp = split(query);
	int sz = temp.size();
	vi ans;
	vi curr_ptr(sz,0);
	if(sz == 1) return dict[temp[0]]; 
	while(1){
		if(dict[temp[0]].size() == 0 || dict[temp[0]].size() <= curr_ptr[0]) return ans;
		int mn = dict[temp[0]][curr_ptr[0]];
		int mn_idx = 0;
		bool same = 1;
		for(int x=1; x<sz; x++){
			if(dict[temp[x]].size()==0 || dict[temp[x]].size() <= curr_ptr[x]) return ans;
			if(dict[temp[x-1]][curr_ptr[x-1]] != dict[temp[x]][curr_ptr[x]] && same) same=0;
			if(dict[temp[x]][curr_ptr[x]] < mn) {
				mn = dict[temp[x]][curr_ptr[x]];
				mn_idx = x;
			}
		}
		if(!same)
			curr_ptr[mn_idx]+=1;
		else{
			ans.push_back(dict[temp[0]][curr_ptr[0]]);
			for(int k=0;k<sz;k++) curr_ptr[k]++;
		}
	}
	return ans;
}

int main(){
	vs t={"bob and alice like to text to each other",
			"bob does not like to ski but does not like to fall",
			"alice likes to ski"};
	vs q={"bob and alice","alice","like"};
	vs t1 = {"jim likes marry", "kate likes tom", "tom does not like jim"};
	vs t2 = {"how it was done", "are you how", "it goes to", "goes done are it"};
	vs q3={"done it", "done", "it"};
	textQueries(t2,q3);
	return 0;
}