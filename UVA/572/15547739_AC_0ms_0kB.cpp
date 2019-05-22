#include<iostream>
#include<cstring>
using namespace std;
const int maxm = 100;
const int maxn = 100;
char oil[maxm][maxn];
int id[maxm][maxn];
int m, n;
inline int judge(int r,int c)
{
	return (r >= 0 && r < m) && (c >= 0 && c < n);
}
void dfs(int r, int c, int iden)
{
	if (oil[r][c] == '@'&&id[r][c] == 0)
	{
		id[r][c] = iden;
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
				if ((i || j) && judge(r + i, c + j))
					dfs(r + i, c + j, iden);
	}
}
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	while ((cin >> m >> n) && m&&n)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> oil[i][j];
		memset(id, 0, sizeof(id));

		int cnt = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (oil[i][j] == '@'&&id[i][j] == 0)
					dfs(i, j, ++cnt);
		cout << cnt << endl;
	}
	return 0;
}