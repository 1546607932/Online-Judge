#include<iostream>
using namespace std;
int aim[100005];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < m; i++)
			cin >> aim[i];

		_int64 total = 0;
		int now = 1;
		for (int i = 0; i < m; i++)
		{
			if (aim[i] >= now)
			{
				total += aim[i] - now;
				now = aim[i];
			}
			else
			{
				total += aim[i] + n - now;
				now = aim[i];
			}
		}
		cout << total << endl;
	}
	return 0;
}