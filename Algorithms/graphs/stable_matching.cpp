#include <bits/stdc++.h>
using namespace std;
typedef vector<int> lst;
typedef vector<lst> llst;

int main(){
	lst wife(3,-1);
	lst husband(3,-1);
	queue<int> q;
	q.push(1); 
	q.push(0); 
	q.push(2);
	llst men = {{0,1,2},{1,0,2},{0,1,2}};
	llst women = {{1,0,2},{0,1,2},{0,1,2}};
	llst proposed(3,lst(3,-1));
	lst count(3,0);
	llst women_pref(3,lst(3));
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			women_pref[i][women[i][j]]=j;
	}
	while(!q.empty()){
		int m=q.front();
		if(count[m]>3){
			q.pop();
			continue;
		}
		int st=0;
		int w=men[m][st];
		while(true){
			if(proposed[m][w]==-1)
				break;
			st++;
			w=men[m][st];
		}
		q.pop();
		count[m]++;
		proposed[m][w]=1;
		if(wife[w]==-1){
			wife[w]=m;
			husband[m]=w;
		}
		else if(women_pref[w][m]<women_pref[w][wife[w]]){
			husband[wife[w]]=-1;
			q.push(wife[w]);
			wife[w]=m;
			husband[m]=w;
		}
		else{
			q.push(m);
			continue;
		}
	}
	for(int k=0;k<3;k++)
		cout<<k<<"<-->"<<husband[k]<<endl;

	return 0;
}