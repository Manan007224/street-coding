#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
  	vector<int> res(k);
  	if(arr.size() == 0) return res;
    if(x <= arr[0]) {
    	copy(arr.begin(), arr.begin()+k, res.begin());
    	return res;
    }
    if(x >= arr[arr.size()-1]) {
    	copy(arr.begin()+arr.size()-k, arr.end(), res.begin());
    	return res;
    }
    int lo = 0, hi = arr.size()-1, idx = -1;
    while(lo < hi) {
    	int mid = (lo + hi)/2;
    	if(arr[mid] == x) {
    		idx = mid;
    		break;
    	}
    	arr[mid] > x ? hi = mid-1 : lo = mid+1;
    }
    if(idx == -1) idx = lo;
    lo = (idx-k+1 > 0) ? idx-k+1 : 0;
    hi = (idx+k-1 > 0) ? idx+k-1 : arr.size()-1;
    while(hi-lo > k-1) {
    	if(lo < 0 || (x - arr[lo] <= arr[hi] - x))
    		hi--;
    	else if(hi > arr.size()-1 || (x - arr[lo] > arr[hi] - x))
    		lo++;
    }
    copy(arr.begin()+lo, arr.begin()+hi+1, res.begin());
    return res;
  }
};

int main() {
	vector<int> t = {3,4,7,8,13,17,18,19,21,25};
	Solution sln;
	vector<int> res = sln.findClosestElements(t, 5, 1);
	for(auto r: res) cout << r << " " ;
	cout << endl;
	return 0;
}