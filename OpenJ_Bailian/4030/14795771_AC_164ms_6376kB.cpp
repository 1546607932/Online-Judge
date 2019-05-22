#include <iostream>
#include<string>
using namespace std;
string a, b;
int main()
{
	int x = -1, y = 0;//x表示第一次出现的位置，y统计总次数
	getline(cin, a);
	getline(cin, b);
	int la = a.length(), lb = b.length();//或者用a.size()
	int i = 0;
	while (i<lb)
	{
		while (b[i] == ' '&&i<lb)i++;
		int j = 0;
		while (j<la&&i<lb)
		{
			if (a[j] == b[i] || abs(a[j] - b[i]) == 32)
			{
				i++; j++;
			}
			else
				break;
		}
		if (j == la && (b[i] == ' ' || i == lb - 1))
		{
			if (x == -1)
				x = i - la;
			y++;
		}
		while (b[i] != ' '&&i<lb)i++;
	}
	if (x == -1)
		cout << x << endl;
	else
		cout << y << ' ' << x << endl;
	return 0;
}