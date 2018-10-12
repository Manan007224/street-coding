#include <bits/stdc++.h>
using namespace std;

typedef vector<int> lst;

 bool add(lst test, int k){
 	int a = 0;
 	for(auto& k: test)
 		a+=k;
 	return (a==k);
}

int subs(lst tp1, lst tp2, int k){
	if(tp2.size()==0)
		return (add(tp1,k)) ? 1 : 0;
	lst vt (tp2.begin()+1, tp2.end());
	lst vt1 = tp1;
	vt1.push_back(tp2[0]);
	int ll = subs(tp1,vt,k) + subs(vt1,vt,k);
	return ll;
}

int main(){
	lst input = {1,1,1};
	lst fs = {input[0]};
	lst vt (input.begin()+1, input.end());
	lst ep;
	int ans = subs(ep,vt,2) + subs(fs,vt,2);
	cout<<ans<<endl;
	return 0;
}