#include<iostream>
#include<algorithm>
using namespace std;
const int maxl = 100000 + 5;
const int INF = 10000000;
int line[maxl];
int pos;
int n;
int get_max()
{
	int ma = -INF;
	for (int i = 0; i < n; i++)
		if (line[i] > ma) { ma = line[i]; pos = i + 1; }
	return ma;
}
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int kase = 0 , T;
	cin >> T;
	while (T--)
	{
		if (kase)
			cout << endl;
		int flag = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", line + i);
			if (line[i] > 0) { flag = 1; }
		}

		if (!flag)
		{
			printf("Case %d:\n", ++kase);
			int ma = get_max();
			cout << ma << ' ' << pos << ' ' << pos << endl;
		}
		else
		{
			int begin = 0, end = 0;
			int total = 0, sum = 0;
			int fbegin;
			for (int i = 0; i < n; i++)
			{
				total += line[i];
				if (total > sum) { sum = total; fbegin = begin + 1; end = i + 1; }
				if (total < 0) { begin = i + 1; total = 0; }
			}
			printf("Case %d:\n", ++kase);
			cout << sum << ' ' << fbegin << ' ' << end << endl;
		}
	}
	return 0;
}