#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int j=0;j<n;j++)
	{
		int times;
		cin >> times;
		int sum = 0;
		for (int i = 0; i < times; i++)
		{
			int temp;
			cin >> temp;
			sum += temp;
		}
		cout << sum << endl;
	}
	return 0;
}