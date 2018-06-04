#include <bits/stdc++.h>
using namespace std;


class Solution {
	public:
	    int lengthOfLongestSubstring(string s) {
	    	int ans = 0;
	    	unordered_set<char> st;
	    	int i=0; int j=0;
	    	while(i<s.length() && j<s.length()){
	    		char fn = s[j];
	    		if(st.find(fn)==st.end()){
	    			st.insert(fn);
	    			j++;
	    			ans = max(ans,j-i);
	    		}
	    		else {
	    			st.erase(s[i]);
	    			i++;
	    		}
	    	}
	    return ans;
	    }
};
