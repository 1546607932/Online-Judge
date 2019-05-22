#include<iostream>
using namespace std;
const int maxl = 100000 + 5;
int n,m;
int lef[maxl], rig[maxl];
void link(int l, int r)
{
	rig[l] = r;
	lef[r] = l;
}
void print_box()
{
	int cur = 0;
	for (int i = 1; i <= n; i++)
	{
		cur = rig[cur];
		cout << cur << ' ';
	}
}
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int kase = 0;
	while (cin >> n >> m)
	{
		//初始化信息
		for (int i = 1; i <= n; i++)
		{
			lef[i] = i - 1;
			rig[i] = (i + 1) % (n + 1);
		}
		lef[0] = n;
		rig[0] = 1;
		int flag = 0;
	//	print_box();
		for (int i = 0; i < m; i++)
		{
			int cmd, x, y;
			scanf("%d", &cmd);
			if (cmd == 4)
				flag = !flag;
			else
			{
				scanf("%d%d", &x, &y);
				if (flag&&cmd!=3) cmd = 3 - cmd;
				if (cmd == 1 && rig[x] == y)	continue;
				if (cmd == 2 && lef[x] == y)	continue;
				if (cmd == 3 && rig[y] == x) swap(x, y);
				int ly = lef[y], ry = rig[y];
				int lx = lef[x], rx = rig[x];
				//特殊处理
				if (cmd == 1)
				{
					link(lx, rx); link(ly, x); link(x, y);
				}
				else if (cmd == 2)
				{
					link(lx, rx); link(y, x); link(x, ry);
				}
				else if (cmd == 3)
				{
					if (rig[x] == y)
					{
						link(lx, y); link(y, x); link(x, ry);
					}
					else
					{
						link(lx, y); link(y, rx); link(ly, x); link(x, ry);
					}
				}
			}
		//	print_box();
		//	cout << endl;
		}

		long long ans = 0;
		int cur = 0;
		for (int i = 1; i <= n; i++)
		{
			cur = rig[cur];
			if (i % 2 != 0)
				ans += cur;
		}
		if (flag && (n % 2 == 0))	ans = (long long)n*(n + 1) / 2 - ans;
		printf("Case %d: %lld\n", ++kase, ans);
	}
	return 0;
}