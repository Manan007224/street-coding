#include <bits/stdc++.h>
using namespace std;

const int MAX = 20100;
vector<int> p;


void sv() {
 	vector<int> primes;
  bool marked[MAX/2 + 100] = {0};
  for (int i=1; i<=(sqrt(MAX)-1)/2; i++)
    for (int j=(i*(i+1))<<1; j<=MAX/2; j=j+2*i+1) marked[j] = true;
  primes.push_back(2);
  for (int i=1; i<=MAX/2; i++)
    if (marked[i] == false) primes.push_back(2*i + 1);
  for(int i=0; i<primes.size(); i+=2) p.push_back(primes[i]);
}

bool go(int left, unordered_map<int, bool> &lookup) {
	if(lookup.find(left) != lookup.end()) return lookup[left];
	for(int i=0; i<p.size(); i++) {
		if(left - p[i] < 0) continue;
		if(!go(left - p[i], lookup)) return lookup[left] = 1;
	}
	return lookup[left] = 0;
}

int main() {
	sv();
	unordered_map<int, bool> lookup;
	for(int i=0; i<=20000; i++) go(i, lookup);
	int n;
	while(cin >> n) {
		if(lookup[n]) cout << "Stan wins." << endl;
		else cout << "Ollie wins." << endl;
	}
	return 0;
}