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
#include<algorithm>
using namespace std;
//define the rule for sort
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	int n;
	int buf[100];
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &buf[i]);
		}
		sort(buf, buf + n, cmp); //overload c++ sort function(quicksort)
		for(i = 0; i < n; i++) {
			printf("%d ", buf[i]);
		}
		printf("\n");
	}
	return 0;
}