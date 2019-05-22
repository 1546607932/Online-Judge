#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;
const int INF = 10000000;
const int maxn = 10000 + 10;
int lch[maxn], rch[maxn];
int in_order[maxn], post_order[maxn];
int n = 0;
bool read_input(int* a)
{
	string temp;
	if (!getline(cin,temp))	return false;
	stringstream line(temp);
	n = 0;
	while (line >> a[++n]);
	return n > 0;
}
int built(int L1, int R1, int L2, int R2)
{
	if (L1 > R1)	return false;
	int root = post_order[R2];
	int p = L1;
	while (in_order[p] != root) p++;
	int cnt = p - L1;
	lch[root] = built(L1, p - 1, L2, L2 + cnt - 1);
	rch[root] = built(p + 1, R1, L2 + cnt, R2 - 1);
	return root;
}
int best, best_sum;
void dfs(int u, int sum)
{
	sum += u;
	if (!lch[u] && !rch[u])
	{
		if (sum < best_sum || ((sum == best_sum) && u < best))
		{
			best = u;
			best_sum = sum;
		}
	}
	if (lch[u]) dfs(lch[u], sum);
	if (rch[u]) dfs(rch[u], sum);
}
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	while (read_input(in_order))
	{
		read_input(post_order);
		memset(lch, 0, sizeof(lch));
		memset(rch, 0, sizeof(rch));
		built(1, n - 1, 1, n - 1);
		best_sum = INF;
		dfs(post_order[n - 1], 0);
		cout << best << endl;
	}
	return 0;
}