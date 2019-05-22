#include<iostream>
#include<cstring>
using namespace std;
char codechar[9][1 << 8];
int readcode()
{
	memset(codechar, 0, sizeof(codechar));
	int ch;
	for (int i = 1; i < 9; i++)
	{
		for (int j = 0; j < (1 << i) - 1; j++)
		{
			ch = getchar();
			if (ch == EOF)
				return 0;
			if (ch == '\n')
				return 1;
			else
				codechar[i][j] = ch;
		}
	}
	return 1;
}
int getlen()
{
	char ch;
	int len = 0;
	for (int i = 0; i < 3; i++)
	{
		ch = getchar();
		if (ch == '\n')
		{
			i--;
			continue;
		}
		len = len * 2 + ch - '0';
	}
	if (len == 0)
		return 0;
	return len;
}
char getch(int len)
{
	char ch;
	int length = 0;
	for (int i = 0; i < len; i++)
	{
		ch = getchar();
		if (ch == '\n')
		{
			i--;
			continue;
		}
		length = length * 2 + ch - '0';
	}
	if (length == (1 << len) - 1)
		return '\0';
	return codechar[len][length];
}
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	while (readcode())
	{
		int len;
		while (len=getlen())
		{
			while (1)
			{
				char ch = getch(len);
				if (ch != '\0')
					putchar(ch);
				else
					break;
			}
		}
		cout << endl;
		getchar();
	}
	return 0;
}