#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
  		unordered_map<string,int> tp1;
  		unordered_map<string,int> tp2;
  		int mn = -1;
  		vector<string> ans;
  		for(int k=0; k<list1.size(); k++)
  			tp1[list1[k]] = k;
  		for(int k=0; k<list2.size(); k++)
  			tp2[list2[k]] = k;
  		for(auto it: tp1){
  			auto tp3 = tp2.find(it.first);
  			if(tp3!=tp2.end()){
  				int j = it.second+tp3->second;
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
  		return ans;
    }
};

int main(){
	vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
	Solution sln;
	vector<string> ans;
	ans = sln.findRestaurant(list1,list2);
	for(auto a: ans)
		cout<<a<<endl;
	return 0;
}