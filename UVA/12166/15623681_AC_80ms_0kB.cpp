#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
#include<cmath>
#include<map>
using namespace std;

typedef long long LL;

const int INF = 100000000;

LL weight;
int depth;
int total;
string line;
map<LL, int> times;
int maxtime;

void get_times()
{
	times.clear();
	total = 0;
	maxtime = 0;
	depth = 0;
	getline(cin, line);
	int len = line.length();
	for (int i = 0; i < len; i++)
	{
		if (line[i] == '[')
			depth++;
		else if (line[i] == ']')
			depth--;
		else if(isdigit(line[i]))
		{
			LL value = line[i] - '0';
			for (int k = i + 1; k < len; k++)
				if (isdigit(line[k]))
				{
					value = value * 10 + line[k]-'0';
					i = k;
				}
				else
					break;
			weight = pow(2, depth) * value;
			if (times.find(weight) == times.end())
				times[weight] = 1;
			else
				times[weight]++;
			maxtime = max(maxtime, times[weight]);
			total++;
		}
	}
}

int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int T;
	scanf("%d\n", &T);
	while (T--)
	{
		get_times();
		cout << total-maxtime << endl;
	}
	return 0;
}