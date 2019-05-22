#include<iostream>
#include<string>
using namespace std;
string a, b;
int flag;
int main()
{

	while (cin >> a >> b)
	{
		flag = 1;
		unsigned c = a.length(), d = b.length();
		unsigned now = 0;
		for (unsigned i = 0; i < c&&flag; i++)
			for (unsigned j = now; j < d; j++)
			{
				if (b[j] == a[i])
				{
					now = j + 1;
					break;
				}
				else if (j == (d - 1))
					flag = 0;
			}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}