#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int N = 1000+5;
string a, b;
int dp[N][N];

int least_common_substr() {
	a = ' ' + a; b = ' ' + b;
	int alen = a.length(), blen = b.length();
	for (int i = 0; i < alen; i++)
		for (int j = 0; j < blen; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
	return dp[alen - 1][blen - 1];
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cout << least_common_substr() << endl;
	}
	return 0;
}