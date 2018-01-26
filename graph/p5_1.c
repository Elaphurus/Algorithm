/*
 * connected component
 * 1s 128M
 * input:
 * 4(n < 1000) 2(m)
 * 1 3
 * 4 3
 * 3 3
 * 1 2
 * 1 3
 * 2 3
 * 5 2
 * 1 2
 * 3 5
 * 999 0
 * 0
 * output:
 * 1
 * 0
 * 2
 */
#include <stdio.h>

#define N 1000

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

int main()
{
	int n, m;
	int a, b;
	int ans;
	int i;

	while (scanf("%d", &n) != EOF && n != 0) {
		scanf("%d", &m);
		for (i = 1; i <= n; i++)
			tree[i] = -1;
		while (m-- != 0) {
			scanf("%d%d", &a, &b);
			a = findRoot(a);
			b = findRoot(b);
			if (a != b)
				tree[a] = b;
		}
		ans = 0;
		for (i = 1; i <= n; i++) {
			if (tree[i] == -1)
				ans++;
		}
		printf("%d\n", ans - 1);
	}

	return 0;
}