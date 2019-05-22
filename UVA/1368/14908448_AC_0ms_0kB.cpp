#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int acgt_number[256];
string t[50];
string aim;
int m, n;
int get_max()
{
	if (acgt_number['T'] > acgt_number['G'] && acgt_number['T'] > acgt_number['C'] && acgt_number['T'] > acgt_number['A'])
	{
		aim += 'T';
		return acgt_number['T'];
	}
	else if (acgt_number['G'] > acgt_number['C'] && acgt_number['G'] > acgt_number['A'])
	{
		aim += 'G';
		return acgt_number['G'];
	}
	else if (acgt_number['C'] > acgt_number['A'])
	{
		aim += 'C';
		return acgt_number['C'];
	}
	aim += 'A';
	return acgt_number['A'];
}
int get_number(int a)
{
	memset(acgt_number, 0, sizeof(acgt_number));
	for (int i = 0; i < m; i++)
		acgt_number[t[i][a]]++;
	return m - get_max();
}
int main()
{
	int times;
	cin >> times;
	while (times--)
	{
		cin >> m >> n;
		aim.clear();
		int total = 0;
		for (int i = 0; i < m; i++)
			cin >> t[i];
		for (int i = 0; i < n; i++)
			total += get_number(i);
		cout << aim << endl;
		cout << total << endl;
	}
	return 0;
}