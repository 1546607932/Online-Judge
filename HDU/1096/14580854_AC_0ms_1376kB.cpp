#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int count;
		int sum = 0;
		int temp;
		cin >> count;
		while (count--)
		{
			cin >> temp;
			sum += temp;
		}
		if (i != n - 1)
			cout << sum << endl << endl;
		else
			cout << sum << endl;
	}
	return 0;
}