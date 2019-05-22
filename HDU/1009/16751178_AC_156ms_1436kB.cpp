#include<iostream>
#include<algorithm>
using namespace std;
struct info {
	int a, b;
	double c;
	bool operator<(info& b) {
		return c > b.c;
	}
};
istream& operator>>(istream& in, info& temp) {
	cin >> temp.a;
	cin >> temp.b;
	temp.c = (double)temp.a / temp.b;
	return in;
}
info aa[1005];
int main() {
	int m, n;
	while ((cin >> m >> n)&&(m!=-1||n!=-1)) {
		for (int i = 0; i < n; i++)
			cin >> aa[i];
		sort(aa, aa + n);
		double ans = 0;
		for (int i = 0; i < n; i++) {
			if (aa[i].b <= m) {
				ans += aa[i].a;
				m -= aa[i].b;
			}
			else {
				ans += aa[i].c*m;
				break;
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}