#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 200000 + 5;
const int maxa = 100000 + 5;

int skill[maxn];
int bit[maxa];
int a[maxn], b[maxn];
int n;

inline int lowbit(int x)
{
	return x & -x;
}
int sum(int x)
{
	int ans = 0;
	while (x > 0)
	{
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}
void add(int x, int d = 1)
{
	while (x <= maxa)
	{
		bit[x] += d;
		x += lowbit(x);
	}
}

int main()
{
//	freopen("d:\\sample.in", "r", stdin);
//	freopen("d:\\test.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			scanf("%d", &skill[i]);

		memset(bit, 0, sizeof(bit));
		for (int i = 1; i <= n; i++)
		{
			a[i] = sum(skill[i] - 1);
			add(skill[i]);
		}
		memset(bit, 0, sizeof(bit));
		for (int i = n ; i >= 1; i--)
		{
			b[i] = sum(skill[i] - 1);
			add(skill[i]);
		}

		long long ans = 0;
		for (int i = 2; i <= n; i++)
			ans += a[i] * (n - i - b[i]) + b[i] * (i - 1 - a[i]);
		cout << ans << endl;
	}
	return 0;
}