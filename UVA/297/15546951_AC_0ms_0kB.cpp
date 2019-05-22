#include<iostream>
using namespace std;
const int len = 32;
char graph[len][len];
void draw(int r,int c,int len)
{
	char ch;
	cin >> ch;
	if (ch == 'p')
	{
		draw(r,c+len/2,len/2);
		draw(r,c,len/2);
		draw(r+len/2,c,len/2);
		draw(r+len/2,c+len/2,len/2);
	}
	else if (ch == 'f')
	{
		for (int i = 0; i < len; i++)
			for (int j = 0; j < len; j++)
				graph[r + i][c + j] = 'B';
	}
}
int get_total()
{
	int ans = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			if (graph[i][j] == 'B')
				ans++;
	return ans;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		for (int i = 0; i < len; i++)
			for (int j = 0; j < len; j++)
				graph[i][j] = ' ';
		draw(0,0,len);
		draw(0,0,len);
		printf("There are %d black pixels.\n", get_total());
	}
	return 0;
}