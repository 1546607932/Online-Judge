#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cctype>
using namespace std;
int m;
long long net[1000];
int cou = 0;

void input()
{
	string temp;
	getline(cin, temp);
	int len = temp.length();
	for (int i = 0; i < len; i++)
		if (!isdigit(temp[i]))
			temp[i] = ' ';
	stringstream line(temp);
	long long a, b, c, d;
	line >> a >> b >> c >> d;
	net[cou] = (a << 24) + (b << 16) + (c << 8) + d;
	cou++;
}
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	while (cin >> m)
	{
		cou = 0;
		long long mi, ma;
		getchar();
		for(int i=0;i<m;i++)
			input();

		mi = ma = net[0];
		for (int i = 1; i < m; i++)
		{
			mi = min(mi, net[i]);
			ma = max(ma, net[i]);
		}
		int count = 33;
		for (long long cur = ((long long)1 << 32); cur > 0;cur/=2)
		{
			if ((cur&mi) != (cur&ma))
				break;
			else if (count == 0)
				break;
			else
				count--;
		}
		(mi >>= count) <<= count;
		cout << (mi >> 24) << '.' << (mi % ((long long)1 << 24) >> 16) << '.' << (mi % ((long long)1 << 16) >> 8) << '.' << mi % (1 << 8) << endl;
		long long yan = ((long long)1 << 32) - 1;
		yan = yan >> count;
		yan = yan << count;
		cout << (yan >> 24) << '.' << (yan % ((long long)1 << 24) >> 16) << '.' << (yan % ((long long)1 << 16) >> 8) << '.' << yan % (1 << 8) << endl;
	}
	return 0;
}