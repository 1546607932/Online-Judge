#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int maxn = 25;
int n;//木块堆数
vector<int> block[maxn];
int pa, pb;
int a, b;
int find_block(int aimed)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < block[i].size(); j++)
			if (block[i][j] == aimed)
				return i;
	return -1;
}
void back_aimed(int aimed, int who)
{
	int sz = block[who].size();
	for (int i = sz - 1; i >= 0; i--)
	{
		if (block[who][i] == aimed)
			break;
		else
		{
			block[block[who][i]].push_back(block[who][i]);
			block[who].pop_back();
		}
	}
}
void print_block()
{
	for (int i = 0; i < n; i++)
	{
		cout << i << ':';
		if (block[i].size() == 0)
		{
			cout << endl; continue;
		}
		for (int j = 0; j < block[i].size() - 1; j++)
			cout << ' ' << block[i][j];
		cout << ' ' << block[i][block[i].size() - 1] << endl;
	}
}
int main()
{
	//	freopen("d:\\sample.txt", "r", stdin);
	//	freopen("d:\\test.txt", "w", stdout);
	for (int i = 0; i < maxn; i++)
		block[i].push_back(i);
	cin >> n;
	string temp;
	while ((cin >> temp) && temp[0] != 'q')
	{
		string temp2;
		cin >> a >> temp2 >> b;
		pa = find_block(a);
		pb = find_block(b);
		if (pa == pb)
			continue;
		if (temp[0] == 'm'&&temp2 == "onto")
		{
			back_aimed(a, pa);
			back_aimed(b, pb);
			block[pa].pop_back();
			block[pb].push_back(a);
		}
		else if (temp[0] == 'm'&&temp2 == "over")
		{
			back_aimed(a, pa);
			block[pa].pop_back();
			block[pb].push_back(a);
		}
		else if (temp[0] == 'p'&&temp2 == "onto")
		{
			back_aimed(b, pb);
			vector<int> t;
			while (find_block(a) == pa)
			{
				t.push_back(block[pa].back());
				block[pa].pop_back();
			}
			int len = t.size();
			for (int i = 0; i < len; i++)
			{
				block[pb].push_back(t.back());
				t.pop_back();
			}
		}
		else
		{
			vector<int> t;
			while (find_block(a) == pa)
			{
				int temp = block[pa].back();
				block[pa].pop_back();
				t.push_back(temp);
			}
			int len = t.size();
			for (int i = 0; i < len; i++)
			{
				block[pb].push_back(t.back());
				t.pop_back();
			}
		}
	}
	print_block();
	return 0;
}