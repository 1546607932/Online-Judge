#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string a, b;
	while ((cin >> a)&&a!="0")
	{
		b = a;
		int len=b.length();
		for (int i = 0; i < len; i++)
			if (b[i] > '7')
				b[i] -= 2;
			else if (b[i] > '2')
				b[i]--;
		stringstream line(b);
		int c;
		line >>oct>> c;
		cout << a << ':' << ' ' << dec << c << endl;
	}
	return 0;
}