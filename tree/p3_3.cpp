/*
 * huffman tree
 * input:
 * 5
 * 1 2 2 5 9
 * output:
 * 37
 */
#include <stdio.h>
#include <queue>
using namespace std;

/* 
 * min heap
 * need a space between greater<int> and >
 */
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		while (!q.empty())
			q.pop();
		
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			q.push(x);
		}

		int ans = 0;
		while (q.size() > 1) {
			int a = q.top();
			q.pop();
			int b = q.top();
			q.pop();
			ans += a + b;
			q.push(a + b);
		}
		printf("%d\n", ans);
	}

	return 0;
}
