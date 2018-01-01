/*
score sort
time: 1s memory: 32M special: none
description: N students, sorted by score, if score equals, then by name, if name also equals, then by age. output N sorted students' info
input: several groups of test data, first line an integer N(N<=1000), following N lines include data of N student, each includes name(string, no more than 100), age and score(integer, no more than 100)
output: N lines, each in: name age score
example input:
3
abc 20 99
bcd 19 97
bed 20 97
example output:
bcd 19 97
bed 20 97
abd 20 99
hint: name A is before a(by ASCII)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct E {
	char name[101];
	int age;
	int score;
}buf[100];
int cmp(const void* x, const void* y) {
	struct E* a = (struct E*)x;
	struct E* b = (struct E*)y;
	if(a->score != b->score) {
		return a->score - b->score;
	} else if(strcmp(a->name, b->name) != 0) {
		return strcmp(a->name, b->name);
	} else {
		return a->age - b->age;
	}
}
int main() {
	int n, i;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%s%d%d", buf[i].name, &buf[i].age, &buf[i].score);
		}
		qsort(buf, n, sizeof(struct E), cmp);
		for(i = 0; i < n; i++) {
			printf("%s %d %d\n", buf[i].name, buf[i].age, buf[i].score);
		}
	}
	return 0;
}