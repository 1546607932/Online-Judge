#include<iostream>
using namespace std;
const int MAX_M = 20, MAX_N = 20;
char tab[MAX_M][MAX_N];
int m, n;
int sum;
pair<int, int> p[4];
void dfs(int a, int b)
{
	if (tab[a][b] == '.' || tab[a][b] == '@')
	{
		tab[a][b] = '#';
		sum++;
		int nx, ny;
		for (int i = 0; i < 4; i++)
		{
			nx = a + p[i].first, ny = b + p[i].second;
			if (nx >= 0 && nx < m&&ny >= 0 && ny < n)
				dfs(nx, ny);
		}
	}
}
int main()
{
	int a1[4] = { 1,0,-1,0 };
	int a2[4] = { 0,1,0,-1 };
	for (int i = 0; i < 4; i++)
	{
		p[i].first = a1[i];
		p[i].second = a2[i];
	}
	do
	{
		sum = 0;
		scanf("%d%d", &n, &m);
		if (m != 0 && n != 0)
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					cin >> tab[i][j];
		else
			break;

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (tab[i][j] == '@')
				{
					dfs(i, j);
					printf("%d\n", sum);
					break;
				}
	} while (1);
	return 0;
}