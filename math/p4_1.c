/*
 * special multiple
 * 1s 32M
 * input:
 * 123 45(<1000000000)
 * output:
 * 54(1*4+1*5+2*4+2*5+3*4+3*5)
 */
#include <stdio.h>

int main()
{
	int a,b;
	int buf1[20], buf2[20];
	int size1, size2;
	int ans;
	int i, j;

	while (scanf("%d%d", &a, &b) != EOF) {
		size1 = 0;
		size2 = 0;
		while (a != 0) {
			buf1[size1++] = a % 10;
			a /= 10;
		}
		while (b != 0) {
			buf2[size2++] = b % 10;
			b /= 10;
		}
		ans = 0;
		for (i = 0; i < size1; i++)
			for (j = 0; j < size2; j++)
				ans += buf1[i] * buf2[j];
		printf("%d\n", ans);
	}

	return 0;
}