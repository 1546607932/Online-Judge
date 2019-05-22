#include<iostream>
using namespace std;
int main() {
	int temp;
	int n;
	while (scanf("%d", &n)!=EOF) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			sum += temp;
		}
		printf("%d\n", sum);
	}
	return 0;
}