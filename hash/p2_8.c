/*
hash
output how many times a designated score shows in an array
input:
3
80 60 90
60
2
85 66
0
5
60 75 90 55 75
75
output:
1
0
2
*/
#include <stdio.h>
int main() {
	int n;
	int x;
	int hash[101] = {0};
	int i;
	while(scanf("%d", &n) != EOF && n != 0) {
		for(i = 1; i <= n; i++) {
			scanf("%d", &x);
			hash[x]++;
		}
		scanf("%d", &x);
		printf("%d\n", hash[x]);
	}
	return 0;
}