#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<iomanip>
using namespace std;
string word[1000][100];
int len[1000];
int maxslen[100];
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int count = 0;
	string temp;
	while (getline(cin, temp))
	{
		stringstream line(temp);
		int n = 0;
		while (line >> word[count][n++]) len[count]++;
		count++;
	}
	int maxl = 0;	//最大的列数
	for (int i = 0; i < count; i++)
		maxl = max(maxl, len[i]);
	for (int i = 0; i < maxl; i++)	//对于每一列
		for (int j = 0; j < count; j++)	//对于每一个行
			maxslen[i] = max(maxslen[i], int(word[j][i].length()));//第i行第j列

	for (int i = 0; i < count; i++)	//每一行
	{
		for (int j = 0; j < maxl; j++)
		{
			if (!word[i][j].empty() && !word[i][j + 1].empty())
				cout << left << setw(maxslen[j] + 1) << word[i][j];
			else
			{
				cout << left << word[i][j] << endl;
				break;
			}
		}
	}
	return 0;
}