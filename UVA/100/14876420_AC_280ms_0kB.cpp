#include<iostream>
using namespace std;
int function(int i)
{
	int count = 1;
	while (i != 1)
	{
		if (i % 2 == 0)
			i /= 2;
		else
			i = 3 * i + 1;
		count++;
	}
	return count;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		int flag = 1;
		if (a > b)
		{
			flag = 0;
			swap(a, b);
		}
		int max = 0;
		for (int i = a; i <= b; i++)
		{
			if (function(i) > max)
				max = function(i);
		}
		if (flag)
			cout << a << ' ' << b << ' ' << max << endl;
		else
			cout << b << ' ' << a << ' ' << max << endl;
	}
	return 0;
}