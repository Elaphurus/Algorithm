/**
 * input4.txt中存放一无向连通图G，顶点数不超过20。
 * 判断是否存在一个顶点，当其被删除时G不再连通。若存在找出一个即可。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vnum;
int g[20][20] = {0};
int visited[20] = {0};
int count;

void DFS(int rm, int v)
{
	int i;

	visited[v] = 1;
	for (i = 1; i <= vnum; i++) {
		if (i == rm || i == v || visited[i] == 1)
			continue;
		else if(g[v][i] == 1) {
			count++;
			DFS(rm, i);
		}
	}	
}

int main()
{
	FILE *fp;
	char line[10];
	int len;
	int v1, v2;
	int rm;
	int i, j;

	if ((fp = fopen("./input4.txt", "r")) == NULL) {
		printf("Can't open file!\n");
		exit(0);
	}
	
	fgets(line, 10, fp);
	len = strlen(line);
	line[--len] = '\0';
	if (len == 1) {
		vnum = line[0] - 48;
	} else if (len == 2) {
		vnum = line[1] - 48 + 10 * (line[0] - 48);
	} else {
		printf("顶点数不超过20!\n");
	}

	for (i = 1; i <= vnum; i++) {
		g[i][i] = 1;
	}

	while (fgets(line, 10, fp) != NULL) {
		len = strlen(line);
		line[--len] = '\0';
		v1 = line[0] - 48;
		if (line[1] != ' ') {
			v1 = 10 * v1 + line[1] - 48;
			v2 = line[3] - 48;
			if (len == 5)
				v2 = 10 * v2 + line[4] - 48;
		} else {
			v2 = line[2] - 48;
			if (len == 4)
				v2 = 10 * v2 + line[3] - 48;
		}
		g[v1][v2] = 1;
		g[v2][v1] = 1;
	}

	/*for (i = 1; i <= vnum; i++) {
		for (j = 1; j <= vnum; j++) {
			printf("%2d", g[i][j]);
		}
		printf("\n");
	}*/

	for (rm = 1; rm <= vnum; rm++) {
		for (i = 1; i <= vnum; i++) {
			visited[i] = 0;
		}

		count = 1;
		i = 1;
		for (; i <= vnum; i++) {
			if (i != rm)
				break;
		}
		DFS(rm, i);
		if (count < vnum - 1) {
			printf("%d\n", rm);
			break;
		}
		if (rm == vnum) {
			printf("不存在满足要求的顶点！\n");
		}
	}

	return 0;
}
