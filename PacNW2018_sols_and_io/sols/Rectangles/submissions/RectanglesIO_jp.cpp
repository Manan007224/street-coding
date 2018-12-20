#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int N;
vector<ll> a, sign;
void pop(int i)
{
	a[i >> 1] = (a[i] + a[i ^ 1])*sign[i >> 1];
}
void pop_up(int i)
{
	for (; i > 1; i >>= 1) pop(i);
}
void init_tree()
{
	for (int i = 2 * N - 1; i > 1; i -= 2) pop(i);
}
void modifier_helper(int i)
{
	a[i] = -a[i];
	sign[i] = -sign[i];
}
void modify(int L, int R)
{
	L += N;
	R += N;
	int LCopy = L;
	int RCopy = R;
	for (; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1)
	{
		if (L & 1) modifier_helper(L);
		if (!(R & 1)) modifier_helper(R);
	}
	pop_up(LCopy);
	pop_up(RCopy);
}
ll real_value(int i)
{
	ll v = a[i];
	for (i >>= 1; i > 0; i >>= 1) v *= sign[i];
	return v;
}
ll query(int L, int R)
{
	L += N;
	R += N;
	ll sum = 0;
	for (; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1)
	{
		if (L & 1) sum += real_value(L);
		if (!(R & 1)) sum += real_value(R);
	}
	return sum;
}
struct ev
{
	int x, y1, y2;
	ev() {}
	ev(int x, int y1, int y2) : x(x), y1(y1), y2(y2) {}
	bool operator < (const ev& o) const { return x < o.x; }
};
int main()
{
	int n;
        cin >> n ;
	vector<int> ys;
	map<int, int> ytoi;
	vector<ev> events;
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2 ;
		ys.emplace_back(y1);
		ys.emplace_back(y2);
		events.emplace_back(ev(x1, y1, y2));
		events.emplace_back(ev(x2, y1, y2));
	}
	sort(ys.begin(), ys.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());
	int ycnt = ys.size();
	for (int i = 0; i < ycnt; i++) ytoi[ys[i]] = i;
	for (auto &e : events) { e.y1 = ytoi[e.y1]; e.y2 = ytoi[e.y2]; }
	sort(events.begin(), events.end());

	for (N = 1; N < ycnt; N <<= 1);
	a.resize(2 * N + 1, 0);
	sign.resize(2 * N + 1, 1);
	for (int i = 0; i < ycnt - 1; i++) a[N + i] = -(ys[i + 1] - ys[i]);
	init_tree();

	ll lstx = events[0].x;
	ll ans = 0;
	for (auto &e : events)
	{
		// sum areas
		ll dx = e.x - lstx;
		ans += query(0, ycnt - 1)*dx;
		// flip sign
		modify(e.y1, e.y2 - 1);
		lstx = e.x;
	}

	ll all_area = (ys.back() - ys[0])*(lstx - events[0].x);
        cout << (all_area + ans) / 2 << endl ;
}
