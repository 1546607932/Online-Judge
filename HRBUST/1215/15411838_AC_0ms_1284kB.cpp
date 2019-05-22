#include<iostream>
#include<cmath>
using namespace std;
double a, b, c, d;
const double eps = 1e-6;
double x[3];
const int INF = 10000;
double function(double x)
{
	return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}
double get_ans(double first,double end)
{
	double begin = first;
	double fbegin = function(first);
	double fend = function(end);

	if (fabs(fbegin) < eps)
		return begin;
	else if (fabs(fend) < eps)
		return end;
	else if (fbegin*fend > 0)
		return INF;
	else if (fbegin*fend < 0)
	{
		double ans;
		double mid = (first + end) / 2.0;
		if ((ans = get_ans(first, mid)) != INF)
			return ans;
		else
			return get_ans(mid, end);
	}
}
int main()
{
	while (cin >> a >> b >> c >> d)
	{
		int count = 0;
		for (int first = -100; first < 100; first++)
		{
			double ans = get_ans(first, first + 1);
			if (ans != INF)
			{
				int flag = 1;
				for (int i = 0; i < count; i++)
					if (x[i] == ans)
						flag = 0;
				if (flag)
					x[count++] = ans;
			}
			if (count == 3)
				break;
		}
		printf("%.2lf %.2lf %.2lf\n", x[0], x[1], x[2]);
	}
	return 0;
} 