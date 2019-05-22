#include<iostream>
using namespace std;
int alpha[25];
int go(int pos, int dir, int len, int n)
{
	while (len != 0)
	{
		pos = (pos + dir + n) % n;
		if (alpha[pos] != 0)
			len--;
	}
	return pos;
}
int main()
{
	int n, a, b;
	while (cin >> n >> a >> b&&n&&a&&b)
	{
		//初始化数组
		for (int i = 0; i < 25; i++)
			alpha[i] = 1;
		//循环结束条件
		int left = n;
		//人物位置
		int pos1 = n - 1;
		int pos2 = 0;
		while (left)
		{
			pos1 = go(pos1, 1, a,n);
			pos2 = go(pos2, -1, b,n);
			if (pos1 == pos2)
			{
				printf("%3d", pos1+1);
				alpha[pos1] = 0;
				if (left != 1)
					printf("%c", ',');
				else
					printf("%c", '\n');
				left--;
			}
			else
			{
				printf("%3d%3d", pos1+1, pos2+1);
				alpha[pos1] = 0;
				alpha[pos2] = 0;
				if (left != 2)
					printf("%c", ',');
				else
					printf("%c", '\n');
				left -= 2;
			}
		}
	}
	return 0;
}