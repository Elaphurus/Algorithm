/*
 * MST-road building
 * 1s 128M
 * input:
 * 3(n < 100)
 * 1 2 1
 * 1 3 2
 * 2 3 4
 * 0
 * output:
 * 3
 */
#include <stdio.h>
#include <stdlib.h>

#define N 101

int tree[N];

int findRoot(int x)
{
	int tmp;

	if (tree[x] == -1)
		return x;
	else {
		tmp = findRoot(tree[x]);
		tree[x] = tmp;
		return tmp;
	}
}

struct edge {
	int a, b;
	int cost;
}edge[6000];

int cmp(const void *x, const void *y)
{
	return ((struct edge *)x)->cost - ((struct edge *)y)->cost;
}

int main()
{
	int n;
	int ans;
	int a, b;
	int i;

	while (scanf("%d", &n) != EOF && n != 0) {
		for (i = 1; i <= n * (n - 1) / 2; i++) {
			scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].cost);
		}
		qsort(edge + 1, n * (n - 1) / 2, sizeof(struct edge), cmp);
		for (i = 1; i <= n; i++) {
			tree[i] = -1;
		}
		ans = 0;
		for (i = 1; i< n * (n - 1) / 2; i++) {
			a = findRoot(edge[i].a);
			b = findRoot(edge[i].b);
			if (a != b) {
				tree[a] = b;
				ans += edge[i].cost;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}