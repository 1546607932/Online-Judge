#include<iostream>
using namespace std;
int main()
{
	int n;
	while ((cin >> n) && n != 0)
	{
		int sum = 0;
		int temp;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			sum += temp;
		}
		cout << sum << endl;
	}
	return 0;
}