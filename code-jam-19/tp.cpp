#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

int n = 8, b = 5;

string buildReq(int k) {
  string res;
  for(int i = 0; i < n; i++) {
    res += ((i >> k) & 1) ? '1' : '0';
  }
  return res;
}

void find_broken(int pdi, int rid, int numWorking, vector<string> responses, vector<int>& res) {
  set<int> found;
  for(int i = 0; i < numWorking; i++) {
    int value = 0;
    for(int j = 0; j < 4; j++) {
      value = (value << 1) | (responses[j + 1][rid + i] == '1');
    }
    found.insert(value);
  }

  int partSize = min(n, (pdi + 1) * 16) - (pdi * 16);
//  cerr << "partSize " << partSize << endl;
  for(int i = 0; i < partSize; i++) {
    if(!found.count(i)) {
      res.push_back(pdi * 16 + i);
    }
  }
}


int main() {
	vector<string> req = {"00001111", "00110011", "01010101"};
	vector<string> responses = {"00111", "01001", "00011"};
	vector<int> values = {5,0};
	
	int rid = 0, pdi = 0;
	vector<int> res;
	for(int i=1; i<=n-b; i++) {
		if(i == n + b || responses[0][i] != responses[0][i - 1]) {
			cout << "came" << " " << i << endl;
      find_broken(pdi, rid, i - rid, responses, res);
      rid = i;
      pdi++;
    }
	}


	return 0;
}