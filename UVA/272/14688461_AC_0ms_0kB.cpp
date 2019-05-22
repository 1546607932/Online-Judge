#include<iostream>
using namespace std;
int main()
{
	int count = 0;
	char ch;
	while (scanf("%c", &ch)!=EOF)
	{
		if (ch == '"')
		{
			if (count % 2 == 0)
				cout << "``";
			else
				cout << "''";
			count++;
		}
		else
			cout << ch;
	}
	return 0;
}