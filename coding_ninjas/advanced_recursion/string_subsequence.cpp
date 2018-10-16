#include <bits/stdc++.h>
using namespace std;

void subsequence(string str, unordered_set<string> &st){
  if(st.find(str)==st.end())
    st.insert(str);
  for(int i=0;i<str.length();i++){
    string tp = str;
    string nstr = tp.erase (i,1);
    if(st.find(nstr)==st.end())
      subsequence(nstr, st);
  }
}

int subs(string input, vector<string> &output){
  if(input.empty()){
    output.push_back(" ");
    return 1;
  }
  string nstr = input.substr(1);
  int nstr_count = subs(nstr, output);
  for(int i=0;i<nstr_count;i++)
    output.push_back(input[0] + output[i]);
  return 2*nstr_count;
}

int main(){
  string str = "abc";
  unordered_set<string> st;
  subsequence(str, st);
  for(auto it=st.begin(); it!=st.end(); it++){
    cout << *it << endl;
  }
  vector<string> ans;
  subs(str, ans);
  for(auto it: ans) cout << it << endl;
  return 0;
}
