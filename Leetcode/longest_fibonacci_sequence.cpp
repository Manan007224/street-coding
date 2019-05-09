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
  int lenLongestFibSubseq(vector<int>& A) {
    int n = A.size(), res = 0;
    if(n==0) return 0;
    // vector<int> dp(n, 1);
    unordered_set<int> st(A.cbegin(), A.cend());
    // for(int i=0; i<n; i++) mp[A[i]] = i;
   	for(int i=0; i<n; i++) {
   		for(int j=i+1; j<n; j++) {
   			int a = A[i], b = A[j], c = a+b;
   			int curr = 2;
   			while(st.find(c)!=st.end()) {
   				b = c;
   				a = b-a;
   				c = a+b;
   				curr++;
   			}
   			res = max(res, curr);
   		}
   	}
   	return res > 2 ? res : 0;  
  }
};

int main() {
	vector<int> arr = {1,3,7,11,12,14,18};
	vector<int> arr1 = {1,2,3,4,5,6,7,8};
	vector<int> arr2 = {1,2,3,5,8};
	Solution sln;
	cout << sln.lenLongestFibSubseq(arr2) << endl;
	return 0;
}