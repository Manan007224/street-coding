#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int scheduleCourse(vector<vector<int>>& courses) {
  	sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b) {
  		return a[1] < b[1];
  	});
  	int currentTotalTime = 0;
  	priority_queue<int> pq;
  	for(int i=0; i<courses.size(); i++) {
  		pq.push(courses[i][0]);
  		currentTotalTime += courses[i][0];
  		if(currentTotalTime > courses[i][1]) {
  			// remove the course with the biggest duration
  			int tp = pq.top();
  			pq.pop();
  			currentTotalTime -= tp;
  		}
  	}
  	return pq.size();    
  }
};

int main() {
	Solution sln;
	vector<vector<int>> arr = {{100,200},{200,1300},{1000,1250},{2000,3200}};
	int a = sln.scheduleCourse(arr);
	cout << a << endl;
	return 0;
}