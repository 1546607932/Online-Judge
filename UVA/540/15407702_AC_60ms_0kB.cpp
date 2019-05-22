#include<iostream>
#include<queue>
#include<map>
using namespace std;
int main()
{
	//	freopen("d:\\sample.txt", "r", stdin);
	//	freopen("d:\\test.txt", "w", stdout);
	int kase = 0;
	int team_num;
	while ((cin >> team_num) && team_num)
	{
		//输入队伍人员
		queue<int> all, team[1000];
		map<int, int> belong;
		for (int i = 0; i < team_num; i++)
		{
			int num;
			cin >> num;
			for (int j = 0; j < num; j++)
			{
				int temp;
				scanf("%d", &temp);
				belong[temp] = i;
			}
		}

		printf("Scenario #%d\n", ++kase);
		char temp[10];
		while (cin >> temp)
		{
			if (temp[0] == 'E')
			{
				int t;
				scanf("%d", &t);
				if (team[belong[t]].empty())
				{
					team[belong[t]].push(t);
					all.push(belong[t]);
				}
				else
				{
					team[belong[t]].push(t);
				}
			}
			else if (temp[0] == 'D')
			{
				int num;
				int t = all.front();
				num = team[t].front();
				if (team[t].size() == 1)
				{
					all.pop();
					team[t].pop();
				}
				else
				{
					team[t].pop();
				}
				cout << num << endl;
			}
			else
				break;
		}
		cout << endl;
	}
	return 0;
}