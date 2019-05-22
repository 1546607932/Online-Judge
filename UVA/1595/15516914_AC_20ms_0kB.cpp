#include<iostream>
#include<cmath>
#include<set>
using namespace std;
const double eps = 1e-6;
struct point
{
	int x, y;
	point(int x=0, int y=0) :x(x), y(y) {}
}p[1000];
bool operator<(const point& a, const point& b)
{
	return a.x < b.x || ((a.x == b.x) && (a.y < b.y));
}
bool dcmp(double a, double b)
{
	if (fabs(a - b) < eps)
		return 1;
	else
		return 0;
}
set<point> graph;
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		graph.clear();
		int flag = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> p[i].x >> p[i].y;
			graph.insert(p[i]);
		}
		int i = 0;
		double sym = ((*graph.begin()).x + (*--graph.end()).x) / 2.0;
		for (int i = 0; i < n; i++)
			if (dcmp(p[i].x, sym))
				continue;
			else if (p[i].x < sym)
			{
				point temp(round(sym + (sym - p[i].x)), p[i].y);
				if (graph.find(temp) == graph.end())
				{
					flag = 1;
					break;
				}
			}
		if (flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}