#include<iostream>
#include<algorithm>
using namespace std;
struct point
{
	int x;
	int y;
	int id;
} Point[30000];
bool cmp(point a, point b)
{
	return a.x < b.x || (a.x == b.x) && (a.y < b.y);
}
int main()
{
	int t;
	int n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int count = 0;
		for (;;)
		{
			cin >> Point[count].x >> Point[count].y;
			Point[count].id = count+1;
			count++;
			if (count == 3 * n)
				break;
		}
		sort(Point, Point + 3 * n, cmp);
		for (int i = 0; i < n; i++)
		{
			cout << Point[3 * i].id << ' ' << Point[3 * i + 1].id << ' ' << Point[3 * i + 2].id << endl;
		}
	}
	return 0;
}