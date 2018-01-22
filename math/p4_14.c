/*
 * factorial of big integer
 * 3s 128M
 * input:(0 <= N <= 1000)
 * 4
 * 5
 * 15
 * output:
 * 24
 * 120
 * 1307674368000
 */
#include <stdio.h>
#include <string.h>

struct bigInteger {
	int digit[1000];
	int size;
}a;

void init(struct bigInteger *ret)
{
	int i;
	for (i = 0; i < 1000; i++) {
		ret->digit[i] = 0;
	}
	ret->size =0;
}

void set(int x)
{
	init(&a);
	do {
		a.digit[a.size++] = x % 10000;
		x /= 10000;
	} while (x != 0);
}

void output()
{
	int i;
	for (i = a.size - 1; i >= 0; i--) {
		if (i != a.size - 1) printf("%04d", a.digit[i]);
		else printf("%d", a.digit[i]);
	}
	printf("\n");
}

struct bigInteger multiply(int x)
{
	struct bigInteger ret;
	int carry = 0;
	int tmp;
	int i;
	init(&ret);
	for (i = 0; i < a.size; i++) {
		tmp = x * a.digit[i] + carry;
		carry = tmp / 10000;
		tmp %= 10000;
		ret.digit[ret.size++] = tmp;
	}
	if (carry != 0)
		ret.digit[ret.size++] = carry;
	return ret;
}

int main()
{
	int n;
	int i;
	while (scanf("%d", &n) != EOF) {
		set(1);
		for (i = 1; i <= n; i++)
			a = multiply(i);
		output();
	}

	return 0;
}