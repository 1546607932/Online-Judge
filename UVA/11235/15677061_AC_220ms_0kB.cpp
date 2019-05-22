//Range Maximum Query
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100000 + 5;
const int INF = 2000000000;

pair<int, int> p[maxn];
int n, q;
int num[maxn], lef[maxn], rig[maxn];
int ma[maxn][30];
int cur = 0;

void RMQ_init()
{
	for (int i = 0; i < cur; i++)
		ma[i][0] = p[i].second;
	for (int j = 1; (1 << j) <= cur; j++)
		for (int i = 0; i + (1 << j) <= cur; i++)
			ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
}
int RMQ(int L, int R)
{
	if (L > R)
		return 0;
	int k = 0;
	while ((1 << (k + 1)) <= R - L + 1) k++;
	return max(ma[L][k], ma[R - (1 << k) + 1][k]);
}

bool get_table()
{
	cin >> n;
	if (n == 0) return false;
	cin >> q;
	int now = INF,number;
	cur = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &number);
		if (number == now)
		{
			p[cur].second++;
			num[i] = cur;
		}
		else
		{
			rig[cur] = i - 1;
			cur++;
			p[cur].first = number;
			p[cur].second = 1;
			num[i] = cur;
			if (p[cur].second == 1)
			{
				lef[cur] = i;
				now = number;
			}
		}
	}
	rig[cur] = n;
	RMQ_init();
	return true;
}
void query()
{
	while (q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (num[a] == num[b])
		{
			cout << b - a + 1 << endl;
			continue;
		}
		int num1, num2, num3;
		num1 = rig[num[a]] - a + 1;
		num2 = RMQ(num[a] + 1, num[b] - 1);
		num3 = b - lef[num[b]] + 1;
		cout << max(max(num1, num2), num3) << endl;
	}
}

int main()
{
//	freopen("d:\\sample.in", "r", stdin);
//	freopen("d:\\test.out", "w", stdout);
	while (get_table())
		query();
	return 0;
}