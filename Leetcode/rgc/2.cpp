#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> &A, int K) {
	int cnt = 0;
	for(int i = 1; i <= A.size() - K; i++)
		if(A[cnt]<A[i]) cnt = i;
	vector<int> res;
	for(int i = cnt; i < A.size(); i++) res.push_back(A[i]);
	return res;
}

int main() {
	vector<int> t = {1,4,3,2,5};
	vector<int> res = solution(t, 4);
	for(auto r : res) cout << r << endl;
	return 0;
}