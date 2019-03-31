#include <bits/stdc++.h>
using namespace std;


struct Interval {
	int start, end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
typedef Interval it;
typedef vector<Interval> vii;
bool icomapre(Interval a, Interval b){return a.end < b.end;}

class Solution {
public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
  	vector<Interval> res;
  	auto x = newInterval;
  	int ll = intervals.size();
  	if(ll==0){
  		res.push_back(x);
  		return res;
  	}
  	sort(intervals.begin(),intervals.end(),icomapre);
  	int i = 0;
  	for(; i<ll; i++) {
  		if(intervals[i].end >= x.start) break;
  		res.push_back(intervals[i]);
  	}
  	for(;i<ll;i++) {
  		if(x.end<intervals[i].start) break;
  		x.start = min(intervals[i].start,x.start);
  		x.end = max(intervals[i].end,x.end);
  	}
  	res.push_back(x);
  	for(;i<ll;i++) res.push_back(intervals[i]);
  	return res;   
  }
};

int main() {
	vii t = {it(1,2), it(3,5), it(6,7), it(8,10), it(12,16)};
	vii t1 = {it(1,3), it(6,9)};
	auto n = Interval(4,8);
	auto n1 = Interval(2,5);
	Solution sln;
	vii ans = sln.insert(t1,n1);
	for(it a:ans) cout << a.start << " " << a.end << endl;
	return 0;
}