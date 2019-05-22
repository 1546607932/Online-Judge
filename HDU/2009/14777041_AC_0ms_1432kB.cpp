#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double n;
	int m;
	while (cin >> n >> m)
	{
		double total = 0;
		for (int i = 0; i < m; i++)
		{
			total += n;
			n = sqrt(n);
		}
		printf("%.2f\n", total);
	}
	return 0;
}