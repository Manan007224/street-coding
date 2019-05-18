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

class NumMatrixSlow {
public:
  NumMatrixSlow(vector<vector<int>>& matrix) {
  	int m = matrix.size();
    if(m!=0) {
      int n = matrix[0].size();
      dp = vii(m, vi(n+1, 0));
      for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) dp[i][j+1] = dp[i][j] + matrix[i][j];
    }
  }
  
  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;
    for(int i = row1; i <= row2; ++i) sum += (dp[i][col2+1] - dp[i][col1]);
    return sum;
  }
private:
	vector<vector<int>> dp;
};

class NumMatrixFast {
public:
	NumMatrixFast(vector<vector<int>> &matrix) {
		int m = matrix.size();
		if(m != 0) {
			int n = matrix[0].size();
			dp = vii(m+1, vi(n+1, 0));
			for(int i = 1; i <= m; i++) 
				for(int j = 1; j <= n; j++)
					dp[i][j] = matrix[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
	}

private:
	vector<vector<int>> dp;
};

int main() {
	vii arr = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
	NumMatrixFast nmx(arr);
	cout << nmx.sumRegion(2,1,4,3) << endl;
	return 0;
}