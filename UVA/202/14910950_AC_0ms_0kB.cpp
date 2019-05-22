#include<iostream>
using namespace std;
int a[10000], b[10000];//a存余数，b存整数
int first;
int point;
int function(int num1,int num2)
{
	int count = 0;
	while (1)
	{
		a[count] = num1 % num2;
		b[count] = num1 / num2;
		num1 = a[count];
		num1 *= 10;
		for (int i = 0; i < count; i++)
			if (a[i] == a[count])
			{
				first = i;
				return count - i;
			}
		count++;
	}
}
int get_point(int num1,int num2)
{
	int count = 0;
	int temp;
	temp = num1 / num2;
	if (temp == 0)
		return 0;
	while (!temp)
	{
		count++;
		temp /= 10;
	}
	return count;
}
int main()
{
	int head = 0;
	int num1, num2;
	while (cin >> num1 >> num2)
	{
		int temp = function(num1,num2);
		point = get_point(num1,num2);
		cout << num1 << '/' << num2 << " = ";
		for (int i = 0; i <= first; i++)
		{
			cout << b[i];
			if (first == 0||i==point)
				cout << '.';
		}
		cout << '(';
		for (int i = first + 1; i <= first + temp; i++)
		{
			cout << b[i];
			if (i == first + 50-(first-point))
			{
				cout << "...";
				break;
			}
		}
		cout << ')' << endl;
		printf("   %-d = number of digits in repeating cycle\n", temp);
		cout << endl;
	}
	return 0;
}