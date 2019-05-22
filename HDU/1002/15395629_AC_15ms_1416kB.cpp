//用两个int数组存储两个大数的每一位
//使第一个数的位数总不小于第二个数
//把第二个数每一位加到相应的第一个数的位上
//对第一个数进行进位处理
//输出结果;
#include<iostream>
#include<string>
using namespace std;
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);		//用于测试
//	freopen("d:\\test.txt", "w", stdout);
	int kase;		//需处理的情况数
	int count = 0;	//第count次，用于格式中的输出
	cin >> kase;
	while (kase--)
	{
		int flag = 0;
		string a, b;	//a是第一个数，b是第二个数
		int num1[1005], num2[1005];

		if (count)
			cout << endl;	//两种情况中间的空行
		printf("Case %d:\n", ++count);	//格式

		cin >> a >> b;		//暂时输入两个数到字符串，操作使第一个字符串位数不小于第二个字符串
		int alen = a.length(), blen = b.length();
		if (alen < blen)
		{
			flag = 1;
			swap(a, b);
			swap(alen, blen);
		}

		for (int i = 0; i < alen; i++)		//把对应位上的数存入数组中
			num1[i] = a[i] - '0';
		for (int j = 0; j < blen; j++)
			num2[j] = b[j] - '0';

		int i = alen - 1;				//逐位累加到第一个数
		int j = blen - 1;
		while (i >= 0 && j >= 0)
		{
			num1[i] += num2[j];
			i--;
			j--;
		}

		for (int k = alen - 1; k > 0; k--)	//进位处理，第一位不用进位直接输出
		{
			if (num1[k] >= 10)
				num1[k - 1]++;	//最多加一
			num1[k] %= 10;
		}
		if(flag==0)
		cout << a << ' ' << '+' << ' ' << b << ' ' << '=' << ' ';	//输出a + b = 
		else
			cout << b << ' ' << '+' << ' ' << a << ' ' << '=' << ' ';
		for (int i = 0; i < alen; i++)								//输出a+b的结果
			cout << num1[i];
		cout << endl;
	}
	return 0;
}