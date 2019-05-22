#include<iostream>
#include<cmath>
using namespace std;

bool is_prime(const int n) {
	if (n == 2)
		return true;
	else if (n < 2 || n % 2 == 0)
		return false;
	else for (int i = 3; i <=sqrt(n); i += 2)
		if (n%i == 0)
			return false;
	return true;
}

int main() {
	int total = 0;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if (is_prime(temp))
			total++;
	}
	printf("%d\n", total);
	return 0;
}