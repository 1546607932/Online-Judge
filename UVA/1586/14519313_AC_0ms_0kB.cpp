#include<iostream>
#include<string>
using namespace std;
double judge(char t)
{
	if (t == 'C')	return 12.01;
	if (t == 'H')	return 1.008;
	if (t == 'O')	return 16.00;
	if (t == 'N')	return 14.01;
	return 0;
}
int main()
{
	int T;
	string a;
	cin >> T;
	for (int TEST = 0; TEST < T; TEST++)
	{
		double sum = 0;
		cin >> a;
		int num = 0;
		for (unsigned i = 0; i < a.length(); i++)
		{
			num = 0;
			if (isalpha(a[i]))
				if (isdigit(a[i + 1]))
				{
					num += a[i + 1] - '0';
					if (isdigit(a[i + 2]))
					{
						num = a[i + 2] - '0';
						num += 10 * (a[i + 1] - '0');
					}
				}
				else
					num = 1;
			sum += num * judge(a[i]);
		}
		printf("%.3f\n", sum);
	}
	return 0;
}