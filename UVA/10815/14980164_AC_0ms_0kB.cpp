#include<iostream>
#include<cctype>
#include<set>
#include<string>
using namespace std;
set<string> words;
string to_lower(string a)
{
	int count = 0;
	int sz = a.length();
	for (int i = 0; i < sz; i++)
		if (isupper(a[i]))
			a[i]=tolower(a[i]);
	return a;
}
int main()
{
	while (1)
	{
		char t;
		string temp;
		while (t = getchar())
		{
			if (t == EOF)
				goto LOOP;
			if (isalpha(t))
				temp += t;
			else
				break;
		}
		if (temp.size() != 0)
		{
			temp = to_lower(temp);
			words.insert(temp);
		}
	}
LOOP:
	for (set<string>::iterator it = words.begin(); it != words.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}