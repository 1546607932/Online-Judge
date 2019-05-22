#include<iostream>
#include<sstream>
#include<string>
#include<set>
using namespace std;
int main()
{
	set<string> words;
	string a;
	while (getline(cin,a))
	{
		words.clear();
		stringstream line(a);
		string temp;
		while (line >> temp)
		{
			if (temp == "#") goto LOOP;
			words.insert(temp);
		}
		cout << words.size() << endl;
	}
	LOOP:
	return 0;
}