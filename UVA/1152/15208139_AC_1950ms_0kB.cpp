#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 4000;
int A[maxn + 5], B[maxn + 5], C[maxn + 5], D[maxn + 5];
int ANS[maxn*maxn + 5];
int n;
int ct = 0;
void go()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ANS[ct++] = C[i] + D[j];
	sort(ANS, ANS + ct);
}
int main()
{
	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		int total = 0;
		ct = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
		go();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (binary_search(ANS, ANS + ct, -(A[i] + B[j])))
					total += upper_bound(ANS, ANS + ct, -(A[i] + B[j])) - lower_bound(ANS, ANS + ct, -(A[i] + B[j]));
		cout << total << endl;
		if (kase)
			cout << endl;
	}
	return 0;
}