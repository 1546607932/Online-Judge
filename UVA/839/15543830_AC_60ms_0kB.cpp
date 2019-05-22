#include<iostream>
using namespace std;
bool solve(int& w)
{
	int w1, d1, w2, d2;
	bool b1 = true, b2 = true;
	cin >> w1 >> d1 >> w2 >> d2;
	if (!w1) b1 = solve(w1);
	if (!w2) b2 = solve(w2);
	w = w1 + w2;
	return b1 && b2 && (w1*d1 == w2 * d2);
}
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int T;
	int w;
	cin >> T;
	while (T--)
	{
		if (solve(w))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		if (T)
			cout << endl;
	}
	return 0;
}