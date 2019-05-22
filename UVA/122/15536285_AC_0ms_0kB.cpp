#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
bool fail = false;
struct Node
{
	int have_value;
	int v;
	Node* left, *right;
	Node() :have_value(0), left(NULL), right(NULL) {}
};
Node* root;
Node* newnode() { return new Node; }
void addnode(int v,char* s)
{
	Node* cur = root;
	int len = strlen(s);
	for(int i=0;i<len;i++)
		if (s[i] == 'L')
		{
			if (cur->left == NULL)
				cur->left = newnode();
			cur = cur->left;
		}
		else if (s[i] == 'R')
		{
			if (cur->right == NULL)
				cur->right = newnode();
			cur = cur->right;
		}
	if (cur->have_value)	fail = true;
	else
	{
		cur->v = v;
		cur->have_value = 1;
	}
}
void release(Node* u)
{
	if (u == NULL)
		return;
	else
	{
		if (u->left != NULL)release(u->left);
		if (u->right != NULL) release(u->right);
	}
	delete u;
}
bool read_input()
{
	fail = false;
	release(root);
	root = newnode();
	int value;
	char s[600];
	while (1)
	{
		if (scanf("%s", s)!=1)	return false;
		if (!strcmp(s,"()"))	break;
		sscanf(s + 1, "%d", &value);
		addnode(value, strchr(s, ',') + 1);
	}
	return true;
}
int get_ans(vector<int>& ans)
{
	Node* u = root;
	queue<Node*> que;
	que.push(u);
	while (que.size())
	{
		Node* cur = que.front(); que.pop();
		if (!cur->have_value)
			return 0;
		else
		{
			if(cur->left!=NULL)
				que.push(cur->left);
			if(cur->right!=NULL)
				que.push(cur->right);
			ans.push_back(cur->v);
		}
	}
	return 1;
}
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	while (read_input())
	{
		vector<int> ans;
		if (get_ans(ans)&&!fail)
		{
			int len = ans.size();
			for (int i = 0; i < len - 1; i++)
				cout << ans[i] << ' ';
			cout << ans[len - 1] << endl;
		}
		else
			cout << "not complete" << endl;
	}
	return 0;
}