#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

bool isPrime(int num){
	for(int i=2;i<num/2;i++) {
		if(num%i == 0) return true;
	}
	return false;
}
bool Jamcoin(vector<int>& ch){
	for(int i=0;i<ch.size();i++) {
		if(isPrime(ch[i])) return true;
	}
	return false;
}
int fd(int num){
	for(int i=2; i<num/2; i++) {
		if(num%i == 0) return i;
	}
}

int main() {
	int N; cin>>N;
	int J; cin>>J;
	cout << J << endl;
	int cnt = 0;
	while(cnt < J){
		vector<int> tmp(N);
		cout << "cnt" << cnt << endl;
		for(int k=1;k<N-1;k++) tmp[k] = rand()%2;
		tmp[0] = tmp[N-1] = 1;
		vector<int> bases;
		for(int b=2;b<=10;b++){
			int count=0;
			for(int bs=0;bs<tmp.size();bs++){
				tmp[bs] == 1 ? count+=pow(b, N-bs-1) : count+=0;
			}
			bases.push_back(count);
		}
		 if(!Jamcoin(bases)) {
			cnt++;
			vector<int> divisor;
			for(int n=0;n<bases.size();n++) divisor.push_back(fd(bases[n]));
			for(int d=0;d<tmp.size();d++) cout << tmp[d];
			cout << " Now displaying the divisors" << endl;
			for(int d=0;d<divisor.size();d++) cout << divisor[d] << endl;
		 }
	}
	return 0;
}
