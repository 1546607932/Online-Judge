#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int aim[1005];
	for (int i = 0; i < 1005; i++)
		aim[i] = i + 1;
	
	int n, m;
	while (cin >> n >> m)
	{
		sort(aim, aim + 1000);
		for (int i = 0; i < m-1; i++)
			next_permutation(aim, aim + n);
		for (int i = 0; i < n-1; i++)
			cout << aim[i] << ' ';
		cout << aim[n - 1] << endl;
	}
	return 0;
}