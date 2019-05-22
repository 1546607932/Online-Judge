#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 1000000000;
int n, m;
int house[31][31];
int water;
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int kase = 0;
	while ((cin >> n >> m)&&n&&m)
	{
		int ma = -INF;
		int mi = INF;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &house[i][j]);
				ma = max(ma, house[i][j]);
				mi = min(mi, house[i][j]);
			}
		cin >> water;
		int vol = n * m;

		double water_height = mi;
		int sanked = 0;
		for (int height = mi; height <= ma; height++)
		{
			int hei;//比当前楼高的楼的数目
			int cou;//当前高度的楼的数目
			int need = 0;//再淹一层需要的水量
			hei = 0; cou = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (house[i][j] > height)
						hei++;
					else if (house[i][j] == height)
						cou++;
			need = (vol - hei) * 100;
			if (height == ma&&water!=0) { sanked += cou; water_height = height + double(water) / need; break; }
			if (water > need) { sanked += cou; water -= need; }
			else if (water == need) { sanked += cou; water_height = height + 1; break; }
			else if (water != 0 && water < need) { sanked += cou; water_height = height + double(water) / need; break; }
			else if (water == 0) { break; }
		}
		printf("Region %d\n", ++kase);
		printf("Water level is %.2lf meters.\n", water_height);
		printf("%.2lf percent of the region is under water.\n", double(sanked*100) / n / m);
		cout << endl;
	}
	return 0;
}