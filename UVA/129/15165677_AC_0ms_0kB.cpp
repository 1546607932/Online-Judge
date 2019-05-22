#include<iostream>
using namespace std;
int str[85];//解串长度
int n;//第n个解
int L;//字符范围
int total;
int dfs(int cur)
{
	if (total++ == n)
	{
		for (int i = 0; i < cur; i++)
			if ((i+1) % 4 == 0&&(i+1)%64!=0&&(i+1)!=cur)
				printf("%c ", 'A' + str[i]);
			else if((i+1)%64==0&&(i+1)!=cur)
				printf("%c\n", 'A' + str[i]);
			else
				printf("%c", 'A' + str[i]);
		cout << endl;
		cout << cur << endl;
		return 0;
	}
	else for (int i = 0; i < L; i++)
	{
		str[cur] = i;
		int ok = 1;
		for (int j = 1; 2 * j <= cur + 1; j++)
		{
			int equal = 0;
			for (int k = 0; k < j; k++)
				if (str[cur - (k + j)] != str[cur - k])
				{
					equal = 1;
					break;
				}
			if (!equal) { ok = 0; break; }
		}
		if (ok)	if (!dfs(cur + 1)) return 0;
	}
	return 1;
}
int main()
{
	while ((cin >> n >> L) && n&&L)
	{
		total = 0;
		dfs(0);
	}
	return 0;
}