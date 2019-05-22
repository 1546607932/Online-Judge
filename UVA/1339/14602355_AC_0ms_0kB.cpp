#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
string a, b;
int co[27], aim[27];
void calculate()
{
	int len1 = a.length();
	for (int i = 0; i < len1; i++)
	{
		co[a[i] - 'A']++;
		aim[b[i] - 'A']++;
	}
}
int main()
{
	while (cin >> a >> b)
	{
		int flag = 1;
		memset(co, 0, sizeof(co));
		memset(aim, 0, sizeof(aim));
		calculate();
		sort(co, co + 26);
		sort(aim, aim + 26);
		for(int i=0;i<26;i++)
			if (co[i] != aim[i])
			{
				flag = 0;
				break;
			}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}