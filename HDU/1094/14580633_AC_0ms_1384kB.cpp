#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			sum += temp;
		}
		cout << sum << endl;
	}
	return 0;
}