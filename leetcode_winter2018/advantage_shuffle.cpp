#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pt;
bool icomapre(pt& a, pt&b){return a.first < b.first;}

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    	int ll=A.size();
        sort(A.begin(),A.end());
        vector<pt> b;
        for(int i=0;i<ll;i++) b.push_back({B[i],i});
        sort(b.begin(),b.end(),icomapre);
    	vector<int> res(ll,-1), tr;
    	int k=0;
    	for(int i=0;i<ll;i++){
    		if(A[i]>b[k].first){
    			res[b[k].second]=A[i];
    			k++;
    		}
    		else tr.push_back(A[i]);
    	}
    	int j=0;
    	for(int i=0;i<ll;i++){
    		if(res[i]==-1){
    			res[i]=tr[j++];
    		}
    	}
    	return res;
    }
};

int main(){
	Solution sln;
	vector<int> t1={8,12,24,32};
	vector<int> t2={11,13,25,32};
	vector<int> ans=sln.advantageCount(t1,t2);
	for(auto a:ans) cout<<a<<" ";
	cout<<endl; 
	return 0;
}