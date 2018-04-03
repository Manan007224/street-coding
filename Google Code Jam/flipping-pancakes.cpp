#include <iostream>
#include <string>
using namespace std;


int main() {
	int n; cin>>n;
	for(int i=0;i<n; i++) {
		string tmp; cin>>tmp; int count = 0;
		for(int j=1; j<tmp.length(); j++) {
			if(tmp[j] == tmp[j-1]) count++;
		}
		if(tmp.back() == '-') count++;
		cout << "Case #"<< i+1 << " " << count << endl;
	}
	return 0;
}