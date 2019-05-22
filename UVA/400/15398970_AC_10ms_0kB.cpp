#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
string str[100];
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int n;
	while (cin >> n)
	{
		string file[100][60];
		printf("------------------------------------------------------------\n");
		int maxl = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> str[i];
			maxl = max(maxl, int(str[i].length()));
		}
		sort(str, str + n);

		int c, r;
		c = (60-maxl) / (maxl + 2) + 1;
		r = (n - 1) / c + 1;
		c = (n - 1) / r + 1;
		int i = 0, j = 0;
		for (int k=0;k<n;k++)
		{
			file[i++][j] = str[k];
			if (i == r)
			{
				i = 0;
				j++;
			}
		}
		//输出
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c - 2; j++)
				cout << left << setw(maxl + 2) << file[i][j];

			if (file[i][c - 1].empty())
				cout << left << setw(maxl) << file[i][c-2] << endl;
			else if (!file[i][c - 1].empty() && c != 1)
			{
				cout << left << setw(maxl + 2) << file[i][c - 2];
				cout << left << setw(maxl) << file[i][c-1] << endl;
			}
			else
				cout << left << setw(maxl) << file[i][0] << endl;
		}
	}
	return 0;
}