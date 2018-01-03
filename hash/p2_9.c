/*
hash
sort 1s 128M 
output the big m of n(0<n<1000000) different numbers[-500000,500000]
input:
5 3
3 -35 92 213 -644
output:
213 92 3
*/
#include <stdio.h>
#define OFFSET 500000
int hash[1000001] = {0};
int main() {
	int n, m;
	int i, x;
	while(scanf("%d%d", &n, &m) != EOF) {
		for(i = 1; i <= n; i++) {
			scanf("%d", &x);
			hash[x+OFFSET] = 1;
		}
		for(i = 500000; i >= -500000; i--) {
			if(hash[i + OFFSET] == 1) {
				printf("%d", i);
				m--;
				if(m != 0) {
					printf(" ");
				}
				else {
					printf("\n");
					break;
				}
			}
		}
	}
	return 0;
}