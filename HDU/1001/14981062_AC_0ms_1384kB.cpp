#include<iostream>
using namespace std;
int main()
{
	int n, sum;
	while (cin >> n)
	{
		sum = 0;
		for (int i = 0; i <= n; i++)
			sum += i;
		cout << sum << endl << endl;
	}
	return 0;
}