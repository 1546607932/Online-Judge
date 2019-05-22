#include<iostream>
#include<string>
#include<queue>
using namespace std;
int cou = 0;
queue<string> name[1000];
int main()
{
	string o, n;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int flag = -1;
		cin >> o >> n;
		for (int i = 0; i < cou; i++)
			if (name[i].back()==o)
			{
				flag = i;
				break;
			}
		if (flag == -1)
		{
			name[cou].push(o);
			name[cou].push(n);
			cou++;
		}
		else
			name[flag].push(n);
	}

	cout << cou << endl;
	for (int i = 0; i < cou; i++)
	{
		cout << name[i].front() << ' ' << name[i].back() << endl;
	}
	return 0;
}