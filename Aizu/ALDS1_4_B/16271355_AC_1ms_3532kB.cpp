#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100000;
int a[maxn];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int temp;
	int m; scanf("%d", &m);
	int sum = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		if (binary_search<int*>(a, a + n, temp))
			sum++;
	}
	printf("%d\n", sum);
	return 0;
}