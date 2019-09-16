#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int lo = 0, hi = people.size() - 1;
    int boats = 0;
    while(lo <= hi) {
    	boats++;
    	if(people[lo] + people[hi] <= limit) {
    		lo++;
    		hi--;
    	}
    	else {
    		hi--;
    	}
    }
    return boats;
  }
};

int main() {
	vector<int> p = {1, 2};
	Solution sln;
	cout << sln.numRescueBoats(p, 3) << endl;
	return 0;
}