#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define INF 0x3f3f3f3f;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int L = nums.size();
        if(L==0) return;
        int dec, inc, x{L-1}, y{-1};
        while(x>0 && nums[x]<=nums[x-1]){
        	x--;
        }
        cout << x-1 << endl;
        if(--x >= 0){
        	for(int i=L-1; i>=0; i--) {
	        	if(nums[i] > nums[x]) {
	        		y = i;
	        		swap(nums[x], nums[y]);
	        		break;
	        	}
       	 	}
        }
        
        reverse(nums.begin()+x+1, nums.end());
    }
};

int main() {
	vi T = {1,3,8,6,4,2};
	vi T1 = {5,1,1};
	vi T2 = {1,5,8,4,7,6,5,3,1};
	Solution sln;
	//reverse(T.begin()+1, T.begin()+2);
	sln.nextPermutation(T1);
	for(auto t: T1) cout<<t<<" ";
	cout<<endl;
	return 0;
}