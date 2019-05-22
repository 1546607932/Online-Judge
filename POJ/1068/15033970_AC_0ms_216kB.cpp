#include<iostream>
#include<string>
using namespace std;
string aim;
int cou = 0;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		aim.clear();
		cou = 0;
		int total;
		int temp;
		cin >> total;
		while (total--)
		{
			cin >> temp;
			if (cou < temp)
			{
				for (int i = cou; i < temp; i++)
				{
					aim += '(';
					cou++;
				}
				aim += ')';
			}
			else
				aim+=')';
		}
		int sz = aim.length();
		for(int i=0;i<sz;i++)
			if (aim[i] == ')')
			{
				for (int j = i - 1; j >= 0; j--)
					if (aim[j] == '(')
					{
						if (i != sz - 1)
							cout << (i - 1 - j) / 2 + 1 << ' ';
						else
							cout << (i - 1 - j) / 2 + 1 << endl;
						aim[i] = ' ';
						aim[j] = ' ';
						break;
					}
			}
	}
	return 0;
}