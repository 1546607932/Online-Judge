#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int cou[10];
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		memset(cou, 0, sizeof(cou));
		int n;
		int pos;
		queue<int> line;
		int temp;
		cin >> n >> pos;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			line.push(temp);
			cou[temp]++;
		}

		int max;
		int time = 0;
		while (1)
		{
			for (int i = 9; i > 0; i--)
			{
				if (cou[i] != 0)
				{
					max = i;
					break;
				}
			}
			int first = line.front();
			if (first == max)
			{
				cou[max]--;
				line.pop();
				time++;
				if (pos == 0)
				{
					cout << time << endl;
					break;
				}
				else
					pos--;
				n--;
			}
			else
			{
				line.pop();
				line.push(first);
				pos--;
				if (pos == -1)
					pos = n - 1;
			}
		}
	}
	return 0;
}