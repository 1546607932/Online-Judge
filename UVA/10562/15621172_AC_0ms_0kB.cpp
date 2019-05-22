#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

const int maxs = 200 + 5;

char graph[maxs][maxs];
int n;

void get_graph()
{
	n = 0;
	while (1)
	{
		cin.getline(graph[n], maxs);
		if (graph[n][0] == '#') break;
		else	n++;
	}
}
void print_graph()
{
	for (int i = 0; i < n; i++)
		cout << graph[i] << endl;
}
void dfs(int r, int c)
{
	cout << graph[r][c];
	cout << '(';
	if (r + 1 < n&&graph[r + 1][c] == '|')
	{
		int left, right;
		for (left = c; left-1>=0&&graph[r + 2][left - 1] == '-'; left--);
		for (right = c; graph[r + 2][right + 1] == '-'; right++);

		for (int i = left; i <= right; i++)
			if (graph[r + 3][i] != '\0' && !isspace(graph[r + 3][i]))
				dfs(r + 3, i);
			else if (graph[r + 3][i] == '\0')
				break;
//		for (int i=left; graph[r + 2][i] == '-'&&graph[r + 3][i] != '\0'; i++)
//		{
//			if (!isspace(graph[r + 3][i])) dfs(r + 3, i);
//		}
	}
	cout << ')';
}
void get_ans()
{
	cout << '(';

	int r = 0, c = 0;
	if (n)
	{
		for (int i = 0; i < strlen(graph[0]); i++)
			if (graph[0][i] != ' ')
			{
				c = i; break;
			}
		dfs(r, c);
	}
	cout << ')' << endl;
}

int main()
{
	//	freopen("d:\\sample.txt", "r", stdin);
	//	freopen("d:\\test.txt", "w", stdout);
	int T;
	cin >> T; getchar();
	while (T--)
	{
		get_graph();
		get_ans();
	}
	return 0;
}