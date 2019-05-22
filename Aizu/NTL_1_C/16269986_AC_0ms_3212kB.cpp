#include<iostream>
#include<cmath>
using namespace std;

int gcd(int m, int n) {
	return n ? gcd(n, m%n) : m;
}

int main() {
	int n; scanf("%d", &n);
	int lcm, temp;
	scanf("%d", &lcm);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &temp);
		lcm = lcm * temp / gcd(lcm, temp);
	}
	printf("%d\n", lcm);
	return 0;
}