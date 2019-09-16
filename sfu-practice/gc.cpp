#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000; 

// sieve function for generating fast primes
vector<int> sv() { 
	vector<int> primes;
  bool marked[MAX/2 + 100] = {0}; 
  for (int i=1; i<=(sqrt(MAX)-1)/2; i++) 
    for (int j=(i*(i+1))<<1; j<=MAX/2; j=j+2*i+1) marked[j] = true; 
  primes.push_back(2); 
  for (int i=1; i<=MAX/2; i++) 
  	if (marked[i] == false) primes.push_back(2*i + 1);
  return primes; 
}

int main() {
	vector<int> primes = sv();
	while(1) {
		int n; cin >> n;
		if(!n) break;
		for(int i=0; i<primes[i]<=n/2; i++) {
			int t = n - primes[i];
			bool flag = binary_search(primes.begin(), primes.end(), t);
			if(flag) {
				cout << primes[i] << " + " << t << " = " << n << endl;
				break;
			}
		}
	}
	return 0;
} 