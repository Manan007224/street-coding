#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int minc(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}


int maxPath(vector< vector<int > > &v, int r, int c) {
	if((r<0) || (c<0)) 
		return 0;
	else if(r == 0 && c==0)
		return v[r][c];
	else
		cout << v[r][c] << " " ;
		return v[r][c] + minc(maxPath(v,r-1,c-1), maxPath(v,r-1,c), maxPath(v,r,c-1));
}

int main() {
	vector< vector< int > > m = {{1,2,3},
							 	{4,8,2},		
							 	{1,5,3}};
	int op = maxPath(m,2,2);
	cout << op << endl;
	return 0;
}