#include <bits/stdc++.h>
using namespace std;

bool is_p(int n) {
	if (n <= 1)  return 0;
  if (n <= 3)  return 1;
  if (n%2 == 0 || n%3 == 0) return 0;
  for (int i=5; i*i<=n; i=i+6) {
  	if (n%i == 0 || n%(i+2) == 0) return 0;
  }
  return true;
}

int main() {
	int m, n, r = 0;
	if(m==1 && n==1) return 0;
	cin >> m >> n;
	vector<int> primes;
	for(int i=m; i<=n; i++) {
		if(is_p(i)) primes.push_back(i);
	}
	for(int i=0; i<primes.size()-1; i++) {
		if(primes[i+1] - primes[i] == 2) r++;
	}
	cout << r << endl;
	return 0;
}