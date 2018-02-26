/**
  * input1.txt中仅含一行字符串，长度<=1000，包含若干英文单词和空格，
  * 删除首尾和单词间多余的空格，将结果输出到屏幕。
  */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char input[1000], output[1000];
	int len;
	char ch;
	char lastCh = ' ';

	if((fp = fopen("/home/hmz/Code/C/Algorithm/ustc/2017A/input1.txt", "r")) == NULL) {
		printf("Can't open file!\n");
		exit(0);
	}
	len = 0;
	while (!feof(fp)) {
		ch = fgetc(fp);
		// 忽略字母和空格以外的字符
		if (ch >= 97 && ch <= 122 || ch >= 65 && ch <= 90 || ch == ' ') {
		} else {
			continue;
		}
		if (ch != ' ') {
			if (lastCh == ' ') {
				if (ch >= 97) {
					output[len++] = ch - 32;
				}
			} else {
				output[len++] = ch;
			}
		} else if (lastCh != ' ') {
			// 单词后跟一个空格
			output[len++] = ' ';
		}
		lastCh = ch;
	}
	// 删除最后一个单词后的空格
	if (output[len - 1] == ' ') {
		output[len - 1] = '\0';
		len--;
	}
	fclose(fp);
	/*if ((fp = fopen("/home/hmz/Code/C/Algorithm/ustc/2017A/input1.txt", "w")) == NULL) {
		printf("Can't open file!\n");
		exit(0);
	}
	fputs(output, fp);
	fclose(fp);*/
	printf("%s\n", output);
	return 0;
}
