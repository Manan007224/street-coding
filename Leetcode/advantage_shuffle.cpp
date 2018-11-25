#include <bits/stdc++.h>
typedef vector<int> lst;
typedef unordered_map<int,int> mp;

class Solution {
public:
    lst advantageCount(lst& A, lst& B) {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        mp cc;
        lst df, ans;
        int i=0;
        for(auto x:A){
        	if(B[i]<x) cc[B[i++]]=x;
        	else df.push_back(x);
        }
        for(auto x:B){
        	if(cc.find(x)!=cc.end) ans.push_back(x);
        	else{
        		ans.push_back(df.back());
        		df.pop_back();
        	}
        }
    }
};