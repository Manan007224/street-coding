
#include <bits/stdc++.h>
using namespace std;

int main(){
	cout<<fixed<<setprecision(3);
	int x,y,x1,y1,x2,y2;
	cin>>x>>y>>x1>>y1>>x2>>y2;
	if(x1>x2) swap(x1,x2);
	if(y1>y2) swap(y1,y2);
	
	if(x>=x1 && x <=x2){
		cout<<((double) (min(abs(y-y1),abs(y-y2))))<<endl;
	}
	else if(y>=y1 && y<=y2){
		cout<<((double) (min(abs(x-x1),abs(x-x2))))<<endl;
	}
	else{
		double yy=((double) (min(abs(y-y1),abs(y-y2))));
		double xx=((double) (min(abs(x-x1),abs(x-x2))));
		cout<<sqrt(xx*xx + yy*yy)<<endl;
	}
}


