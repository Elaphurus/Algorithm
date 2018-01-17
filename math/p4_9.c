/*
 * prime selection
 * 1s 32M
 * input:
 * 100(2 <= n <= 10000)
 * output:(end with 1)
 * 11 31 41 61 71
 */
#include <stdio.h>

int prime[10000];
int primeSize;
int mark[10001];

void init()
{
	int i, j;
	for (i = 1; i <= 10000; i++)
		mark[i] = 0; // all be initialized to prime
	primeSize = 0;
	for (i = 2; i <= 10000; i++) {
		if (mark[i] == 1)
			continue;
		prime[primeSize++] = i;
		for (j = i * i; j <= 10000; j += i)
			mark[j] = 1;
	}
}

int main()
{
	int n;
	int isOutput;
	int i;
	init();
	while (scanf("%d", &n) != EOF) {
		isOutput = 0;
		for (i = 0; i < primeSize; i++) {
			if (prime[i] < n && prime[i] % 10 == 1)
				if (isOutput == 0) {
					isOutput = 1;
					printf("%d", prime[i]);
				} else
					printf(" %d", prime[i]);
		}
		if (isOutput == 0)
			printf("-1\n");
		else
			printf("\n");
	}

	return 0;
}