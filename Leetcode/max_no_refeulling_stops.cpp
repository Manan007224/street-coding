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
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int st = stations.size();
    int last_stop = 0;
    int curr_max = startFuel;
    priority_queue<int> pq;
    int stops;
    for(stops = 0; ; stops++) {
    	if(curr_max >= target) break;
    	while(last_stop < st && stations[last_stop][0] <= curr_max){
    		pq.push(stations[last_stop][1]);
    		last_stop++;
    	}
    	if(pq.empty()) return -1;
    	curr_max += pq.top();
    	pq.pop();
    }
    return stops;
  }
};

int main() {
	vector<vector<int>> test = {{10,60}, {20,30}, {30,30}, {60,30}, {90,10}};
	vector<vector<int>> test1 = {{5,30}, {10,35}, {15,55}, {20,45}, {70,10}};
	vector<vector<int>> test2 = {{10,100}};
	Solution sln;
	cout << sln.minRefuelStops(100, 10, test) << endl; 
	return 0;
}