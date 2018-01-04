/*
ladder diagram
input:
4
output:
      ****
    ******
  ********
**********
*/
#include <stdio.h>
int main() {
	int h;
	int maxLine, spaceNum;
	int i, j;
	while(scanf("%d", &h) != EOF) {
		maxLine = h+(h-1)*2;
		for(i = 1; i <= h; i++) {
			spaceNum = maxLine - h - (i - 1)*2;
			for(j = 1; j <= maxLine; j++) {
				if(j <= spaceNum) {
					printf(" ");
				}
				else {
					printf("*");
				}
			}
			printf("\n");
		}
	}
	return 0;
}