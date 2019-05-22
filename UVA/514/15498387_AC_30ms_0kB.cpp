#include<iostream>
#include<stack>
using namespace std;
const int maxl = 1000 + 5 ;
int coach[maxl];
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int n;
	int kase = 0;
	while (1)
	{
		if (kase++)
			cout << endl;
		cin >> n;
		if (!n)
			break;
		while (1)
		{
			stack<int> tran;
			int flag1 = 1;
			int flag2 = 1;
			int ok = 1;
			scanf("%d", &coach[0]);
			if (coach[0] == 0)
				break;
			else for (int i = 1; i < n; i++)
				scanf("%d", &coach[i]);
			//初始化信息
			for (int i = 0; i < n; i++)
			{
				if (!tran.empty() && tran.top() == coach[i])
					tran.pop();
				else
				{
					if (coach[i] < flag1)
					{
						ok = 0;
						break;
					}
					flag2 = coach[i];
					for (int i = flag1; i < flag2; i++)
						tran.push(i);
					flag1 = flag2 + 1;
				}
			}
			if (ok)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}