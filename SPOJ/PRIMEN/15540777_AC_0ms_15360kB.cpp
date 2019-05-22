#include<iostream>
#include<cmath>
using namespace std;
int list[1000 + 5];
void get_list()
{
	for (int i = 2; i < 1000 + 5; i++)
		if (!list[i])
			for (int j = i * i; j < 1000 + 5; j += i)
				list[j] = 1;
}
int main()
{
	get_list();
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			if (!list[i])
				cout << i << endl;
		if (T)
			cout << endl;
	}
	return 0;
}