#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;

struct Node
{
	int i;
	int j;
	int dir;
	Node(int i = 0, int j = 0, int dir = 0) :i(i), j(j), dir(dir) {}
};
bool operator!=(const Node& a, const Node& b)
{
	return a.i != b.i||a.j != b.j||a.dir != b.dir;
}
const int maxn = 10;
const int INF = 10000000;
const int di[] = { -1,0,1,0 };
const int dc[] = { 0,1,0,-1 };
const char* direction = "NESW";
const char* turn = "LFR";
const char* no_ans = "  No Solution Possible\n";

inline int direction_to_num(char ch)
{
	return strchr(direction, ch) - direction;
}
inline int turn_to_num(char ch)
{
	return strchr(turn, ch) - turn;
}

string maze_name;
int r0, c0, dir;
int r1, c1;
int rf, cf;
int graph[maxn][maxn][4][3];
int vis[maxn][maxn][4];
int step[maxn][maxn][4];
Node pre[maxn][maxn][4];

bool ReadInput()
{
	memset(vis, -1, sizeof(vis));
	memset(step, 0, sizeof(step));
	memset(graph, 0, sizeof(graph));
	cin >> maze_name;
	char temp_dir;
	if (maze_name == "END")	return false;
	cin >> r0 >> c0 >> temp_dir;
	r1 = r0, c1 = c0;
	r0 += di[direction_to_num(temp_dir)];
	c0 += dc[direction_to_num(temp_dir)];
	dir = direction_to_num(temp_dir);
	cin >> rf >> cf;
	int r, c;
	while (1)
	{
		scanf("%d", &r);
		if (r == 0)	break;
		scanf("%d", &c);
		while (1)
		{
			char temp[20];
			scanf("%s", temp);
			if (temp[0] == '*')	break;
			for(int i=1;i<strlen(temp);i++)
				graph[r][c][direction_to_num(temp[0])][turn_to_num(temp[i])] = 1;
		}
	}
	return true;
}
bool InRange(int i,int j)
{
	return i > 0 && i < 10 && j>0 && j < 10;
}

Node go(Node beg,int dir)
{
	beg.dir = (beg.dir + dir - 1 + 4) % 4;
	beg.i += di[beg.dir];
	beg.j += dc[beg.dir];
	return beg;
}
void bfs()
{
	queue<Node> que;
	que.push(Node(r0, c0, dir));
	step[r0][c0][dir] = 1;
	Node now;
	while (!que.empty())
	{
		now = que.front(); que.pop();
		vis[now.i][now.j][now.dir] = 1;
		for (int i = 0; i < 3; i++)
			if (graph[now.i][now.j][now.dir][i])
			{
				Node newnode = go(now, i);
				if (InRange(newnode.i, newnode.j) && vis[newnode.i][newnode.j][newnode.dir] == -1)
				{
					que.push(newnode);
					pre[newnode.i][newnode.j][newnode.dir] = now;
					step[newnode.i][newnode.j][newnode.dir] = step[now.i][now.j][now.dir] + 1;
				}
			}
	}
}
void print_ans()
{
	stack<Node> ans;
	cout << maze_name << endl;
	int m = INF;
	int which;
	for (int i = 0; i < 4; i++)
		if (step[rf][cf][i] != 0 && step[rf][cf][i] < m)
		{
			m = step[rf][cf][i];
			which = i;
		}
	
	if (m == INF)
		cout << no_ans;
	else
	{
		Node now(rf,cf,which);
		ans.push(Node(rf, cf, which));
		while (now != Node(r0, c0, dir))
		{
			now = pre[now.i][now.j][now.dir];
			ans.push(now);
		}
		ans.push(Node(r1, c1, dir));
		int count = 0;
		cout << " ";
		while (!ans.empty())
		{
			while ( ++count % 11 == 0)
				cout << '\n' << " ";
			printf(" (%d,%d)", ans.top().i, ans.top().j);
			ans.pop();
		}
		cout << endl;
	}

}
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	while (ReadInput())
	{
		bfs();
		print_ans();
	}

	return 0;
}