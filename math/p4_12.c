/*
 * binary power
 * input:(1 <= A,B <= 10000)
 * 2 3
 * 12 6
 * 6789 10000
 * 0 0
 * output:
 * 8
 * 984
 * 1
 */
#include <stdio.h>

int main()
{
	int a,b;
	int ans;
	while (scanf("%d%d", &a, &b) != EOF) {
		if (a == 0 && b == 0) break;
		ans = 1;
		while (b != 0) {
			if (b % 2 == 1) {
				ans *= a;
				ans %= 1000;
			}
			b /= 2;
			a *= a;
			a %= 1000;
		}
		printf("%d\n", ans);
	}

	return 0;
}