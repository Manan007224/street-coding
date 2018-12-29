
#include <bits/stdc++.h>
using namespace std;

string start, ss;
const unsigned int ONE=1;

bool func(const vector<string>& v, vector<bool>& done, int pos){
	/*
	string c=ss.substr(pos,1);
	//c[0]--;
	ostringstream oss;
	oss<< ((char)(c[0]-1))<<'{';
	string a = oss.str();
	//c[0]++;
	string b = c+"{";
	cout<<" a: "<<a<<", b: "<<b<<endl;
	//auto it=lower_bound(v.begin(), v.end(), ""+c+((char)(((int)'a')-1)));
	//auto eit=upper_bound(v.begin(), v.end(), ""+c+((char)(((int)'z')+1)));
	
	int i = distance(v.begin(), it);
	int ff=distance(v.begin(), eit);
	
	if(i>0)i--;
	
	for(auto&x: v) cout<<x<<"\t"; cout<<v.size()<<endl;
	cout<<i<<" is start and goes till " << ff <<endl;
	cout<<"char is " << c<<"\n"; */
	
	for(int i=0;i<v.size();i++){
		//cout<<i<<endl;
		if(done[i]) continue;
		cout<<v[i] << " vs " << ss.substr(pos, v[i].size())<<endl;
		if(v[i] == ss.substr(pos, v[i].size())){
			cout<<"matched : "<<v[i]<<endl;
			int xx = pos+v[i].size();
			cout<<xx<<" vs " << ss.size()<<endl;
			if(xx>=ss.size()) return true;
			done[i]=true;
			if(func(v, done, xx)) return true;
			done[i]=false;
		}
	}
	//cout<<"\n\n\n\n\n";
	return false;
}

bool works(unsigned int mask){
	vector<string> v;
	int c=0;
	for(int i=0;i<start.size()-1;i++){
		if((mask & (ONE << i)) == (ONE << i)){
			v.push_back(start.substr(c, i-c+1));
			c=i+1;
		}
	}
	if(c<start.size()) v.push_back(start.substr(c));
	sort(v.begin(), v.end());
		for(auto& x: v) cout<<x<<" ";cout<<endl;
	vector<bool> done(v.size(), false);
	
	bool val= func(v, done, 0);
	if(val){
		cout<<" this works: ";
	}
	return val;
}

int main(){
	cin>>start>>ss;
	if(start == ss){
		cout<<0<<endl;
		return 0;
	}
	
	for(unsigned int i=(1<<start.size()-1)-1;i>0;i--){
		//cout<<"trying " << i<< ": ";
		if(works(i)) cout<<i<<endl;
		//else cout<<endl;
		//works(i);
	}
	return 0;
}

/*
abbaaddccee
aaabbeeddcc
*/
