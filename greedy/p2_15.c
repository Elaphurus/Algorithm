/*
not AC this summer 1s 128M
input:
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 19
0
output:
5
*/
#include <stdio.h>
#include <stdlib.h>

struct program {
	int startTime;
	int endTime;
}buf[100];

int cmp(const void *x, const void *y) {
	return ((struct program*)x)->endTime - ((struct program*)y)->endTime;
}

int main() {
	int n;
	int i;
	int currentTime;
	int ans;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) {
			break;
		}
		for (i = 0; i < n; i++) {
			scanf("%d%d", &buf[i].startTime, &buf[i].endTime);
		}
		printf("----------\n");
		qsort(buf, n, sizeof(struct program), cmp);
		currentTime = 0;
		ans = 0;
		for (i = 0; i < n; i++) {
			if (currentTime <= buf[i].startTime) {
				currentTime = buf[i].endTime;
				ans++;
				printf("%d %d\n", buf[i].startTime, buf[i].endTime);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}