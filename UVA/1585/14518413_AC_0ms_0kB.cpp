#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;

	for (int k = 0; k < n; k++)
	{
		string a;
		int sum = 0, count = 0;
		cin >> a;
		for (int i = 0; i < a.length(); i++)
			if (a[i] == 'O')
			{
				count++;
				sum += count;
			}
			else
				count = 0;
		cout << sum << endl;
	}
	return 0;
}