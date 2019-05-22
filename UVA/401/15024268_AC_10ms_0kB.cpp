#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;
const char* mirror = "A   3  HIL JM O   2TUVWXY51SE 2  8 ";
string rev;
char getnum(char a)
{
	char b;
	if (isalpha(a))
		return b=mirror[a - 'A'];
	else
		return b=mirror[a - '0'+25];
}
int main()
{
	const char* a = "is not a palindrome.";
	const char* b = "is a regular palindrome.";
	const char* c = "is a mirrored string.";
	const char* d = "is a mirrored palindrome.";
	int count = 0;
	string temp;
	while (cin>>temp)
	{
		int flag1 = 1 , flag2 = 0;
		rev = temp;
		reverse(rev.begin(), rev.end());
		if (rev == temp)
			flag2 = 1;
		int sz = temp.size();
		for (int i = 0; i < sz/2+1; i++)
			if (temp[sz-1- i] != getnum(temp[i]))
			{
				flag1 = 0; break;
			}
		if (flag1 == 0 && flag2 == 0)
			cout << temp << " -- " << a << endl;
		else if (flag1 == 0 && flag2 == 1)
			cout << temp << " -- " << b << endl;
		else if (flag1 == 1 && flag2 == 0)
			cout << temp << " -- " << c << endl;
		else
			cout << temp << " -- " << d << endl;
		cout << endl;
	}
	return 0;
}