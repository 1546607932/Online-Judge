#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 500000 + 5;
int a[maxn], b[maxn];
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int n;
	while ((cin >> n)&&n)
	{
		int flag = 1;
		for (int i = 0; i < n; i++)
			scanf("%d%d", &a[i], &b[i]);
		sort(a, a + n);
		sort(b, b + n);
		for(int i=0;i<n;i++)
			if (a[i] != b[i])
			{
				flag = 0;
				break;
			}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}