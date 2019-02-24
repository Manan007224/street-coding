#include <bits/stdc++.h>
using namespace std;

struct Interval{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool icomapre(Interval &a, Interval &b){
	return a.start < b.start;
}

struct compare{
	bool operator()(Interval const &a, Interval const &b){
		return a.end > b.end;
	}
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
    	if(intervals.size()==0) return 0;
        //sort(intervals.begin(), intervals.end(), icomapre);
        priority_queue<Interval, vector<Interval>, compare> q;
        int rooms=1;
        q.push(intervals[0]);
        for(int x=1; x<intervals.size(); x++){
        	int check = q.top().end;
        	int tp = intervals[x].start;
        	if(tp<check) rooms++;
        	else q.pop();
        	q.push(intervals[x]);
        }
        return rooms;
    }
};

int main(){
	auto a1=Interval(0,30);
	auto a2=Interval(5,10);
	auto a3=Interval(15,20);
	auto a4=Interval(9,15);
	auto a5=Interval(16,19);
	auto a6=Interval(7,10);
	auto a7=Interval(9,11);
	auto a8=Interval(13,15);
	Solution sln;
	vector<Interval> test={a6,a7,a8};
	cout<<sln.minMeetingRooms(test)<<endl;
	return 0;
}