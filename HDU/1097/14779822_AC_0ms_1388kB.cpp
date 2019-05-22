#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int c[15];
	int a, b;
	while (cin >> a >> b)
	{
		memset(c, 0, sizeof(c));
		a %= 10;
		int count = 0;
		int temp = a;
		while (1)
		{
			if (c[temp % 10])
				break;
			count++;

			c[temp % 10]++;
			temp *= a;
			temp %= 10;
		}
		if (count)
		{
			b %= count;
			b += count;
		}
		else
			b = 1;
		temp = a;
		for (int i = 0; i < b-1; i++)
		{
			temp *= a;
			temp %= 10;
		}
		cout << temp << endl;
	}
	return 0;
}