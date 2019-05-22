#include<iostream>
#include<algorithm>
using namespace std;
char a[4];
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int count = 0;
	while (cin >> a[0] >> a[1] >> a[2] >> a[3])
	{
		if (a[0] == '0'&&a[1] == '0'&&a[2] == '0'&&a[3] == '0')
			break;
		sort(a, a + 4);
		char temp = EOF;
		do
		{
			if (a[0] == '0')
				continue;
			if (temp != a[0])
			{
				if(count++)
					cout << endl;
				cout << a[0] << a[1] << a[2] << a[3];
				temp = a[0];
				continue;
			}
			cout << ' ' << a[0] << a[1] << a[2] << a[3];
			temp = a[0];
		} while (next_permutation(a, a + 4));
		cout << endl;
	}
	return 0;
}