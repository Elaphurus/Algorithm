/*
 * Dijkstra
 * 1s 128M
 * input:
 * 3(1 < n <= 1000) 2(0 < m < 100000)
 * 1 2 5 6
 * 2 3 4 5
 * 1 3
 * 0 0
 * output:
 * 9 11
 */
#include <stdio.h>
#include <vector>

using namespace std;

struct e {
	int next;
	int c;
	int cost;
};

vector<e> edge[1001];
int dis[1001];
int cost[1001];
bool mark[1001];

int main()
{
	int n, m;
	int s, t;
	int i, j;

	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0 && m == 0)
			break;
		for (i = 1; i <= n; i++) {
			edge[i].clear();
		}
		while (m--) {
			int a, b, c, cost;
			scanf("%d%d%d%d", &a, &b, &c, &cost);
			e tmp;
			tmp.c = c;
			tmp.cost = cost;
			tmp.next = b;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp);
		}
		scanf("%d%d", &s, &t);
		for (i = 0; i <= n; i++) {
			dis[i] = -1;
			mark[i] = false;
		}
		dis[s] = 0;
		mark[s] = true;
		int newP = s;
		for (i = 1; i < n; i++) {
			for (j = 0; j < edge[newP].size(); j++) {
				int t = edge[newP][j].next;
				int c = edge[newP][j].c;
				int co = edge[newP][j].cost;
				if (mark[t] == true)
					continue;
				if (dis[t] == -1 || dis[t] > dis[newP] + c || dis[t] == dis[newP] + c && cost[t] > cost[newP] + co) {
					dis[t] = dis[newP] + c;
					cost[t] = cost[newP] + co;
				}
			}
			int min = 123123123;
			for (j = 1; j <= n; j++) {
				if (mark[j] == true)
					continue;
				if (dis[j] == -1)
					continue;
				if (dis[j] < min) {
					min = dis[j];
					newP = j;
				}
			}
			mark[newP] = true;
		}
		printf("%d %d\n", dis[t], cost[t]);
	}

	return 0;
}