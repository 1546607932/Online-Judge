#include<iostream>
#include<cstring>
using namespace std;
const int maxl = 100000 + 5;
char line[maxl];
int _next[maxl];
int cur, last;
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	while (cin.getline(line+1,maxl))
	{
		last = cur = 0;
		_next[0] = 0;
		int len = strlen(line+1);

		for (int i = 1; i <= len; i++)
		{
			char ch = line[i];
			if (ch == '[') { cur = 0; }
			else if (ch == ']') { cur = last; }
			else
			{
				_next[i] = _next[cur];
				_next[cur] = i;
				if (cur == last) { last = i; }
				cur = i;
			}
		}
		for (int i = _next[0]; i != 0; i = _next[i])
			cout << line[i];
		cout << endl;
	}
	return 0;
}