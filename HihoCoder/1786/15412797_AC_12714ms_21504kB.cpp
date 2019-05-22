#include<iostream>
#include<algorithm>
using namespace std;
int stone[200006];
int step[200006];
const int INF = 100000000;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &stone[i]);	//输入信息

	for (int i = 0; i <= n; i++)
		step[i] = INF;
	step[1] = 0;		//初始化步数表格

	for (int i = 1; i < n; i++)
	{
		step[i + 1] = min(step[i + 1], step[i] + 1);
		for(int k=i+1;k<=n;k++)
			if (stone[k] == stone[i])
			{
				step[k] = min(step[k], step[i] + 1);
				break;
			}
	}
	cout << step[n] << endl;
	return 0;
}