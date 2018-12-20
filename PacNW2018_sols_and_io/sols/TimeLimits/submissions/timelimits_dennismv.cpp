/*
SER2018
Time Limits
by Dennis Matveyev
*/
#include<iostream>
using namespace std;

int main()
{
	int n, factor;
	cin >> n >> factor;

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (max < temp)
			max = temp;
	}
	cout << (factor * max - 1) / 1000 + 1 << endl;

	return 0;
}
