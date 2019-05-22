#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 105;
const int INF = 2000000000;
int arr[maxn][maxn];
int info[maxn];

int get_ans(int m, int n) {
		int ans = INF;
	if (m == n)
		return 0;
	else if (arr[m][n])
		return arr[m][n];
	else {
		for (int i = m; i < n; i++) {
			ans = min(ans, get_ans(m, i) + get_ans(i+1, n) + info[m] * info[i+1] * info[n + 1]);
		}
	}
	return arr[m][n] = ans;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &info[i],&info[i+1]);
	cout << get_ans(0, n-1) << endl;
	return 0;
}