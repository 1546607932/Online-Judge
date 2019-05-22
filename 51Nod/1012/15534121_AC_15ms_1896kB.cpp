#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}
long long lcm(int a, int b)
{
	return (long long)a / gcd(a, b)*b;
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << lcm(a, b) << endl;
	return 0;
}