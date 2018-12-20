
#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n; cin>>n;
	long long c=n+10;
	vector<long long> v;
	v.push_back(n);
	for(long long i=n+1;i<c;i++) v.push_back(i+v.back());
	long long mid=1,right=2;
	while(true){
		long long a=v[mid-1];
		long long b=v[right]-v[mid];
		if(a==b){
			cout<<n<<' '<<(n+mid)<<' '<<(n+right)<<endl;
			break;
		}
		else if(a<b) mid++;
		else{
			right++;
			v.push_back(c+v.back());
			c++;
		}
	}
}

