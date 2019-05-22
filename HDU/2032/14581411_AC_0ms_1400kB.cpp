#include<iostream>
#include<string>
using namespace std;
int yanghui[40][50];
void trangle()
{
	yanghui[0][0] = 1;
	for (int i = 1; i < 40; i++)
	{
		yanghui[i][0] = 1;
		yanghui[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			yanghui[i][j] = yanghui[i - 1][j] + yanghui[i - 1][j - 1];
		}
	}
}
int main()
{
	int n;
	trangle();
	while (cin >> n)
	{
		static int count = 0;
/*		if (count++)
			cout << endl;*/
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
				cout << yanghui[i][j] << ' ';
			cout << yanghui[i][i] << endl;
		}
		cout << endl;
	}

	return 0;
}