/*
 * conversion
 * 1s 32M
 * input:
 * 15 Aab3 7
 * output:
 * 210306( Aab3(15) = 210306(7) )
 */
#include <stdio.h>
#include <string.h>

int main()
{
	int a, b;
	char str[40];
	int tmp, len, c;
	int x, i;
	char ans[40];
	int size;

	while (scanf("%d%s%d", &a, str, &b) != EOF) {
		tmp = 0;
		len = strlen(str);
		c = 1;

		for (i = len - 1; i >= 0; i--) {
			if (str[i] >= '0' && str[i] <= '9')
				x = str[i] - '0';
			else if (str[i] >= 'a' && str[i] <= 'z')
				x = str[i] - 'a' + 10;
			else
				x = str[i] - 'A' + 10;
			tmp += x * c;
			c *= a;
		}

		size = 0;
		do {
			x = tmp % b;
			ans[size++] = (x < 10) ? x + '0' : x - 10 + 'A';
			tmp /= b;
		} while (tmp);
		for (i = size - 1; i >= 0; i--)
			printf("%c", ans[i]);
		printf("\n");
	}

	return 0;
}