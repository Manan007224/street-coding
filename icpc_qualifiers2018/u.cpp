

#include <bits/stdc++.h>
using namespace std;


int main(){
	int n; cin>>n;
	vector<int> v {2,3,5};
	for(int i=7;i<=n;i+=2){
		int val = sqrt(i) + 1;
		bool worked=true;
		for(int j=1;j<v.size();j++){
			if(i%v[j]==0){
				worked=false;
				break;
			}
			if(v[j]>val) break;
		}
		if(worked) v.push_back(i);
	}
	
	int c=0;
	while(n>=4){
		//cout<<"\nn: "<<n<<": ";
		auto it = upper_bound(v.begin(), v.end(), n);
		int d = distance(v.begin(), it);
		//cout<<"\tdistance: "<<d<<endl;
		if(d<v.size()-1) d++;
		//cout<<"\tanother: "<<d<<endl;
		for(int i=d;i>=0;i--){
			int b=v[i];
				//cout<<"\t"<<i;
			if(b<n){
				//cout<<"\t"<<b;
				int a=n-b;
				if(binary_search(v.begin(), v.end(), a)){
					n = b-a;
					c++;
					break;
				}
			}
		}
	}
	cout<<c<<endl;
}

