#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int main() {
	int t; cin>>t;
	while(t-- > 0) {
		int n,k; cin>>n>>k;
		priority_queue< pair<int,int> > pq;
		pair<int, int> start = make_pair(1,n);
		int min = 0; int max = 0;
		pq.push(start);
		for(int i=0;i<k;i++) {
			int left = pq.top().first;
			int right = pq.top().second;
			int middle = (left+right)/2;
			pq.pop();
			pair<int, int> p1;
			p1 = make_pair(left, middle-1);
			if(p1.first < p1.second) pq.push(p1);
			pair<int, int> p2;
			p2 = make_pair(middle+1, right); 
			if(p2.first < p2.second) pq.push(p2); 
			min = middle - left; 
			max = right - middle;
		}
		cout << "Case# " << max << " " << min << endl;
	}
	return 0;
}

