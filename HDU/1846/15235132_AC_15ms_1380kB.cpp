#include<iostream>
using namespace std;
int main()
{
	int kase;
	cin >> kase;
	while (kase--)
	{
		int n, m;
		cin >> n >> m;
		if (n % (m + 1) == 0)
			cout << "second" << endl;
		else
			cout << "first" << endl;
	}
	return 0;
}