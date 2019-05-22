#include<iostream>
using namespace std;
int main()
{
	long long aim;
	while (cin >> aim)
	{
		int flag = 0;
		if (aim > 0)
		{
			while (aim > 0)
			{
				if (aim % 10 > 0)
				{
					cout << aim % 10;
					flag = 1;
				}
				else if (flag)
					cout << 0;
				aim /= 10;
			}
		}
		else if (aim == 0)
			cout << 0 << endl;
		else
		{
			aim = -aim;
			cout << "-";	
			while (aim > 0)
			{
				if (aim % 10 > 0)
				{
					cout << aim % 10;
					flag = 1;
				}
				else if (flag)
					cout << 0;
				aim /= 10;
			}
		}
		cout << endl;
	}
	return 0;
}