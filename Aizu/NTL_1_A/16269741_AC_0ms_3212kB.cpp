#include<iostream>
#include<cmath>
using namespace std;

bool is_prime(int n) {
	if (n == 2)
		return true;
	else if (n < 2 || n % 2 == 0)
		return false;
	else for (int i = 3; i <= sqrt(n); i++)
		if (n%i == 0)
			return false;
	return true;
}
int main() {
	int n; scanf("%d", &n);
	printf("%d:", n);
	while (n!=0&&n!=1) {
		if (is_prime(n)) {
			printf(" %d", n);
			break;
		}
		if (n % 2 == 0) {
			n /= 2;
			printf(" 2");
			continue;
		}
		for (int i = 3; i <= sqrt(n); i+=2)
			if (n%i == 0) {
				n /= i;
				printf(" %d", i);
				break;
			}
	}
	printf("\n");
	return 0;
}