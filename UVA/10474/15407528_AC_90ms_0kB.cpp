#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10000 + 5;
int marble[maxn];
int gue[maxn];
int main()
{
	int N, M;
	int kase = 0;
	while (cin >> N >> M&&N&&M)
	{
		for (int i = 0; i < N; i++)
			cin >> marble[i];
		for (int i = 0; i < M; i++)
			cin >> gue[i];
		sort(marble, marble + N);

		printf("CASE# %d:\n", ++kase);
		for (int i = 0; i < M; i++)
		{
			int p = lower_bound(marble, marble + N, gue[i]) - marble;
			if (marble[p] == gue[i])
				printf("%d found at %d\n", gue[i], p + 1);
			else
				printf("%d not found\n", gue[i]);
		}
	}
	return 0;
}