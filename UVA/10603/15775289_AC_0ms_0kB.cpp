#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct Node {
	int v[3];
	int dist;
	bool operator>(const Node& b)const {
		return dist > b.dist;
	}
	Node(int a, int b, int c, int d) :dist(d) {
		v[0] = a;
		v[1] = b;
		v[2] = c;
	}
};

const int maxn = 200 + 5;

int vis[maxn][maxn], dist[maxn];

void change(const Node& n) {
	for (int i = 0; i < 3; i++) {
		int d = n.v[i];
		if (dist[d] < 0 || n.dist < dist[d]) dist[d] = n.dist;
	}
}
void bfs(int a, int b, int c, int d) {
	memset(vis, 0, sizeof(vis));
	memset(dist, -1, sizeof(dist));

	int cap[3], dis;
	cap[0] = a; cap[1] = b; cap[2] = c; dis = 0;
	Node start(0, 0, cap[2], dis);
	priority_queue<Node, vector<Node>, greater<Node>> que;
	que.push(start);
	vis[0][0] = 1;
	
	while (!que.empty()) {
		Node temp = que.top(); que.pop();
		change(temp);
		if (dist[d] >= 0) break;

		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if (i != j && temp.v[i] && temp.v[j] != cap[j])
				{
					int amount = min(temp.v[i] + temp.v[j], cap[j]) - temp.v[j];
					Node newnode = temp;
					newnode.v[i] -= amount;
					newnode.v[j] += amount;
					newnode.dist += amount;
					if (!vis[newnode.v[0]][newnode.v[1]])
					{
						vis[temp.v[0]][temp.v[1]] = 1;
						que.push(newnode);
					}
				}
	}
}

void print_ans(int ans) {
	while (ans >= 0) {
		if (dist[ans] >= 0) {
			cout << dist[ans] << ' ' << ans << endl;
			return;
		}
		ans--;
	}
}
int main() {
	int T;
	int a, b, c, d;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		bfs(a, b, c, d);
		print_ans(d);
	}
	return 0;
}