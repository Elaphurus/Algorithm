/*
 * prime ring problem
 * 2s 32M
 * input:
 * 6(1 < n < 17)
 * output:
 * Case 1:
 * 1 4 3 2 5 6
 * 1 6 5 2 3 4
 */
#include <stdio.h>

int ans[22];
bool hash[22];
int n;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

bool judge(int x)
{
	int i;

	for (i = 0; i < 13; i++) {
		if (prime[i] == x)
			return true;
	}
	return false;
}

void check()
{
	int i;

	if (!judge(ans[n] + ans[1]))
		return;
	for (i = 1; i <= n; i++) {
		if (i != 1)
			printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}

void DFS(int num)
{
	int i;
	if (num > 1)
		if (!judge(ans[num] + ans[num - 1]))
			return;
	if (num == n) {
		check();
		return;
	}
	for (i = 2; i <= n; i++) {
		if (!hash[i]) {
			hash[i] = true;
			ans[num + 1] = i;
			DFS(num + 1);
			hash[i] = false;
		}
	}
}

int main()
{
	int cas = 0;
	int i;

	while (scanf("%d", &n) != EOF) {
		cas++;
		for (i = 0; i < 22; i++) {
			hash[i] = false;
		}
		ans[1] = 1;
		printf("Case %d:\n", cas);
		hash[1] = true;
		DFS(1);
	}
	return 0;
}