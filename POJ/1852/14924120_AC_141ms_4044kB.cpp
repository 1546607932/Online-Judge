#include<cstdio>
const int max_n = 1000000;
int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
void solve()
{
	int L, n, Case;
	int x[max_n];
	
	scanf("%d", &Case);

	do
	{
		scanf("%d%d", &L,&n);

		for (int p = 0; p < n; p++)
			scanf("%d", &x[p]);

		int minT = 0;
		for (int i = 0; i < n; i++)
			minT = max(minT, min(x[i], L - x[i]));

		int maxT = 0;
		for (int i = 0; i < n; i++)
			maxT = max(maxT, max(x[i], L - x[i]));

		printf("%d %d\n", minT, maxT);
		Case--;
	} while (Case != 0);
}
int main(void)
{
	solve();
	return 0;
}