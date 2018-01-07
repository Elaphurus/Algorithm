/*
FatMouse' Trade
input:
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1
output:
13.333
31.500
*/
#include <stdio.h>
#include <stdlib.h>

struct goods {
	double j;
	double f;
	double s;
}buf[1000];

int cmp(const void *x, const void *y) {
	double cmpr = ((struct goods*)y)->s - ((struct goods*)x)->s;
	if (cmpr > 0.000001)
		return 1;
	else
		return -1;
}

int main() {
	double m;
	int n;
	int idx;
	double ans;
	int i;
	while (scanf("%lf%d", &m, &n) != EOF) {
		if (m == -1 && n == -1)
			break;
		for (i = 0; i < n; i++) {
			scanf("%lf%lf", &buf[i].j, &buf[i].f);
			buf[i].s = buf[i].j / buf[i].f;
		}
		qsort(buf, n, sizeof(struct goods), cmp);
		idx = 0;
		ans = 0;
		while (m > 0 && idx < n) {
			if (m > buf[idx].f) {
				ans += buf[idx].j;
				m -= buf[idx].f;
			} else {
				ans += m * buf[idx].s;
				m = 0;
			}
			idx++;
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}