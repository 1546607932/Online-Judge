#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, q;
	int kase(1);
	while (cin >> n >> q) {
		if (n == 0 && q == 0)
			break;
		multiset<int>a;
		int c;
		int b[10000];
		for (int i = 0; i<n; i++) {
			cin >> c;
			a.insert(c);
		}
		for (int i = 0; i<q; i++)
			cin >> b[i];
		cout << "CASE# " << kase++ << ":" << endl;
		for (int i = 0; i<q; i++) {
			multiset<int>::iterator p = a.lower_bound(b[i]);
			int count(0);
			for (multiset<int>::iterator j = a.begin(); j != p && j != a.end(); j++) {
				count++;
			}
			if ((p != a.end())&&(*p == b[i]))  cout << b[i] << " found at " << count + 1 << endl;
			else cout << b[i] << " not found" << endl;
		}
	}
}