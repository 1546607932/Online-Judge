#include<iostream>
using namespace std;
char table[11][10];
int Jx, Jy;
int Gx, Gy;
int ax, ay;
pair<int, int> dir[4];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int is_valid(int x, int y)
{
	if (x > 0 && x < 11 && y>0 && y < 10)
		return 1;
	else
		return 0;
}
int horse()
{
	if (is_valid(ax + 2, ay + 1) && table[ax + 2][ay + 1] == 'H'&&table[ax + 1][ay + 1] == ' ')
		return 0;
	if (is_valid(ax + 2, ay - 1) && table[ax + 2][ay - 1] == 'H'&&table[ax + 1][ay - 1] == ' ')
		return 0;
	if (is_valid(ax + 1, ay - 2) && table[ax + 1][ay - 2] == 'H'&&table[ax + 1][ay - 1] == ' ')
		return 0;
	if (is_valid(ax - 1, ay - 2) && table[ax - 1][ay - 2] == 'H'&&table[ax - 1][ay - 1] == ' ')
		return 0;
	if (is_valid(ax - 2, ay - 1) && table[ax - 1][ay - 2] == 'H'&&table[ax - 1][ay - 1] == ' ')
		return 0;
	if (is_valid(ax - 2, ay + 1) && table[ax - 2][ay + 1] == 'H'&&table[ax - 1][ay + 1] == ' ')
		return 0;
	if (is_valid(ax - 1, ay + 2) && table[ax - 1][ay + 2] == 'H'&&table[ax - 1][ay + 1] == ' ')
		return 0;
	if (is_valid(ax + 1, ay + 2) && table[ax + 1][ay + 2] == 'H'&&table[ax + 1][ay + 1] == ' ')
		return 0;
	return 1;
}
int cannon()
{
	int flag = 0;
	for (int i = ay + 1; i < 10; i++)
		if (!flag&&table[ax][i] != ' ')
			flag = 1;
		else if (flag&&table[ax][i] == 'C')
			return 0;
		else if (flag&&table[ax][i] != ' ')
			break;
	flag = 0;
	for (int i = ay-1; i > 0; i--)
		if (!flag&&table[ax][i] != ' ')
			flag = 1;
		else if (flag&&table[ax][i] == 'C')
			return 0;		
		else if (flag&&table[ax][i] != ' ')
			break;
	flag = 0;
	for (int i = ax + 1; i < 11; i++)
		if (!flag&&table[i][ay] != ' ')
			flag = 1;
		else if (flag&&table[i][ay] == 'C')
			return 0;	
		else if (flag&&table[i][ay] != ' ')
			break;
	flag = 0;
	for (int i = ax - 1; i > 0; i--)
		if (!flag&&table[i][ay] != ' ')
			flag = 1;
		else if (flag&&table[i][ay] == 'C')
			return 0;
		else if (flag&&table[i][ay] != ' ')
			break;
	return 1;
}
int car()
{
	//横向检测
	for (int i = ay + 1; i < 10; i++)
		if (table[ax][i] == 'R')
			return 0;
		else if (table[ax][i] == ' ')
			continue;
		else break;
	for (int i = ay - 1; i > 0; i--)
		if (table[ax][i] == 'R')
			return 0;
		else if (table[ax][i] == ' ')
			continue;
		else break;
	//纵向检测
	for (int i = ax + 1; i < 11; i++)
		if (table[i][ay] == 'R')
			return 0;
		else if (table[i][ay] == ' ')
			continue;
		else break;
		for (int i = ax - 1; i < 11; i--)
			if (table[i][ay] == 'R')
				return 0;
			else if (table[i][ay] == ' ')
				continue;
			else break;
	return 1;
}
int general()
{
	if (ay != Gy)
		return 1;
	else for (int i = ax + 1; i < Gx; i++)
		if (table[i][ay] != ' ')
			return 1;
	return 0;
}
void memdir()
{
	for (int i = 0; i < 4; i++)
	{
		dir[i].first = dx[i];
		dir[i].second = dy[i];
	}
}
void print_table()
{
		for (int i = 1; i < 11; i++)
		{
			for (int j = 1; j < 10; j++)
				cout << table[i][j] << ' ';
			cout << endl;
		}

}
int is_zhaomian()
{
	if (Jy != Gy)
		return 0;
	else
		for (int i = Jx + 1; i < Gx; i++)
			if (table[i][Jy] != ' ')
				return 0;
	return 1;
}
int is_safe()
{
	table[Jx][Jy] = ' ';
	if (is_zhaomian())
		return 1;
	for (int i = 0; i < 4; i++)
	{
		ax = Jx + dir[i].first;
		ay = Jy + dir[i].second;
		if (ax > 0 && ax < 4 && ay>3 && ay < 7)
		{
			if (horse() && cannon() && car() && general()) //都打不死就返回安全
				return 1;
		}
	}
	return 0;	//全都不安全，返回不安全
}
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	memdir();
	int n;
	while (cin >> n >> Jx >> Jy)
	{
		if (!n&&!Jx&&!Jy)
			break;
		char temp;	int x, y;
		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 10; j++)
				table[i][j] = ' ';
		table[Jx][Jy] = 'J';
		for (int i = 0; i < n; i++)
		{
			cin >> temp >> x >> y;
			table[x][y] = temp;
			if (temp == 'G') { Gx = x; Gy = y; }
		}
		//初始化信息
	//	print_table();
		if (is_safe())
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}