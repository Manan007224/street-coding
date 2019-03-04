#include <bits/stdc++.h>
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
using namespace std;

vector<int> res;
int maxM;
int finalSUM;


void printSequence(vector<vector<vector<int>>>& memo) {
	vector<int> possibleNumbers;
	for(int b=1; b<memo.size(); ++b) {
		for(int l=1; l<memo[b].size(); ++l) {
			for(int r=1; r<memo[b][l].size(); ++r) {
				if(memo[b][l][r]!=0) {
					possibleNumbers.push_back(memo[b][l][r]);
					cout << "Value at [" << b << "," << l << "," << r << "] = " << memo [b][l][r] << endl;
				}
			}
		}
	}
	// sort(possibleNumbers.begin(),possibleNumbers.end() );
	// possibleNumbers.erase(unique(possibleNumbers.begin(),possibleNumbers.end() ),possibleNumbers.end());
	// for(int i=0; i<possibleNumbers.size(); ++i) {
	// 	cout << possibleNumbers[i] << ",";
	// }
	// cout << endl;
	// cout << "reaching point 1" << endl;
	// combinationSum2(possibleNumbers,finalSUM);
	// cout << "reaching point 2" << endl;
	// for(int i=0; i<res.size(); ++i) {
	// 	for(int j=0; j<res[i].size(); ++j) {
	// 		cout << res[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
}

// void show_last(viii &memo, int l, int r, int b) {
// 	int mn = INF, mx = -INF, nb, nl, nr;
// 	for(int i=l; i<=r; i++) {
// 		if(memo[b-1][l][i-1] > memo[b][i+1][r] && mn > memo[b-1][l][i-1])
// 			mx = memo[b-1][l][i-1], nb = b-1, nl = l; nr = i-1;
// 		else
// 			mx = memo[b][i+1][r], nb = b, nl = i+1, nr = r;
// 		mn = min(mn, mx);
// 	}
// }

void sf(viii &memo) {
	for(int i=1; i<73; i++) {
		cout << memo[b-1][l][i-1] << " " << memo[b][i+1][r] << endl;
	}
}

int rec(int b, int l, int r, int& sum, vector<vector<vector<int>>>& memo, int minValue) {
	if(l>r) {
		return 0;
	} else {

		if(b==1) {
			int val = (r*(r+1))/2 - (l*(l-1))/2;
			memo[b][l][r] = val;
			sum = memo[b][l][r];
			return val;
		} else if(b>1) {
			if(memo[b][l][r]) {
				return memo[b][l][r];
			}
			for(int i=l; i<=r; ++i) {
				int val1 = rec(b-1,l,i-1,sum,memo,INT_MAX)+i;
				int val2 = rec(b,i+1,r,sum,memo,INT_MAX)+i;
				int val = max(val1,val2);
				minValue = min(minValue,val);
			}
			memo[b][l][r] = minValue;
			sum = memo[b][l][r];
			return memo[b][l][r];
		}

	}
}

int main() {
	string line;
	int k,m;
	getline(cin,line);
	istringstream iss{line};
	iss >> k;
	iss >> m;

	maxM = m;

	vector<vector<vector<int>>> memo(k+1, vector<vector<int>>(m+1, vector<int>(m+1)));

	int sum = 0;
	rec(k,1,m,sum,memo,INT_MAX);

	finalSUM = sum;
	////////////////////////////////////////////////////////////////////////////////////////
	cout << "PRINTING ARRAY" << endl;
	for(int i=0; i<res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
	cout << "********************************************" << endl;
	cout << "sum --> " << sum << endl;

	// cout << "********************************************" << endl;
	// printSequence(memo);
	////////////////////////////////////////////////////////////////////////////////////////
    sf(memo);
    return 0;
}