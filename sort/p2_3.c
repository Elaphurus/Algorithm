/*
sort
time: 1s memory: 32M special: none
description: sort n numbers input and output
input: first line an integer(1<=n<=100). next line includes n number integers
output: may have several groups of test data, for each group, output n sorted integers, every number followed by a space. the rusult of each group covers one line
example input: 
4
1 4 3 2
example output(desc):
4 3 2 1
*/

#include<stdio.h>
#include<stdlib.h>
//define the rule for sort
int cmp(const void* x, const void* y) {
	return *(int*)y - *(int*)x;
}
int main() {
	int n;
	int i;
	int buf[100];
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d", &buf[i]);
		}
		qsort(buf, n, sizeof(int), cmp); //c quicksort
		for(i = 0; i < n; i++) {
			printf("%d ", buf[i]);
		}
		printf("\n");
	}
	return 0;
}