#include<set>
#include<iostream>
using namespace std;
set<int> digit;
int n;
bool is_different(int mu)
{
	digit.clear();
	int zi = mu * n;
	if (zi > 98765)
		return 0;
	for (int i = 0; i < 5; i++)
	{
		digit.insert(mu % 10);
		mu /= 10;
		digit.insert(zi % 10);
		zi /= 10;
	}
	return digit.size() == 10;
}
int main()
{
	int count = 0;
	while ((cin >> n) && n)
	{
		if (count++)
			cout << endl;
		int flag = 0;
		for (int i = 1234; i < 50000; i++)
			if (is_different(i))
			{
				printf("%d / %05d = %d\n", i*n, i, n);
				flag = 1;
			}
		if (!flag)
			printf("There are no solutions for %d.\n", n);
	}
	return 0;
}