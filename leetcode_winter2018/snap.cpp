#include <bits/stdc++.h>
using namespace std;
typedef vector<float> vf;
typedef unordered_map<string,vf> supplier;
typedef unordered_map<string,supplier> Custom;

int check_rate(int rate, string supl, int days){
	if(supl == "A" && days <= 1) return (rate+(rate*0.5));
	else if(supl == "B" && days < 3) return -1;
	else if(supl == "C" && days < 7) return (rate-(rate*0.1));
	else if(supl == "D" && days < 7) return (rate+(rate*0.1));
	else return rate;
}


int main(){
	int t; cin>>t;
	Custom snap;
	// filling the values in the data structure
	while(t--){
		string city, supl;
		float rate;
		cin>>city>>supl>>rate;
		if(snap.find(city)==snap.end()){
			supplier s; 
			vf v = {rate};
			s[supl] = v;
			snap[city] = s; 
		}
		else{
			supplier now = snap[city];
			if(now.find(supl)==now.end()){
				vf v = {rate};
				now[supl] = v;
			}
			else now[supl].push_back(rate);
		}
	}
	int x; cin>>x;
	while(x--){
		string city; cin>>city;
		int days; cin>>days;
		supplier city_map = snap[city];
		vf rates;
		for(auto cm: city_map){
			cout<<cm.first<<endl;
			string sp = cm.first;
			vf check = cm.second;
			for(auto ch: check){
				if(check_rate(ch, cm.first, days) != -1) rates.push_back(ch);
			}
		}
		sort(rates.begin(), rates.end());
		if(rates.size() == 0) cout<<"None"<<endl;
		else{
			for(auto r: rates) cout<<r<<" ";
			cout<<endl;
		}
	}
	return 0;
}