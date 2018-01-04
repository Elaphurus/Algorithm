/*
superposition of baskets
input:
5 @ W(size of outter basket is an odd between 0 and 80)
output:
 @@@ 
@WWW@
@w@W@
@WWW@
 @@@
*/
#include <stdio.h>
int main() {
	int outputBuf[82][82];
	char a, b, c;
	int n;
	int i, j, k;
	int x, y;
	int firstBasket = 1;
	while(scanf("%d %c %c", &n, &a, &b) == 3) {
		if(firstBasket == 1) {
			firstBasket = 0;
		}
		else {
			printf("\n"); // every two baskets seperated by a blank line
		}
		for(i = 1, j = 1; i <= n; i += 2, j++) { // j: number of circle from inside out; i: side length
			x = n / 2 + 1;
			y = x;
			x -= j - 1;
			y -= j - 1;
			c = j % 2 == 1 ? a : b;
			for(k = 1; k <= i; k++) {
				outputBuf[x + k - 1][y] = c; // left side
				outputBuf[x][y + k - 1] = c; // top
				outputBuf[x + i - 1][y + k - 1] = c; // down
				outputBuf[x + k - 1][y + i - 1] = c; // right
			}
		}
		if(n != 1) {
			outputBuf[1][1] = ' ';
			outputBuf[1][n] = ' ';
			outputBuf[n][1] = ' ';
			outputBuf[n][n] = ' ';
		}
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				printf("%c", outputBuf[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}