#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	char a[105];
	char b[105];
	while (scanf("%s%s", a, b) == 2)
	{
		int count1 = 0;
		int count2 = 0;
		int len1 = strlen(a);
		int len2 = strlen(b);
		if (len1 > len2) { swap(a, b); swap(len1, len2); }
		int i = 0; int j = 0;
		while (i < len1)
		{
			if (a[i] + (j<len2 ? b[j] : 0) <= 3+2*'0')
			{
				i++;
				j++;
			}
			else
			{
				i = 0;
				j = ++count1;
			}
		}
		int ans1 = max(count1 + len1, len2);
		swap(a, b);
		swap(len1, len2);
		i = 0; j = 0;
		while (i < len1)
		{
			if (a[i] + (j<len2 ? b[j] : 0) <= 3 + 2 * '0')
			{
				i++;
				j++;
			}
			else
			{
				i = 0;
				j = ++count2;
			}
		}
		int ans2 = count2 + len1;
		cout << min(ans1,ans2) << endl;
	}
	return 0;
}