#include<iostream>
using namespace std;
int main()
{
	int i, n, a[1005] = { 1 }, b[1005] = { 0 };
	for (i = 1; i <= 1000; i++)
	{
		a[i] = (b[i - 1]) % 10000;
		b[i] = (a[i - 1] * 2 + b[i - 1]) % 10000;
	}
	while ((cin>>n) && n)
		printf("%d\n", a[n]);
	return 0;
}