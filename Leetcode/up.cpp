#include <bits/stdc++.h>
using namespace std;

int HashCode (const std::string &str) {
    int h = 0;
    for (size_t i = 0; i < str.size(); ++i)
        h = h * 31 + static_cast<int>(str[i]);
    return h;
}

int main() {
	// vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
	// int i = 0;
	// int m = 10;
	// int x = upper_bound(matrix[i].begin(), matrix[i].end(), m)-matrix[i].begin();
	// cout << x << endl;
	// vector<int> v = {10, 15, 17, 26, 45, 56, 60};
	// cout << v[upper_bound(v.begin(), v.end(), 40) - v.begin()] << endl;
	string data = "ManAN";
	cout << HashCode(data) << endl;
	cout << HashCode("maniyarmanan1996@gmail.com") << endl;
	string a = "ATL", b = "SFO";
	cout << (a<b) << endl;
	return 0;
}