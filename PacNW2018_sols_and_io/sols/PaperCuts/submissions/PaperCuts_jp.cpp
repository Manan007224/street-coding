#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
string a, b;
map<int, int> d[100];
int main()
{
	cin >> a >> b;
	d[0][0] = -1;
	for (int i = 1; i <= a.length(); i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// cut a[j-1 ... i-1] as a strip
			string st = a.substr(j - 1, i - j + 1);
			vector<int> masks;
			for (int s = 0; s+i-j < b.length(); s++)
			{
				if (b.substr(s, i - j + 1) == st)
				{
					masks.emplace_back(((1 << (i - j + 1)) - 1) << s); // 2^s + .. + 2^(s+i-j)
				}
			}
			for (int mask : masks)
			{
				for (auto it : d[j - 1])
				{
					if (it.first&mask) continue;
					int newmask = it.first | mask;
					auto dit = d[i].find(newmask);
					if (dit == d[i].end()) d[i][newmask] = it.second + 1;
					else d[i][newmask] = min(dit->second, it.second + 1);
				}
			}
		}
	}
	cout << d[a.length()][(1 << a.length()) - 1]<<endl;
	return 0;
}
