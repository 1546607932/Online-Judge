#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
int Left[256], Right[256];
int pre[30], in[30], pos[30];
int len;
queue<int> ans;
int get_tree(int L1,int R1,int L2,int R2)
{
	if (L1 > R1 || L2 > R2)
		return -1;
	int root = pre[L1];
	int pr = L2;
	while (in[pr] != root) pr++;
	int cntL = pr - L2;
	int cntR = R2 - pr;
	Left[root] = get_tree(L1 + 1, L1  + cntL, L2, L2 + cntL - 1);
	Right[root] = get_tree(R1 - cntR + 1, R1, pr + 1, R2);
	return root;
}
bool read_input()
{
	memset(Left, 0, sizeof(Left));
	memset(Right, 0, sizeof(Right));
	string temp;
	if (!(cin>>temp))	return false;
	len = temp.length();
	for (int i = 0; i < len; i++)
		pre[i] = temp[i] - 'A';
	cin >> temp;
	for (int i = 0; i < len; i++)
		in[i] = temp[i] - 'A';
	return true;
}
void get_post(int root)
{
	if (Left[root] != -1)
		get_post(Left[root]);
	if (Right[root] != -1)
		get_post(Right[root]);
	ans.push(root);
}
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	while (read_input())
	{
		int root = get_tree(0, len - 1, 0, len - 1);
		get_post(root);
		while (!ans.empty())
		{
			char temp = ans.front() + 'A';
			ans.pop();
			cout << temp;
		}
		cout << endl;
	}
	return 0;
}