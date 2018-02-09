/*
 * BFS
 * big escape
 * 2s 32M
 * input:
 * 1
 * 3 3 4(1<=A,B,C<=50) 20(1<=T<=1000)
 * 0 1 1 1
 * 0 0 1 1
 * 0 1 1 1
 * 1 1 1 1
 * 1 0 0 1
 * 0 1 1 1
 * 0 0 0 0
 * 0 1 1 0
 * 0 1 1 0
 * output:
 * 11
 */
#include <stdio.h>
#include <queue>

using namespace std;

bool mark[50][50][50];
int maze[50][50][50];

struct n {
	int x, y, z;
	int t;
};

queue<n> q;

int go[][3] = {
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1
};

int BFS(int a, int b, int c)
{
	int i;

	while (!q.empty()) {
		n now = q.front();
		q.pop();
		for (i = 0; i < 6; i++) {
			int nx = now.x + go[i][0];
			int ny = now.y + go[i][1];
			int nz = now.z + go[i][2];
			
			if (nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c)
				continue;
			if (maze[nx][ny][nz] == 1)
				continue;
			if (mark[nx][ny][nz] == true)
				continue;

			n tmp;
			tmp.x = nx;
			tmp.y = ny;
			tmp.z = nz;
			tmp.t = now.t + 1;
			q.push(tmp);
			mark[nx][ny][nz] = true;
			if (nx == a - 1 && ny == b - 1 && nz == c - 1)
				return tmp.t;
		}
	}
	return -1;
}

int main()
{
	int T;
	int i, j, k;

	scanf("%d", &T);
	while (T--) {
		int a, b, c, t;
		scanf("%d%d%d%d", &a, &b, &c, &t);
		for (i = 0; i < a; i++) {
			for (j = 0; j < b; j++) {
				for (k = 0; k < c; k++) {
					scanf("%d", &maze[i][j][k]);
					mark[i][j][k] = false;
				}
			}
		}
		while (!q.empty()) {
			q.pop();
		}
		mark[0][0][0] = true;
		n tmp;
		tmp.t = tmp.x = tmp.y = tmp.z = 0;
		q.push(tmp);
		int rec = BFS(a, b, c);
		if (rec <= t)
			printf("%d\n", rec);
		else
			printf("-1\n");
	}
	return 0;
}