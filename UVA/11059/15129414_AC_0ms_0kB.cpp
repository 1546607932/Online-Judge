#include<iostream>
#include<algorithm>
using namespace std;
long long S[20];
int main()
{
	int n;
	int kase = 0;
	while (cin >> n)
	{
		long long ma = 0;
		for (int i = 0; i < n; i++)
			cin >> S[i];
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
			{
				long long temp = 1;
				for (int k = i; k <= j; k++)
					temp *= S[k];
				ma = max(ma, temp);
			}
		printf("Case #%d: The maximum product is %lld.\n\n",++kase,ma);
	}
	return 0;
}