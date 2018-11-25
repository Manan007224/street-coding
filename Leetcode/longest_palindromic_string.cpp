#include <bits/stdc++.h>
using namespace std;

int main(){
    string a; cin>>a;
    int mx=0;
    int ll=a.length(); 
    string ans="";
    for(int x1=0;x1<ll;x1++){
        int i=x1; int j=x1;
        int k=x1;
        while(k++<2){
            if(i>=0 && j<=ll-1 && a[i]==a[j]){
                while(i-1>=0 && j+1<=ll-1 && a[i-1]==a[j+1]) i++,j--;
                int cc=j-i;
                if(mx>cc){
                    mx=cc;
                    ans=a.substr(i,j-i+1);
                }
            } 
            i=k; j=k+1;
        }
    }
    cout<<ans<<endl;
	return 0;
}