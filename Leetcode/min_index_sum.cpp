#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
  		unordered_map<string,int> tp1;
  		unordered_map<string,int> tp2;
  		int mn = -1;
  		vector<string> ans;
  		for(int k=0; k<list1.length(); k++)
  			tp1[list1[k]] = k;

  		for(int k=0; k<list2.length(); k++)
  			tp2[list2[k]] = k;

  		for(auto it: tp1){
  			auto tp3 = tp2.find(it.first);
  			if(tp3!=tp2.end()){
  				int j = it.second+tp3.second;
  				if(mn==-1){
  					mn=j;
  					ans.push_back(it.first);
  				}
  				else{
  					if(mn>j){
  						ans.clear();
  						mn=j;
  						ans.push_back(it.first);
  					}
  					else if(mn==j) ans.push_back(it.first);
  					else continue;
  				}
  			}

  		}
    }
};

int main(){
	return 0;
}