#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pt;
typedef vector<pt> lst_p;
bool icomapre(pt& a, pt&b){return a.first < b.first;}
struct compare{
    bool operator()(pt& a, pt& b){return a.second > b.second;}
};

int solution(vector<int> &S, vector<int> &E) {
    lst_p people;
    if(S.size()==0) return 0;
    int ll = S.size();
    for(int x=0; x<ll; x++) people.push_back({S[x],E[x]});
    sort(people.begin(), people.end(), icomapre);
    priority_queue<pt,lst_p,compare> q;
    int chairs = 1;
    q.push(people[0]);
    for(int x=1; x<ll; x++){
      int check = q.top().second;
      int tp = people[x].first;
      if(tp<check) chairs++;
      else q.pop();
      q.push(people[x]);
    }
    return chairs;
}

int main(){
  vector<int> start = {1,2,6,5,3};
  vector<int> end = {5,5,7,6,8};
  cout<<solution(start,end)<<endl;
  return 0;
}