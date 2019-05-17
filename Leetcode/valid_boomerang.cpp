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

class Solution {
public:
  bool isBoomerang(vector<vector<int>>& points) {
  	return ((points[1][0]-points[0][0])*(points[2][1]-points[1][1]) != (points[2][0]-points[1][0])*(points[1][1]-points[0][1])); 
  }
};

int main() {
	return 0;
}