/*
binary search
time: 1s
input:
4(N <= 1000)
01 李江 男 21
02 刘唐 男 23
03 张军 男 19
04 王娜 女 19
5(M <= 10000)
02
03
01
04
05
output:
02 刘唐 男 23
03 张军 男 19
01 李江 男 21
04 王娜 女 19
No Answer!
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu {
	char no[100];
	char name[100];
	char sex[5];
	int age;
}buf[1000];

int cmp(const void *a, const void *b) {
	return strcmp(((struct stu*)a)->no, ((struct stu*)b)->no);
}

int main() {
	int n, m, ans;
	int i;
	char x[30];
	int base, top, mid;
	int tmp;
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%s%s%s%d", buf[i].no, buf[i].name, buf[i].sex, &buf[i].age);
		}
		qsort(buf, n, sizeof(struct stu), cmp);
		scanf("%d", &m);
		while (m-- != 0) {
			ans = -1;
			scanf("%s", x);
			base = 0;
			top = n - 1;
			while (top >= base) {
				mid = (top + base) / 2;
				tmp = strcmp(buf[mid].no, x);
				if (tmp == 0) {
					ans = mid;
					break;
				} else if (tmp > 0) {
					top = mid - 1;
				} else {
					base = mid + 1;
				}
			}							
			if (ans == -1) {
				printf("No Answer!\n");
			} else {
				printf("%s %s %s %d\n", buf[ans].no, buf[ans].name, buf[ans].sex, buf[ans].age);
			}
		}
	}
	return 0;
}