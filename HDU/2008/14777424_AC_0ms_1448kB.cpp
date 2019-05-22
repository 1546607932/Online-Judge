#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n && n)
	{
		double temp;
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			if (temp > 0)
				a++;
			else if (temp < 0)
				c++;
			else
				b++;
		}
		cout << c << ' ' << b << ' ' << a << endl;
	}
	return 0;
}