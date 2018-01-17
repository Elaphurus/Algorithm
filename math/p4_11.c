/*
 * n! % (a^k) = 0, max(k) = ?
 * 1s 32M
 * input:
 * 6(2 <= n <= 1000) 10(2 <= a <= 1000)
 * output:
 * 1
 */
#include <stdio.h>
#include <string.h>

int mark[1001];
int prime[1001];
int primeSize;

void init()
{
	int i, j;
	primeSize = 0;
	for (i = 2; i <= 1000; i++) {
		if (mark[i] == 1) continue;
		//mark[i] = 1;
		prime[primeSize++] = i;
		for (j = i * i; j <= 1000; j += i)
			mark[j] = 1;
	}
}

int cnt[1001];
int cnt2[1001];

int main()
{
	int n, a;
	int ans;
	int t, i;
	init();
	while (scanf("%d%d", &n, &a) == 2) {
		for (i = 0; i < primeSize; i++)
			cnt[i] = cnt2[i] = 0;
		/* resolve n! */
		for (i = 0; i < primeSize; i++) {
			t = n;
			while (t) {
				cnt[i] += t / prime[i];
				t /= prime[i];
			}
		}
		ans = 123123123;
		/* resolve a */
		for (i = 0; i < primeSize; i++) {
			while (a % prime[i] == 0) {
				cnt2[i]++;
				a /= prime[i];
			}
			if (cnt2[i] == 0) continue;
			if (cnt[i] / cnt2[i] < ans)
				ans = cnt[i] / cnt2[i];
		}
		printf("%d\n", ans);
	}

	return 0;
}
