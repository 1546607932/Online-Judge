#include<iostream>
#include<map>
#include<set>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
map<int, string> trans;
const int maxh = 200 + 5;
const int maxw = 50 * 8 + 5;
const int INF = 10000000;
int h, w;
int graph[maxh][maxw];
int vis[maxh][maxw];
const int dh[] = { 1,0,-1,0 };
const int dc[] = { 0,1,0,-1 };
const char to_ans[] = "WAKJSD";
void init()
{
	trans['0'] = "0000";	trans['1'] = "0001";
	trans['2'] = "0010";	trans['3'] = "0011";
	trans['4'] = "0100";	trans['5'] = "0101";
	trans['6'] = "0110";	trans['7'] = "0111";
	trans['8'] = "1000";	trans['9'] = "1001";
	trans['a'] = "1010";	trans['b'] = "1011";
	trans['c'] = "1100";	trans['d'] = "1101";
	trans['e'] = "1110";	trans['f'] = "1111";
}
void get_graph()
{
	char temp;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			scanf("%c", &temp);
			graph[i][4 * j] = trans[temp][0]-'0';
			graph[i][4 * j + 1] = trans[temp][1]-'0';
			graph[i][4 * j + 2] = trans[temp][2]-'0';
			graph[i][4 * j + 3] = trans[temp][3]-'0';
		}
		getchar();
	}
}
void print_graph()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w * 4; j++)
			printf("%3d", graph[i][j]);
		cout << endl;
	}
}
void dfs_get(int h, int c, int cnt)
{
	if (graph[h][c] == 0&& h>= 0 && h< ::h&&c>= 0 && c< 4 * w)
	{
		graph[h][c] = cnt;
		for (int i = 0; i < 4; i++)
			if (h + dh[i] >= 0 && h+dh[i] < ::h&&c+dc[i] >= 0 && c+dc[i] < 4 * w)
				dfs_get(h + dh[i], c + dc[i], cnt);
	}
}
void get_number()
{
	int cnt = 10;
	for(int i=0;i<h;i++)
		for(int j=0;j<4*w;j++)
			if(graph[i][j]==0)
				dfs_get(i, j, ++cnt);
}

set<int> ed;
int hole = 0;
void dfs(int h, int c)
{

	vis[h][c] = 1;
	if (graph[h][c]!=INF&&(ed.find(graph[h][c]) == ed.end()))
	{
		hole++;
		ed.insert(graph[h][c]);
	}
	if (graph[h][c] == 1)
		for (int i = 0; i < 4; i++)
			if (h + dh[i] >= 0 && h + dh[i] < ::h&&c + dc[i] >= 0 && c + dc[i] < 4 * w&&!vis[h+dh[i]][c+dc[i]])
				dfs(h + dh[i], c + dc[i]);
}
void dfs2(int h,int c)
{
	if (graph[h][c] == 0)
	{
		graph[h][c] = INF;
		for (int i = 0; i < 4; i++)
			if (h + dh[i] >= 0 && h + dh[i] < ::h&&c + dc[i] >= 0 && c + dc[i] < 4 * w && !vis[h + dh[i]][c + dc[i]])
				dfs2(h + dh[i], c + dc[i]);
	}
}
string get_ans()
{
//	print_graph();
	string ans;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < 4 * w; j++)
			if (graph[i][j] == 1 && !vis[i][j])
			{
				hole = 0;
				ed.clear();
				dfs(i, j);
				hole -= 1;
				ans += to_ans[hole];
			}
	sort(ans.begin(), ans.end());
	return ans;
}
void biankuang()
{
	for (int i = 0; i < 4 * w; i++)
	{
		if (graph[0][i] == 0)
			dfs2(0, i);
		if (graph[h - 1][i] == 0)
			dfs2(h - 1, i);
	}
	for (int i = 0; i < h; i++)
	{
		if (graph[i][0] == 0)
			dfs2(i, 0);
		if (graph[i][4 * w - 1] == 0)
			dfs2(i, 4 * w - 1);
	}
}
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int kase = 0;
	init();
	while (1)
	{
		cin >> h >> w;
		if (h == 0 && w == 0) break;
		getchar();
		memset(vis, 0, sizeof(vis));
		get_graph();
		biankuang();
		get_number();
//		print_graph();
		printf("Case %d: %s\n", ++kase, get_ans().c_str());
	}
	return 0;
}