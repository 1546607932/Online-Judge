#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 8;
int graph[maxn][maxn];
int br, bc;
int dr, dc;
typedef pair<int, int> p;
const int Dr[] = { -2,-1,1,2,2,1,-1,-2 };
const int Dc[] = { 1,2,2,1,-1,-2,-2,-1 }; 
inline bool InRange(int r,int c)
{
	return r >= 0 && r < maxn && c >= 0 && c < maxn;
}
void print_graph()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			printf("%3d", graph[i][j]);
		cout << endl;
	}
}
void bfs(int r, int c)
{
	memset(graph, -1, sizeof(graph));
	graph[r][c] = 0;
	queue<p> que;
	que.push(p(r, c));
	while (!que.empty())
	{
		int r = que.front().first;
		int c = que.front().second;
		que.pop();
		for (int i = 0; i < 8; i++)
			if (InRange(r + Dr[i], c + Dc[i]) && graph[r + Dr[i]][c + Dc[i]] ==-1)
			{
				que.push(p(r + Dr[i], c + Dc[i]));
				graph[r + Dr[i]][c + Dc[i]] = graph[r][c] + 1;
			}
//		print_graph();
//		system("pause");
	}
}

int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	char pos[30];
	while (cin.getline(pos, 20))
	{
		bc = pos[0] - 'a'; br = pos[1] - '1';
		dc = pos[3] - 'a'; dr = pos[4] - '1';
		bfs(br, bc);
		printf("To get from %c%d to %c%d takes %d knight moves.\n",bc+'a',br+1,dc+'a',dr+1,graph[dr][dc]);
	}
	return 0;
}