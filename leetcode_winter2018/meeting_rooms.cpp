#include <bits/stdc++.h>
using namespace std;

struct Interval{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool icomapre(Interval &a, Interval &b){
	return a.end < b.end;
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
  		sort(intervals.begin(), intervals.end(), icomapre);
  		if(intervals.size()==0) return true;
  		int ss=intervals[0].end;
  		for(int x=1; x<intervals.size(); x++){
  			int ff=intervals[x].start;
  			if(ff<ss) return false;
  			ss=intervals[x].end;
  		}
  		return true;    
    }
};

int main(){
	auto a1=Interval(2,4);
	auto a2=Interval(7,10);
	auto a3=Interval(15,20);
	vector<Interval> test={a1,a2};
	Solution sln;
	cout<<sln.canAttendMeetings(test)<<endl;
	return 0;
}