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
  bool canJump(vector<int>& nums) {
    int n = nums.size()-1;
    if(n+1 <= 1) return 1;
    vector<int> can_jump(n+1, 0);
    can_jump[n] = 1;
    for(int i=n-1; i>=0; i--) {
    	for(int j=nums[i]; j>0; j--) {
    		if(i+j <= n) {
    			if(can_jump[i+j]) {
    				can_jump[i] = 1;
    				break;
    			}
    		}
    	}
    }
    return can_jump[0]; 
  }
};

int main() {
	vector<int> arr = {2,3,1,1,4};
	vector<int> arr1 = {3,2,1,0,4};
	Solution sln;
	cout << sln.canJump(arr) << endl;
	cout << sln.canJump(arr1) << endl;
	return 0;
}