#include<iostream>
#include<string>
using namespace std;
string A, B;
int n;
string newstr(int a)
{
	string behind, after;
	behind = A.substr(0, a);
	after = A.substr(a, n - a);
	return after + behind;
}
int main()
{
	int T;
	cin >> T;
	for (int z = 0; z < T; z++)
	{
		cin >> A;
		B = A;
		n = A.length();
		char min = A[0];
		for (int i = 1; i < n; i++)
			if (A[i] <= min)
			{
				min = A[i];
				if (newstr(i) < B)
					B = newstr(i);
			}
		cout << B << endl;
	}
	return 0;
}