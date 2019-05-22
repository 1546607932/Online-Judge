#include<iostream>
#include<algorithm>
using namespace std;

int a[6], b[6];
pair<int, int> p[6];

int judge()
{
	for (int i = 0; i < 3; i++)
		if (p[2 * i] != p[2 * i + 1])
			return 0;
	for (int i = 0; i < 3; i++)
		if (p[i].first != p[i + 1].first)
			return 0;
	for (int i = 0; i < 3; i++)
		if (p[i + 2].second != p[i + 3].second)
			return 0;
	if ((p[4].first != p[5].first) || (p[5].first != p[0].second) || (p[0].second != p[1].second))
		return 0;
	return 1;
}
int main()
{
	while (1)
	{
		for (int i = 0; i < 6; i++)
		{
			if (cin >> a[i] >> b[i])
				if (a[i] > b[i])
				{
					int temp;
					temp = a[i];
					a[i] = b[i];
					b[i] = temp;
				}
				else;
			else
				return 0;
			p[i].first = a[i];
			p[i].second = b[i];
		}
		sort(p, p + 6);
			if (judge())
				cout << "POSSIBLE" << endl;
			else
				cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}