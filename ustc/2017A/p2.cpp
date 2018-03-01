/**
 * 输出2～1000的所有“完数”和“盈数”
 * “完数”：6=3+2+1；“盈数”：4<2+2+1。
 */
#include <stdio.h>
#include <math.h>
#include <queue>

using namespace std;

int main()
{
	int n, sum;
	queue<int> wan;
	queue<int> ying;
	int i;

	for (n = 2; n <= 1000; n++) {
		sum = 1;
		for (i = 2; i <= (int)sqrt((float)n); i++) {
			if (n % i == 0) {
				sum += i + n / i;
			}
		}
		if (n == sum) {
			wan.push(n);
		} else if (n < sum) {
			ying.push(n);
		}
	}

	printf("完数：\n");
	while (!wan.empty()) {
		printf("%d ", wan.front());
		wan.pop();
	}
	printf("\n");
	printf("盈数：\n");
	while (!ying.empty()) {
		printf("%4d ", ying.front());
		ying.pop();
	}
	printf("\n");

	return 0;
}
