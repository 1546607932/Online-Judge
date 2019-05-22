#include<iostream>
#include<string>
using namespace std;
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	string temp;
	int T;
	cin >> T;
	getchar();
	while (T--)
	{
		bool ok = true;
		getline(cin, temp);
		int len = temp.length();
		int count1 = 0;
		int count2 = 0;
		char ch;
		for (int i = 0; i < len; i++)
		{
			if ((ch = temp[i]) == '(')
				count1++;
			else if (ch == ')')
				count1--;
			else if ((ch == '['))
				count2++;
			else if ((ch == ']'))
				count2--;
			else
				continue;
			if (count1 < 0 || count2 < 0)
			{
				ok = false;
				break;
			}
			for (int j = i + 1; j < len; j++)
			{
				if ((ch = temp[j]) == '(')
					count1++;
				else if (ch == ')')
					count1--;
				else if ((ch == '['))
					count2++;
				else if ((ch == ']'))
					count2--;
				if (count1 == 0 && count2 == 0)
				{
					temp[i] = ' ';
					temp[j] = ' ';
					break;
				}
			}
			if (count1 != 0 || count2 != 0)
			{
				ok = false;
				break;
			}
		}
		if (ok)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}