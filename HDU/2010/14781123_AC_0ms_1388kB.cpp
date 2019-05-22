#include<iostream>
using namespace std;
int judge(int n)
{
	int temp = n;
	int a, b, c;
	a = n / 100;
	n -= a * 100;
	b = n / 10;
	n -= b * 10;
	c = n;
	return a * a*a + b * b*b + c * c*c == temp;
}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int flag2 = 1;
		int flag = 1;
		for (int i = m; i <= n; i++)
		{
			if (judge(i))
			{
				if (flag2)
					cout << i;
				else
					cout << ' ' << i;
				flag2 = 0;
				flag = 0;
			}
			if (i == n && !flag)
				cout << endl;
		}
		if (flag)
			cout << "no" << endl;
	}
	return 0;
}