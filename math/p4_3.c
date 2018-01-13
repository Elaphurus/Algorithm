/*
 * another a+b
 * 1s 32M
 * input:
 * 8 1300 48(<=2^31-1)
 * 2 1 7
 * 0
 * output:
 * 2504
 * 1000
 */
#include <stdio.h>

int main()
{
	__int64 a, b;
	int m;
	__int64 ans[50];
	int size;
	int i;

	while (scanf("%d", &m) != EOF) {
		if (m == 0)
			break;

		scanf("%I64d%I64d", &a, &b);
		a = a + b;

		size = 0;
		do {
			ans[size++] = a % m;
			a /= m;
		} while (a != 0);
		for (i = size -1; i>=0; i--)
			printf("%I64d", ans[i]);
		printf("\n");
	}

	return 0;
}