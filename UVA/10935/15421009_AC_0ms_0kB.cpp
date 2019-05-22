#include<iostream>
#include<queue>
using namespace std;
int main()
{
//	freopen("d:\\sample.txt", "r", stdin);
//	freopen("d:\\test.txt", "w", stdout);
	int n;
	while ((cin >> n)&&n)
	{
		queue<int> card;
		for (int i = 1; i <= n; i++)
			card.push(i);
		//初始化条件
		printf("Discarded cards:");
		if (n == 1)
		{
			cout << endl;
			printf("Remaining card: %d\n", card.front());
			continue;
		}
		while (card.size() > 2)
		{
			cout <<' '<< card.front() << ',';
			card.pop();
			card.push(card.front());
			card.pop();
		}
		cout <<' '<< card.front() << endl;
		card.pop();
		printf("Remaining card: %d\n", card.front());
	}
	return 0;
}