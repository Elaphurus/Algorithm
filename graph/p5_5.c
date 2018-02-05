/*
 * Floyd
 * 1s 128M
 * input:
 * 2(<=100) 1(<=10000)
 * 1 2 3
 * 3 3
 * 1 2 5
 * 2 3 5
 * 3 1 2
 * 0 0
 * output:
 * 3
 * 2
 */
#include <stdio.h>

int ans[101][101];

int main()
{
	int n, m;
	int i, j, k;
	int a, b, c;
	
	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0 && m == 0)
			break;
		for (i = 0; i <= n; i++) {
			for (j = 0; j <= n; j++) {
				ans[i][j] = -1;
			}
			ans[i][i] = 0;
		}
		while (m--) {
			scanf("%d%d%d", &a, &b, &c);
			ans[a][b] = ans[b][a] = c;
		}
		for (k = 1; k <= n; k++) {
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					if (ans[i][k] == -1 || ans[k][j] == -1)
						continue;
					if (ans[i][j] == -1 || ans[i][k] + ans[k][j] < ans[i][j])
						ans[i][j] = ans[i][k] + ans[k][j];
				}
			}
		}
		printf("%d\n", ans[1][n]);
	}

	return 0;
}