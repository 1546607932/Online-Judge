#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int thing[100005];
int indi[100005];
int main()
{
	int kase;
	int A = 0;
	cin >> kase;
	while (kase--)
	{
		memset(indi, 0, sizeof(indi));
		if (A++)
			cout << endl;
		int n,len;
		cin >> n >> len;
		for (int i = 0; i < n; i++)
			scanf("%d", &thing[i]);
		sort(thing, thing + n);
		//完成输入
		int Fir=0, Sec=n;//首位置
		Sec = upper_bound(thing, thing + n, len - thing[Fir]) - thing;
		if (Sec >= n)
			Sec--;
		int end = Sec;
		for (Fir = 0; Fir < Sec;)
			if (thing[Fir] + thing[Sec] <= len)
			{
				indi[Fir++] = indi[Sec--] = 1;
			}
			else
				Sec--;

		int total = 0;
		int sum = 0;
		for (int i = 0; i < end; i++)
			if (indi[i] == 1)
				sum++;
			else
				total++;
		total += sum / 2 + n - end;
		cout << total << endl;
	}
	return 0;
}