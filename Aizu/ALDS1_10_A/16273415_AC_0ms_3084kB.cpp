#include<iostream>
#include<algorithm>
using namespace std;

long long fibo[45];

void get_fibo() {
	fibo[0] = fibo[1] = 1;
	for (int i = 2; i < 45; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
}
int main() {
	get_fibo();
	int n;
	cin >> n;
	cout << fibo[n] << endl;
	return 0;
}