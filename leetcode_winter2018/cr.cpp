#include <bits/stdc++.h>
using namespace std;

vector<int> mystery(vector<string> letter) {
	vector<int> output;
	for(auto s:letter){
		int i{0}, ans{0};
		int j=s.length()-1;
	    while(i<j)
	    	ans+=abs(s[i++]-s[j--]);
	    output.push_back(ans);
	}
    return output;
}

int main(){
	int T; cin>>T;
	vector<string> input;
	while((T--)>0){
		string str; cin>>str;
		input.push_back(str);
	}
	vector<int> ans = mystery(input);
	for(auto x:ans) cout<<x<<endl;
	return 0;
}