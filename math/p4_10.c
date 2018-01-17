/*
 * the number of prime factors
 * 1s 32M
 * input:
 * 120(1 < N < 10^9)
 * output:
 * 5
 */
#include <stdio.h>

int mark[100001];
int prime[100001];
int primeSize;

void init()
{
	int i, j;
	primeSize = 0;
	for (i = 2; i <= 100000; i++) {
		if (mark[i] == 1) continue;
		prime[primeSize++] = i;
		if (i >= 1000) continue;
		for (j = i * i; j <= 100000; j += i)
			mark[j] = 1;
	}
}

int main()
{
	int n;
	int ansPrime[30];
	int ansSize;
	int ansNum[30];
	int ans;
	int i;

	init();
	while (scanf("%d", &n) != EOF) {
		ansSize = 0;
		for (i = 0; i < primeSize; i++) {
			if (n % prime[i] == 0) {
				ansPrime[ansSize] = prime[i];
				ansNum[ansSize] = 0;
				while (n % prime[i] == 0) {
					ansNum[ansSize]++;
					n /= prime[i];
				}
				ansSize++;
				if (n == 1) break;
			}
		}
		if (n != 1) {
			ansPrime[ansSize] = n;
			ansNum[ansSize++] = 1;
		}
		ans = 0;
		for (i = 0; i < ansSize; i++)
			ans += ansNum[i];
		printf("%d\n", ans);
	}

	return 0;
}