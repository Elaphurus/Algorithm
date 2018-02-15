/*
 * flood fill
 * 1s 32M
 * input:
 * 3 5
 * *@*@*
 * **@**
 * *@*@*
 * 1 8
 * @@****@*
 * 0 0
 * output:
 * 1
 * 2
 */
#include <stdio.h>

char maze[101][101];
bool mark[101][101];
int n, m;
int go[][2] = {
	1, 0,
	-1, 0,
	0, 1,
	0, -1,
	1, 1,
	1, -1,
	-1, -1,
	-1, 1
};

void DFS(int x, int y)
{
	int i;

	for (i = 0; i < 8; i++) {
		int nx = x + go[i][0];
		int ny = y + go[i][1];
		if (nx < 1 || nx > n || ny < 1 || ny > m)
			continue;
		if (maze[nx][ny] == '*')
			continue;
		if (mark[nx][ny] == true)
			continue;
		mark[nx][ny] = true;
		DFS(nx, ny);
	}
}

int main()
{
	int ans;
	int i, j;

	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0 && m == 0)
			break;
		for (i = 1; i <= n; i++) {
			scanf("%s", maze[i] + 1);
		}
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				mark[i][j] = false;
			}
		}
		ans = 0;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				if (mark[i][j] == true)
					continue;
				if (maze[i][j] == '*')
					continue;
				DFS(i, j);
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}