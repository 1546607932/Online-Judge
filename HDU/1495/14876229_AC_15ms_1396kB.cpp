#include<iostream>
using namespace std;
using namespace std;
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}
int main()
{
	int a, b, c;
	while (cin >> a >> b >> c && (a&&b&&c))
	{
		a /= gcd(b, c);
		if (a & 1)
			cout << "NO" << endl;
		else
			cout << a - 1 << endl;
	}
	return 0;
}