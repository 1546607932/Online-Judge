#include<iostream>
#include<string>
#include<ctime>
using namespace std;
int c[10005][2];
int main()
{
	int k;
	while (cin >> k)
	{
		int x;
		int count = 0;
		for (unsigned long long i = k+1; i <= 2 * k; i++)
		{
			x = k * i / (i - k);
			if (k == x * i / (x + i))
			{
				c[count][0] = x;
				c[count][1] = i;
				count++;
			}
		}
		cout << count << endl;
		for(int i=0;i<count;i++)
			printf("1/%d = 1/%d + 1/%d\n",k,c[i][0],c[i][1]);
	}
	return 0;
}
