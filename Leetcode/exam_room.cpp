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

class ExamRoom {
public:

	int size;

	struct compare {
		bool operator() (pii &a, pii &b) {
			return (a.se-a.fi) >= (b.fi-b.se);
		}
	}

  ExamRoom(int N) {
    priority_queue<pii> pq;
    size = N;
    pq.push(-1, N);
  }
  
  int seat() {
  	int mid;
  	pii now = pq.top();
  	pq.pop();
  	if(now.fi == -1) mid = 0;
  	else if(now.se == size) mid = size-1;
    else {
    	mid = (now.se+now.fi)/2;
    	pq.push({available.fi, mid});
    	pq.push({mid, available.se});
    }
    return mid;  
  }
  
  void leave(int p) {
    vector<pii> pq_v;
    while(!pq.empty()) {
    	pq_v.pb(pq.top());
    	pq.pop();
    }
    int s_pos = -1, e_pos = -1;
    for(int i=0; i<pq_v.size(); i++) {
    	if(pq_v[i].fi == p) s_pos = i;
    	if(pq_v[i].se == p) e_pos = i;
    	if(s_pos != -1 && e_pos != -1) break;
    }
    for(int i=0; i<pq_v.size()){
    	if(i==s_pos || i==e_pos) continue;
    	pq.push(x);
    }
  }
};

int main() {
	return 0;
}