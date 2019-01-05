#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unordered_map<int,int> map;
typedef unordered_map<string,map> UMP;
#define INF 0x3f3f3f3f

vs split(string input){
	vs v;  stringstream ts(input); string tk;
	while(getline(ts,tk,' ')) v.push_back(tk);
	return v;
}

map customize(int ll){
	map output;
	for(int i=0;i<ll;i++) output.insert({i,0});
	return output;
}

void textQueries(vs sentences, vs queries){
	int ll = sentences.size(), lq = queries.size();
	UMP dict;
	vvi res(lq);
	for(int i=0; i<ll; i++){
		vs tp = split(sentences[i]);
		for(auto& t:tp){
			if(dict.find(t)==dict.end()) dict.insert({t,customize(ll)});
			dict[t][i]++;
		}
	}
	for(int i=0; i<lq; i++){
		vs qr = split(queries[i]);
		if(qr.size()==1){
			for(auto it=dict[qr[0]].begin(); it!=dict[qr[0]].end(); it++){
				int cf {it.first}, cs{it.second};
				for(int x=0;x<cs;x++) res[i].push_back(cf);
			}
		}
		else{
			vi phr(ll,INF);
			ump temp;
			for(auto q:query){
				for(auto it=dict[q].begin();it!=dict[q].end();it++){
					temp[it.first]=min(temp[it.first],)
				}
			}
			for(int x=0; x<ll; x++){
				for(auto q:qr) phr[x]=min(phr[x],dict[q][x]);
			}
			for(int i=0;i<ll;i++){
				for(int j=0;j<phr[i];j++) res[i].push_back(i);
			}
		}
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