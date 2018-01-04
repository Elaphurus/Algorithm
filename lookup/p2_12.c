/*
linear lookup
input:
2(1<=n<=200)
1 3
0
output:
-1
*/
#include <stdio.h>
int main() {
	int buf[200];
	int n, x;
	int ans;
	int i;
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%d", &buf[i]);
		}
		ans = -1;
		scanf("%d", &x);
		for (i = 0; i < n; i++) {
			if (x == buf[i]) {
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}