#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) return recur(1/x,abs(n));
        else return reucr(x,n);
    }

    double recur(double x,int n){
    	if(n==0) return 1.0;
    	double half=recur(x,n/2);
    	return (n%2==0)?(half*half):(half*half*x);
    }
};