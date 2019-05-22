#include<iostream>
#include<string>
using namespace std;
const string a = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
	char temp;
	while ((temp = getchar())!=EOF)
	{
		int flag = 0;
		for (int i = 0;i<47; i++)
		{
			if (a[i] == temp)
			{
				cout << a[i - 1];
				flag = 1;
				break;
			}
		}
		if (!flag)
			cout << temp;
	}
	return 0;
}