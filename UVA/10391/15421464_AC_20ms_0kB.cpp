#include<iostream>
#include<string>
#include<set>
using namespace std;
set<string> dic;
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	string temp;
	while (cin >> temp)
		dic.insert(temp);
	int len = dic.size();
	for (auto it = dic.begin(); it != dic.end(); it++)
	{
		int len = (*it).length();
		for (int i = 1; i < len; i++)
		{
			if ((dic.find((*it).substr(0, i)) != dic.end()) && dic.find((*it).substr(i, len - i)) != dic.end())
			{
				cout << (*it) << endl;
				break;
			}
		}
	}
	return 0;
}