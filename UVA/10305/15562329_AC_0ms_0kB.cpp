#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100 + 5;
int n, m;
int G[maxn][maxn], vis[maxn], total;
int topo[maxn];
int dfs(int u)
{
	vis[u] = -1;
	for (int v = 0; v < n; v++)
		if (G[u][v])
			if (vis[v] == -1)	return false;
			else if (!vis[v]) dfs(v);
	vis[u] = 1; topo[--total] = u;
	return 1;
}
int toposort()
{
	total = n;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
		if (!vis[i])
			if (!dfs(i))
				return false;
	return true;
}
int main()
{
	while (scanf("%d%d", &n, &m) == 2 && n)
	{
		int u, v;
		memset(G, 0, sizeof(G));
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &u, &v);
			u--; v--;
			G[u][v] = 1;
		}

		if (toposort())
		{
			for (int i = 0; i < n - 1; i++)
				cout << topo[i] + 1 << ' ';
			cout << topo[n - 1] + 1 << endl;
		}
	}
	return 0;
}
