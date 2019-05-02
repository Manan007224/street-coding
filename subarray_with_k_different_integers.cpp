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
  // int subarraysWithKDistinct(vector<int>& A, int K) {
  //   int n = A.size();
  //   int count = 0;
  //   for(int i=0; i<n; i++) {
  //   	unordered_set<int> dict;
  //   	int distinct = 0;
  //   	for(int j=i; j<n; j++) {
  //   		auto at_j = dict.find(A[j]);
  //   		if(at_j == dict.end()){
  //   			distinct ++;
  //   		}
  //   		dict.insert(A[j]);
  //   		if(distinct == K){
  //   			count++;
  //   		}
  //   	}
  //   }
  //   return count;
  // }

   int subarraysWithKDistinct(vector<int>& A, int K) {
   		
   }

};

int main() {
	vector<int> a = {1,2,1,2,3};
	Solution sln;
	cout << sln.subarraysWithKDistinct(a, 2) << endl;
	return 0;
}