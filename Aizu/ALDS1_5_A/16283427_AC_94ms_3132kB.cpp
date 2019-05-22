#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 25;
int n;
int arr[maxn];

int solve(int i, int m) {
	if (m == 0)
		return true;
	else if (i > n)
		return false;
	else if (m < 0)
		return false;
	bool ans = solve(i + 1, m) || solve(i + 1, m - arr[i]);
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int temp; scanf("%d", &temp);
		if (solve(0, temp))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}