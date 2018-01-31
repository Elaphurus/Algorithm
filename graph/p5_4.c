/*
 * Freckles
 * 1s 128M
 * input:
 * 3(0 < n <= 100)
 * 1.0 1.0
 * 2.0 2.0
 * 2.0 4.0
 * output:
 * 3.41
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	int a,b;
	double cost;
}edge[6000];

int cmp(const void *x, const void *y)
{
	double diff = ((struct edge *)x)->cost - ((struct edge *)y)->cost;
	if (diff >= 0)
		return 1;
	else return -1;
}

struct point {
	double x, y;
}list[N];

double getDistance(struct point p, struct point q)
{
	double tmp = (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
	return sqrt(tmp);
}

int main()
{
	int n;
	int size;
	double ans;
	int a, b;
	int i, j;

	while (scanf("%d", &n) != EOF) {
		for (i = 1; i <= n; i++) {
			scanf("%lf%lf", &list[i].x, &list[i].y);
		}
		size = 0;
		for (i = 1; i <= n; i++) {
			for (j = i + 1; j <= n; j++) {
				edge[size].a = i;
				edge[size].b = j;
				edge[size].cost = getDistance(list[i], list[j]);
				size++;
			}
		}
		qsort(edge, size, sizeof(struct edge), cmp);
		for (i = 1; i <= n; i++) {
			tree[i] = -1;
		}
		ans = 0;
		for (i = 0; i < size; i++) {
			a = findRoot(edge[i].a);
			b = findRoot(edge[i].b);
			if (a != b) {
				tree[a] = b;
				ans += edge[i].cost;
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}