#include <iostream>
using namespace std;

bool check(int x) {
	return (x && !(x & (x-1)));
}

int count(int x) {
	int c=0;
	while(x){
		x = (x & (x-1));
		c++;
	}
	return c;
}

int main() {
	cout << check(4) << endl;
	cout << check(6) << endl;
	cout << count(4) << endl;
	return 0;
}