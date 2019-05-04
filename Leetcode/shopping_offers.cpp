#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vi_32;
typedef vector<vi_32> vii_32;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
  int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    return go(price, special, needs);  
  }

  int go(vi &price, vii &special, vi &needs) {
  	int n = price.size(), sum = 0;
  	for(int i=0; i<n; i++) sum += (price[i] * needs[i]);
  	for(auto offer: special) {
  		int of = offer.size(), j;
      bool works = 1;
  		for(j=0; j<n; j++) {
  			if(needs[j] - offer[j] < 0) {
          works = 0;
          break;
        }
  			needs[j] -= offer[j];
  		}	
  		if(works) {
  			sum = min(sum, offer[of-1] + go(price, special, needs));
  		}
  		for(int x=0; x<j; x++) {
  			needs[x] += offer[x];
  		}	
  	}
  	return sum;
  }
};

int main(){
	vi a = {2,5}, b = {3,2};
	vii c = {{3,0,5}, {1,2,10}};
	vi a1 = {2,3,4}, b1 = {1,2,1};
	vii c1 = {{1,1,0,4}, {2,2,1,9}};
	Solution sln;
	cout << sln.shoppingOffers(a, c, b) << endl;
	return 0;
}