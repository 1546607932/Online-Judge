#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;
string aim;
const double eps = 1e-6;
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	while (cin >> aim)
	{
		double a;
		int b;
		int len = aim.length();
		for (int i = 0; i < len; i++)
			if (aim[i] == 'e')
				aim[i] = ' ';
		stringstream line(aim);
		line >> a >> b;
		if (a == 0 && b == 0)
			break;
		//处理输入
		int M, E;
		for (M = 0; M <= 9; M++)
		{
			double temp = log10(1 - 1.0 / pow(2, M + 1));
			E = round(log2((b + log10(a) - temp) / log10(2) + 1));
			if (fabs(b + log10(a) - temp - (pow(2, E) - 1)*log10(2))<eps)
				cout << M << ' ' << E << endl;
		}
	}
	return 0;
}