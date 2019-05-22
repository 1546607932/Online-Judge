#include<iostream>
#include<cmath>
using namespace std;

int is_prime(int n) {
	if (n%2==0)
		return 2;
	else for (int i = 3; i <= sqrt(n); i++)
		if (n%i == 0)
			return i;
	return true;
}
int main() {
	int n; scanf("%d", &n);
	printf("%d:", n);
	int a;
	while (n!=0&&n!=1) {
		if ((a=is_prime(n))==1) {
			printf(" %d", n);
			break;
		}
		else {
			printf(" %d", a);
			n /= a;
		}
		
	}
	printf("\n");
	return 0;
}