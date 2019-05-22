#include<iostream>
#include<cstring>
using namespace std;
int pile[200];
const int zero = 100;
const int INF = 1000000;
int mi = INF, ma = -INF;
int solve(int pos)
{
	int value;
	cin >> value;
	if (value == -1)
		return 0;	
	
	if (pos < mi)
		mi = pos;
	if (pos > ma)
		ma = pos;

	pile[pos] += value;
	solve(pos - 1);
	solve(pos + 1);
	return 1;
}
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int kase = 0;
	while (1)
	{
		if (kase)
			cout << endl;
		memset(pile, 0, sizeof(pile));
		mi = INF, ma = -INF;
		if (!solve(zero))
			break;
		printf("Case %d:\n", ++kase);
		for (int i = mi; i < ma; i++)
			cout << pile[i] << ' ';
		cout << pile[ma] << endl;
	}
	return 0;
}