#include <iostream>
#include <vector>
using namespace std;

bool check_tidy(long long n) {
	vector<long long> temp;
	long num = n;
	while(num>0) {
		long long c = num%10; temp.push_back(c);
		num /= 10;
	}
	if(temp.size() == 1) return true;
	else {
		for(long long j=temp.size()-1;j>0;j--) {
			if(temp[j] > temp[j-1]) return false; 
		}
		return true;
	}
}

int main() {
	int t; cin >>t;
	while(t>0) {
		t--;
		long long num; cin>>num;
		for(long long i=num;i>0;i--) {
			if(check_tidy(i)) {
				cout << "THE LAST TIDY NUMBER IS" << i << endl;
				break;
			}
		}
	}
	return 0;
}