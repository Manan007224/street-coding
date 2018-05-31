#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findLongestPath(vector< vector< int> > &matrix, int i, int j) {
	int congested = false;
	int r = matrix.size(); int c = matrix[0].size();
	int len = 0;
	while(!congested) {
		if(i<r-1 && (matrix[i][j]+1==matrix[i+1][j])) {
			i=i+1;
			len++;
		}
		else if(i>0 && (matrix[i][j]+1==matrix[i-1][j])) {
			i=i-1;
			len++;
		}
		else if(j<c-1 && (matrix[i][j]+1==matrix[i][j+1])) {
			j=j+1;
			len++;
		}
		else if(j>0 && matrix[i][j]+1==matrix[i][j-1]) {
			j=j-1;
			len++;
		}
		else congested=true;
	}
	return len+1;
}

int main() {
		vector <vector <int > > m = {{1, 2, 9},
									{5, 3, 8},
									{4, 6, 7}};
		vector<int> pl;
		for(int i=0;i<m.size();i++) {
			for(int j=0; j<m[i].size(); j++) {
					pl.push_back(findLongestPath(m, i, j));
			}
		}
		auto big = max_element(begin(pl), end(pl));
		cout << "Length of the Longest Path is = " << *big << endl;
}