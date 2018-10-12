#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
    	int k=0;
        while(str[k]==' ')
        	k++;
        if(k==str.length())
        	return 0;
        if(str[k]!='+' && str[k]!='-' && !isdigit(str[k]))
        	return 0;
        bool flag = false;
        int pos = k;
        flag = (str[k]=='-') ? true: false;
        if(str[k]=='+' || str[k]=='-')
        	pos++;
        string num;
        while(isdigit(str[pos]) && pos<str.length()){
        	num+=str[pos];
        	pos++;
        }
        int ans = 0;
        int cnt = num.length()-1;

        for(int i=cnt;i>=0;i--){
        	ans = ans + (int(num[i])-48)*(pow(10.0,cnt-i));
        	if(ans>numeric_limits<int>::max())
        		return (flag==false) ? numeric_limits<int>::max() : numeric_limits<int>::min();
        }
        if(ans<=numeric_limits<int>::min())
        	return (flag==false) ? numeric_limits<int>::max() : numeric_limits<int>::min();
        else
        	return (flag==false) ? +(ans) : -(ans);
    }
};

int main(){
	string str = "-91283472332";
	Solution sln;
	cout<<sln.myAtoi(str)<<endl;
	return 0;
}
