#include<iostream>
#include<set>
using namespace std;
int aim[1000000+5];
set<int> snow;
int main()
{
	int kase, n;
	cin >> kase;
	while (kase--)
	{
		snow.clear();
		cin >> n;
		for (int i = 0; i < n; i++)
			scanf("%d", &aim[i]);
		
		int L = 0, R = 0;
		int ma = 0;
		int max = 0;
		while (R<n)
		{
			if (snow.find(aim[R]) == snow.end())
			{
				snow.insert(aim[R++]);
				ma++;
				max = max > ma ? max : ma;
			}
			else
			{
				while (aim[L] != aim[R])
				{
					snow.erase(aim[L]);
					ma--;
					L++;
				}
				snow.erase(aim[L]);
				ma--;
				L++;
			}
		}
		cout << max << endl;
	}
	return 0;
}