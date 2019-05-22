#include<iostream>
#include<cstring>
using namespace std;
int times[10];
int main()
{
	int T;
	cin >> T;
	for (int z = 0; z < T; z++)
	{
		memset(times, 0,sizeof(times));
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int now=i;
			while (now!= 0)
			{
				int temp;
				temp = now % 10;
				times[temp]++;
				now /= 10;
			}
		}
		for (int i = 0; i < 9; i++)
			cout << times[i] << ' ';
		cout << times[9] << endl;
	}
	return 0;
}