#include<iostream>
using namespace std;
int coin[105];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp; scanf("%d", &temp);
		coin[temp]++;
	}
	int max = -1;
	for (int i = 1; i <= 100; i++)
		if (coin[i] > max)
			max = coin[i];
	printf("%d\n", max);
	return 0;
}