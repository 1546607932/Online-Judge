#include<iostream>
#include<set>
using namespace std;
struct ducci
{
	int n;
	int seq[15];
	void init()
	{
		for (int i = 0; i < 15; i++)
			seq[i] = 0;
	}
	int empty()
	{
		for (int i = 0; i < 15; i++)
			if (seq[i] != 0)
				return 0;
		return 1;
	}
	void change()
	{
		int temp = seq[0];
		for (int i = 0; i < n - 1; i++)
			seq[i] = abs(seq[i] - seq[i + 1]);
		seq[n - 1] = abs(seq[n - 1] - temp);
	}
	void print()
	{
		for (int i = 0; i < n; i++)
			cout << seq[i] << ' ';
		cout << endl;
	}
	ducci(int n) :n(n) { init(); }
};
bool operator<(ducci a,ducci b)
{
	for (int i = 0; i < 15; i++)
		if (a.seq[i] < b.seq[i])
			return 1;
		else if (a.seq[i] > b.seq[i])
			return 0;
	return 0;
}
set<ducci> s;
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int flag = 0;	//0表示为0
		s.clear();
		int n;
		cin >> n;
		ducci d(n);
		for (int i = 0; i < n; i++)
			cin >> d.seq[i];

		while (1)
		{
			if (d.empty())	break;
			else if (s.find(d) == s.end())
				s.insert(d);
			else
			{
				flag = 1;
				break;
			}
			d.change();
//			d.print();
		}
		if (flag)
			cout << "LOOP" << endl;
		else
			cout << "ZERO" << endl;
	}
	return 0;
}