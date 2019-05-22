#include<iostream>
using namespace std;
int main() {
	int temp;
	int n;
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			sum += temp;
		}
		printf("%d\n", sum);
		if (t)printf("\n");
	}
	return 0;
}