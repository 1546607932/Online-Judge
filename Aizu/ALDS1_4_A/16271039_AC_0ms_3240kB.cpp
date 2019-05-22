#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 10000;

int main() {
	int n;
	int a[maxn];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int m, temp, sum=0;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		for (int i = 0; i < n; i++)
			if (a[i] == temp) {
				sum++; break;
			}
	}
	printf("%d\n", sum);
	return 0; 
}