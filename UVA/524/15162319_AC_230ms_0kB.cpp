#include<iostream>
#include<cmath>
using namespace std;
int n;
int A[20] = { 1 };
int vis[20];
int is_prime(int n)
{
	double a = sqrt(n);
	for (int i = 2; i <= round(a); i++)
		if (n%i == 0)
			return 0;
	return 1;
}
void dfs(int cur)
{
	if (cur == n && is_prime(A[0] + A[n - 1]))
	{
		for (int i = 0; i < n - 1; i++)
			cout << A[i] << ' ';
		cout << A[n - 1] << endl;
	}
	else
		for (int i = 2; i <= n; i++)
		{
			if (!vis[i] && is_prime(A[cur - 1] + i))
			{
				A[cur] = i;
				vis[i] = 1;
				dfs(cur + 1);
				vis[i] = 0;
			}
		}
}
int main()
{
	int kase = 0;
	while (cin >> n)
	{
		if (kase)
			cout << endl;
		printf("Case %d:\n", ++kase);
		dfs(1);
	}
	return 0;
}