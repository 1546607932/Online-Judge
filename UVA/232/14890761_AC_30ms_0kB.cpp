#include<iostream>
#include<cstring>
using namespace std;
int n, m;
int flag[12][12];//不能为0，能横为1，能竖为2，能横竖为3.
char word[12][12];
int num[12][12];
void r_output()
{
	cout << "Across" << endl;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if (flag[i][j] % 2 == 1)
			{
				printf("%3d", num[i][j]);
				cout << '.';
				while (1)
				{
					cout << word[i][j++];
					if (word[i][j] == '*' || j == m)
						break;
				}
				cout << endl;
			}
		}
}
void c_output()
{
	cout << "Down" << endl;
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			if (flag[i][j]==2||flag[i][j]==3)
			{
				printf("%3d", num[i][j]);
				cout << '.';
				int temp = i;
				while (1)
				{
					cout << word[temp][j];
					flag[temp++][j] = 0;
					if (word[temp][j] == '*' || temp == n)
						break;
				}
				cout << endl;
			}
		}
}
void get_flag()
{
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if (word[i][j] == '*')
			{
				flag[i][j] = 0;
				continue;
			}
			if (j == 0 || word[i][j-1] == '*')
				flag[i][j] = 1;
			if (i==0 || word[i-1][j] == '*')
				if (flag[i][j] == 1)
					flag[i][j] = 3;
				else
					flag[i][j] = 2;
		}
}
void get_number()
{
	memset(num, 0, sizeof(num));
	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (flag[i][j])
				num[i][j] = ++count;
}
int main()
{
	int cnt = 0;
	int count = 0;
	while ((cin >> n >> m) && n&&m)
	{
		if (cnt++)
			cout << endl;
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> word[i][j];
		get_flag();
		cout << "puzzle #" << ++count << ':' << endl;
		get_number();
		r_output();
		c_output();
	}
	return 0;
}