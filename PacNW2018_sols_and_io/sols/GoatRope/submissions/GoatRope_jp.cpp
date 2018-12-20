#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
double clip(double p, double s, double e) { return min(e, max(p, s)); }
int main()
{
	double x, y, x1, y1, x2, y2;
	scanf("%lf%lf%lf%lf%lf%lf", &x, &y, &x1, &y1, &x2, &y2);
	printf("%.3lf\n", hypot(clip(x, x1, x2) - x, clip(y, y1, y2) - y));
	return 0;
}
