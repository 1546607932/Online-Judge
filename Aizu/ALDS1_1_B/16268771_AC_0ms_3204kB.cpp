#include<iostream>
using namespace std;

int gcd(int m, int n) {
	return n ? gcd(n, m%n) : m;
}
int main() {
	int m,n; scanf("%d%d",&m,&n);
	printf("%d\n", gcd(m, n));
	return 0;
}