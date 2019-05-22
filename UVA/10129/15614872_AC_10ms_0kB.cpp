#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 26 + 5;
const char* no = "The door cannot be opened.\n";
const char* yes = "Ordering is possible.\n";
int sx, sy;
int graph[maxn][maxn];
int in[maxn],out[maxn];
void get_graph(int n)
{
	memset(graph, 0, sizeof(graph));
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));

	char temp[1005];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", temp);
		sx = temp[0] - 'a';
		sy = temp[strlen(temp) - 1] - 'a';
		graph[sx][sy]++;
		in[sx]++;
		out[sy]++;
	}
}
void dfs(int x, int y)
{
	graph[x][y]--;
	for (int i = 0; i < 26; i++)
		if (graph[y][i])
			dfs(y, i);
	for (int i = 0; i < 26; i++)
		if (graph[i][x])
			dfs(i, x);
}
bool degree()
{
	int flag_in = 0;
	int flag_out = 0;
	for (int i = 0; i < 26; i++)
		if (in[i] != out[i])
			if (in[i] - out[i] == 1)
				flag_in++;
			else if (in[i] - out[i] == -1)
				flag_out++;
			else
				return false;
	if ((flag_in==0&&flag_out==0)||(flag_in==1&&flag_out==1))
		return true;
	else
		return false;
}
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int flag = 0;
		int n;
		cin >> n;
		get_graph(n);
		dfs(sx, sy);
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				if (graph[i][j])
				{
					flag = 1;
					goto LOOP;
				}
	LOOP:
		if (flag == 1 || !degree())
			cout << no;
		else
			cout << yes;
	}
	return 0;
}