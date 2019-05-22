#include<iostream>
#include<algorithm>
#include<sstream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	getchar();
	while (n--)
	{
		char a;
		string temp;
		while (a = getchar())
		{
			if (a != ' '&&a != '\n')
				temp += a;
			else if (a == ' ')
			{
				reverse(temp.begin(), temp.end());
				cout << temp << ' ';
				temp.clear();
			}
			else if (a == '\n')
			{
				reverse(temp.begin(), temp.end());
				cout << temp;
				cout << endl;
				temp.clear();
				break;
			}
		}
	}
	return 0;
}