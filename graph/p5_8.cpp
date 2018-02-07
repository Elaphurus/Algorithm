/*
 * Leagal or Not(topological sort)
 * 1s 128M
 * input:
 * 3 2(2 <= n, m <= 100)
 * 0 1
 * 1 2
 * 2 2
 * 0 1
 * 1 0
 * output:
 * YES
 * NO
 */
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[501];
queue<int> q;

int main()
{
	int inDegree[501];
	int n, m;
	int i;

	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0 && m == 0)
			break;
		for(i = 0; i < n; i++) {
			inDegree[i] = 0;
			edge[i].clear();
		}
		while (m--) {
			int a, b;
			scanf("%d%d", &a, &b);
			inDegree[b]++;
			edge[a].push_back(b);
		}
		while (!q.empty()) {
			q.pop();
		}
		for (i = 0; i < n; i++) {
			if (inDegree[i] == 0)
				q.push(i);
		}
		int cnt = 0;
		while (!q.empty()) {
			int nowP = q.front();
			q.pop();
			cnt++;
			for (i = 0; i < edge[nowP].size(); i++) {
				inDegree[edge[nowP][i]]--;
				if (inDegree[edge[nowP][i]] == 0)
					q.push(edge[nowP][i]);
			}
		}
		if (cnt == n)
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}