#include<iostream>
using namespace std;
const int maxn = 10005;
int a[maxn];
int INF = 1000000000;
int main()
{
	int n;
	while ((cin >> n) && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int l = 0, r = 0;//最大值的左右端点
		int total = 0, maxsum = -INF;

		int i, j;
		for (i = 0, j = 0; j < n; j++)
		{
			total += a[j];
			if (total > maxsum)
			{
				l = i;
				r = j;
				maxsum = total;
			}
			if (total < 0)
			{
				i = j + 1;
				total = 0;
			}
		}
		if (maxsum >= 0)
			cout << maxsum << ' ' << a[l] << ' ' << a[r] << endl;
		else
			cout << 0 << ' ' << a[0] << ' ' << a[n - 1] << endl;
	}
	return 0;
}