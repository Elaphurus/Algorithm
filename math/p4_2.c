/*
 * a cute solution for p4_1
 */
#include <stdio.h>

int main()
{
	char a[11], b[11];
	int ans;
	int i, j;

	while (scanf("%s%s", a, b) != EOF) {
		ans = 0;
		for (i = 0; a[i] != 0; i++)
			for (j = 0; b[j] != 0; j++)
				ans += (a[i] - '0') * (b[j] - '0');
		printf("%d\n", ans);
	}

	return 0;
}