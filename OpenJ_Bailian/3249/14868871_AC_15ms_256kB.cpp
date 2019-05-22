#include<iostream>
#include<string>
using namespace std;
string hexa;
int bina[300];
int cou = 0;
int judge()
{
	int sz = hexa.length();
	for (int i = 0; i < sz; i++)
		if (hexa[i] != '0')
			return 1;
	return 0;
}
void function()
{
	int sz = hexa.length();
	bina[cou++] = (hexa[sz - 1] - '0') % 2;
	hexa[sz - 1] -= (hexa[sz - 1] - '0') % 2;
	int temp = 0;
	for (int i = 0; i < sz; i++)
	{
		int temp1 = (hexa[i] - '0') % 2;
		hexa[i] = ((10 * temp + hexa[i] - '0') / 2) + '0';
		temp = temp1;
	}
}
int main()
{
	while (cin >> hexa)
	{
		::cou = 0;
		if (hexa == "0")
		{
			cout << 0 << endl;
			continue;
		}
		while (1)
		{
			if (judge())
				function();
			else
			{
				for (int i = cou - 1; i >= 0; i--)
					cout << bina[i];
				cout << endl;
				break;
			}
		}
	}
	return 0;
}