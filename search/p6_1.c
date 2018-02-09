/*
 * enumeration
 * 100 chicken problem
 * 1s 32M
 * input:
 * 40
 * x=0,y=0,z=100
 * x=1,y=1,z=99
 * x=0,y=2,z=98
 * x=1,y=0,z=99
 */
#include <stdio.h>

int main()
{
	int n;
	int x, y, z;
	
	while (scanf("%d", &n) != EOF) {
		for (x = 0; x <= 100; x++) {
			for (y = 0; y <= 100 - x; y++) {
				z = 100 - x - y;
				if (x * 5 * 3 + y * 3 * 3 + z <= n * 3)
					printf("x=%d,y=%d,z=%d\n", x, y, z);
			}
		}
		printf("--------------\n");
	}

	return 0;
}