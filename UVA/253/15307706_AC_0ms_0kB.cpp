#include<iostream>
#include<string>
using namespace std;
int permu[24][6]=
{
{ 1,2,3,4,5,6 },
{ 1,3,5,2,4,6 },
{ 1,4,2,5,3,6 },
{ 1,5,4,3,2,6 },
{ 2,1,4,3,6,5 },
{ 2,3,1,6,4,5 },
{ 2,4,6,1,3,5 },
{ 2,6,3,4,1,5 },
{ 3,1,2,5,6,4 },
{ 3,2,6,1,5,4 },
{ 3,5,1,6,2,4 },
{ 3,6,5,2,1,4 },
{ 4,1,5,2,6,3 },
{ 4,2,1,6,5,3 },
{ 4,5,6,1,2,3 },
{ 4,6,2,5,1,3 },
{ 5,1,3,4,6,2 },
{ 5,3,6,1,4,2 },
{ 5,4,1,6,3,2 },
{ 5,6,4,3,1,2 },
{ 6,2,4,3,5,1 },
{ 6,3,2,5,4,1 },
{ 6,4,5,2,3,1 },
{ 6,5,3,4,2,1 },
};
string origin;
string after;
string all;
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	while (cin >> all)
	{
		origin = all.substr(0,6);
		after = all.substr(6, 12);
	//	cout << origin << endl;
	//	cout << after << endl;
		int ok = 0;
		for (int i = 0; i < 24; i++)
		{
			string temp;
			for (int j = 0; j < 6; j++)
				temp += origin[permu[i][j]-1];
			if (temp==after) { ok = 1; break; }
		}
		if (ok)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;
	}
	return 0;
}