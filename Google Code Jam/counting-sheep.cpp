#include <iostream>
#include <vector>
using namespace std;

bool find(vector<int>& temp, int num){
    for(int i=0;i<temp.size();i++) {
        if(temp[i] == num) return true;
    }
    return false;
}

int main() {
    vector<int> check; vector<int> v;
    int n; cin >> n;
    int t = 0;
    for(int i=0;i<v.size();i++){
       int input = v[i];
       vector<int> check;
       int N = 1; int to_ch = 0; int last = 0; bool flag = true;
       while(check.size()<=9) {
             to_ch = input*N;
             if(to_ch == last) {
                cout <<"Case #"<<i+1 <<":"<<" INSOMNIA" << endl; 
                flag = false; 
                break;
            }
             last = to_ch;
             N++;
             int just = to_ch;
             while(just>0){
                int c = just%10; just /=10;
                if(find(check, c) == false) {check.push_back(c);} 
            } 
        }
        if(flag==true){
        cout<<"Case #"<< i+1 << ": " << to_ch << endl;}
    } 
    return 0;
}
