#include<iostream>
using namespace std;
int n;
int main()
{
	while ((cin >> n) && n)
	{
		int temp;
		int accu = 0;
		unsigned long long total = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			accu += temp;
			total += abs(accu);
		}
		cout << total << endl;
	}
	return 0;
}