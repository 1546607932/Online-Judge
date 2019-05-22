#include<iostream>
#include<string>
using namespace std;
int ans, chance, other;
string aim, pla;
void guess(char ch)
{
	int jud = 0;
	for(int i=0;i<aim.length();i++)
		if (aim[i] == ch)
		{
			other--;
			jud = 1;
			aim[i] = ' ';
		}
	if (jud == 0)
		chance--;
	if (!other)
		ans = 1;
	if (!chance)
		ans = 2;
}
int main()
{
	int rnd;
	while ((cin >> rnd >> aim >> pla) && rnd != -1)
	{
		cout << "Round " << rnd << endl;

		ans = 0;
		chance = 7;
		other = aim.length();
		for (int i = 0; i < pla.length(); i++)
		{
			guess(pla[i]);
			if (ans != 0)
				break;
		}
		if (ans == 1)
			cout << "You win." << endl;
		else if (ans == 2)
			cout << "You lose." << endl;
		else
			cout << "You chickened out." << endl;
	}
	return 0;
}