#include<iostream>
using namespace std;
int condi[12];
int abt[12][4];
int judge(int n)
{
	int flag = 1;
	for (int i = 0; i < n; i++)
		if (condi[i] == 1)
			return 1;
	return 0;
}
int main()
{
	int a = 1;
	int n;
	while (cin >> n&&n)
	{
		int max = 1;
		int count = 0;
		int time = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> abt[i][0] >> abt[i][1] >> abt[i][2];
			abt[i][3] = abt[i][0] + abt[i][1];
		}
		for (int i = 0; i < n; i++)
			max *= abt[i][3];
		while (++time)
		{
			if (count++ > max)
				break;
			for (int i = 0; i < n; i++)
			{
				if ((time - 1 + abt[i][2]) % abt[i][3] <= abt[i][0]&& ((time - 1 + abt[i][2]) % abt[i][3])>0)
					condi[i] = 0;//醒着
				else
					condi[i] = 1;
			}
			int sleep = 0;
			for (int i = 0; i < n; i++)
				if (condi[i] == 1)
					sleep++;
			if (n - sleep >= sleep)
				break;
		}
		while (judge(n)&&time++)
		{
			for(int i=0;i<n;i++)
				if(condi[i]==1)
					if ((time - 1 + abt[i][2]) % abt[i][3] <= abt[i][0] && ((time - 1 + abt[i][2]) % abt[i][3])>0)
						condi[i] = 0;//醒着
		}
		cout << "Case " << a++ << ": ";
		if (count > max)
			cout << -1 << endl;
		else
			cout << time << endl;
	}
	return 0;
}