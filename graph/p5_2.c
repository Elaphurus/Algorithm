/*
 * the biggest connected component
 * input:
 * 4(0 <= n <= 10000000)
 * 1 2
 * 3 4
 * 5 6
 * 1 6
 * output:
 * 4
 */
#include <stdio.h>

#define N 10000001

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

int sum[N];

int main()
{
	int n;
	int a, b;
	int ans;
	int i;

	while (scanf("%d", &n) != EOF) {
		for (i = 1; i <= N; i++) {
			tree[i] = -1;
			sum[i] = 1;
		}
		while (n-- != 0) {
			scanf("%d%d", &a, &b);
			a = findRoot(a);
			b = findRoot(b);
			if (a != b) {
				tree[a] = b;
				sum[b] += sum[a];
			}
		}
		ans = 1;
		for (i = 1; i <= N; i++) {
			if (tree[i] == -1 && sum[i] > ans)
				ans = sum[i];
		}
		printf("%d\n", ans);
	}

	return 0;
}