#include<iostream>
#include<string>
using namespace std;
int SIZE;
int judge(int n)
{
	if (SIZE%n == 0)
		return SIZE/n;
	else
		return 0;
}
int main()
{
	int N;
	cin >> N;
	for (int SIGN = 0; SIGN < N; SIGN++)
	{
		string a;
		cin >> a;
		SIZE = a.length();
		for (int i = 1; i <= SIZE; i++)
		{
			int b;
			if (b = judge(i))
			{
				string temp = a.substr(0, i);
				string ans=temp;
				for (int j = 1; j < b; j++)
					ans += temp;
				if (ans == a)
				{
					if (SIGN < N - 1)
						cout << i << endl << endl;
					else
						cout << i << endl;
					break;
				}
			}
		}
	}
	return 0;
}