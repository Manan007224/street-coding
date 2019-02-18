#include <bits/stdc++.h>
using namespace std;
typedef pair<string,int> pts;

enum State{ACTIVE, BLACKLIST};

struct client{
	string name;
	int start, count, b_start, end, res;
	State state;
	vector<int> hist;
	client(string n,int s){
		name {n}, res {0}, start{s}, count {0}, state {ACTIVE}, b_start {-1};
		hist=vector<int>(5,0);
	}
};

pts split(string input){
	vector<string> v;  stringstream ts(input); string tk;
	while(getline(ts,tk,' ')) v.push_back(tk);
	return {v[0],stoi(v[1])};
}

vector<string> solution(vector<string> &A, int Y) {
	int ll = A.size();
	int cnt {0};
    vector<client> requests;
    string ls = split(A[0]).first, cr;
    requests.push_back({ls,0});
    int max_sec = split(A[0]).second;
    cnt ++;
    for(int i=1; i<ll; i++){
    	max_sec = max(max_sec, split(A[i]).second);
    	cr = split(A[i]).first;
    	if(cr!=ls){
    		requests[requests.size()-1].end = i-1;
    		requests.push_back({cr,i});
    		cnt ++;
    	}
    	ls = cr;
    }
    requests[requests.size()-1].end = ll-1;
    int max_min = max_sec /= 60;
    for(int i=0; i<=max_min; i++){
    	int max_client {0}, max_client_idx {-1}, total{0};
    	for(int k=0; k<cnt; k++){
    		client& temp = requests[k];
    		if(temp.state == BLACKLIST && temp.b_start == i-2) temp.state = ACTIVE;
    		if(temp.state == BLACKLIST){
    			if(split(A[temp.start]).second/60 == i){
    				temp.start++;
    				temp.hist[i%5] = temp.hist[(i-1)%5];
    			}
    		}
    		if(temp.state == ACTIVE){	
    			int idx = temp.start;	
    			int c = 0;
	    		while(1){
	    			if(temp.end < idx || split(A[idx]).second/60 != i) break;	
	    			c++, idx++;
	    		}
	    		temp.count -= temp.hist[i%5];
	    		temp.hist[i%5] = min(c,Y);
	    		temp.res += min(c,Y);
	    		temp.count += temp.hist[i%5];
	    		if(temp.count > max_client) {max_client = temp.count; max_client_idx = k;} 
	    		temp.start = idx;
	    		total += temp.count;
    		}
    		
    	}

    	if(total && total/max_client<2 && total >= 10){
    		requests[max_client_idx].state = BLACKLIST;
    		requests[max_client_idx].b_start = i;
    	}
    }
    vector<string> ans(requests.size());
    for(int x=0; x<requests.size(); x++)
    	ans[x]=(requests[x].name + " " + to_string(requests[x].res));
    return ans;
}

int main(){
	vector<string> test = {"bella 0", "bella 15", "bella 59", "bella 59", 
	"bella 60", "bella 62", "bella 80", "bella 120", "bella 180", "bella 240", 
	"erica 0", "erica 60", "erica 120", "erica 180", "erica 240", "erica 320"};
	vector<string> test1 = {"A 0","A 30","A 59","A 70","A 75","A 75","A 120","A 123",
	"A 198","A 245","B 40","B 76","B 134","B 180","B 245","C 45","C 78","C 124","C 185",
	"C 245","C 340","C 340"};
	vector<string> ans = solution(test1, 3);	
	for(auto a:ans) cout<<a<<endl;
	return 0;
}