#include <bits/stdc++.h>
using namespace std;

vector<int> visited = {0,0,0,0,0};

int fibonacci(int num) {
	int fb;
	if(visited[num]!=0)
		return visited[num];
	else {
		if(num<=2)
			fb = 1;
		else 
			fb = fibonacci(num-1) + fibonacci(num-2);
		visited[num] = fb;
		return fb;
	}
}

int factorial(int num) {
	int fc;
	if(visited[num]!=0)
		return visited[num];
	else if(num<=1) {
		fc = 1;
		visited[num] = fc;
		return 1;
	}
	else {
		fc = num*factorial(num-1);
		visited[num] = fc;
		return fc;
	}
}


int main() {
	cout << factorial(5) << endl;
	cout << fibonacci(5) << endl;
}