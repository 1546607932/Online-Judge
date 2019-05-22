#include<iostream>
#include<algorithm>
using namespace std;
short table[100][100];
int sum[100][100];
int line[100];
const int INF = -100000000;
int main()
{
	int ans = INF;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%hd", &table[i][j]);	//输入信息

	for (int j = 0; j < N; j++)
		sum[0][j] = table[0][j];
	for (int i = 1; i < N; i++)
		for (int j = 0; j < N; j++)
			sum[i][j] = sum[i - 1][j] + table[i][j];

	for(int first=0;first<N;first++)		//对每一个矩形
		for (int second = first; second < N; second++)
		{
			for (int i = 0; i < N; i++)
				if (first)
					line[i] = sum[second][i] - sum[first - 1][i];
				else
					line[i] = sum[second][i];
			//二维化作一维
			int maxs = INF;
			int total = 0;
			for (int i = 0; i < N; i++)
			{
				total += line[i];
				if (total < 0)
					total = 0;
				maxs = max(maxs, total);
			}
			ans = max(ans, maxs);
		}
	cout << ans << endl;
	return 0;
}