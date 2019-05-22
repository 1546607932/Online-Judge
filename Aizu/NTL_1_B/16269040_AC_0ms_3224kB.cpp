#include<iostream>
using namespace std;

typedef unsigned long long ull;
const int M = 1000000007;

ull pow(ull x, ull y) {
	if (y == 0)
		return 1;
	ull ans = pow(x*x%M, y / 2);
	if (y % 2 == 1)
		ans = ans * x%M;
	return ans;
}

int main() {
	ull m, n;
	scanf("%lld%lld", &m, &n);
	printf("%lld\n", pow(m, n));
	return 0;
}