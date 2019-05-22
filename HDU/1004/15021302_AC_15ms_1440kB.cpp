#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string, int> word;
int main()
{
	int n;
	while (cin>>n&&n)
	{
		int max = 0;
		string m;
		word.clear();
		while (n--)
		{
			string temp;
			cin >> temp;
			if (word.find(temp) == word.end())
			{word[temp] = 0;
			word[ temp]++;
			}
			else
				word[temp]++;
			if (word[temp] > max)
			{
				max = word[temp];
				m = temp;
			}
		}
		cout << m << endl;
	}
	return 0;
}