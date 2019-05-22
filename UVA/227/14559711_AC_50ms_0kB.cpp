#include<iostream>
#include<cstring>
using namespace std;
char puzzle[6][6];
int sx, sy, nx, ny;
char mani[1000];
int flag = 1;
int cou = 0;
char c;
int coun = 0;
void change(int a)
{
	sx = nx;
	sy = ny;

	if (mani[a] == 'A')
		ny -= 1;
	else if (mani[a] == 'B')
		ny += 1;
	else if (mani[a] == 'L')
		nx -= 1;
	else if (mani[a] == 'R')
		nx += 1;
	if (nx < 0 || ny < 0 || nx>4 || ny>4)
		flag = 0;
	if (flag)
	{
		puzzle[sy][sx] = puzzle[ny][nx];
		puzzle[ny][nx] = ' ';
	}
}
int main()
{
	while (1)
	{
		flag = 1;
		if(coun++)
			scanf("%c", &c);
		for (int i = 0; i < 5; i++)
		{
			cin.getline(puzzle[i], 6);
			if (puzzle[i][0] == 'Z')
			{
				return 0;
			}
		}
		for (int i = 0;; i++)
		{
			cin >> mani[i];
			if (mani[i] == '0')
			{
				mani[i] = '\0';
				break;
			}
		}
		static int count = 0;
		if (count++)
			cout << endl;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
			{
				if (puzzle[i][j] == ' ' || puzzle[i][j] == '\0')
				{
					sx = j;
					sy = i;
					nx = j;
					ny = i;
					break;
				}
			}

		for (unsigned i = 0; i < strlen(mani); i++)
		{
			change(i);
		}

		cout << "Puzzle #" << ++cou << ':' << endl;
		if (flag == 1)
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					if (j != 4)
						cout << puzzle[i][j] << ' ';
					else
						cout << puzzle[i][j] << endl;
		else
			cout << "This puzzle has no final configuration." << endl;
	}
}
