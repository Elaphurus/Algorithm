/*
brackets matching
1s 32M
input:
)(rttyy())sss)(
output:
)(rttyy())sss)(
?            ?$
*/
#include <stdio.h>
#include <stack>
using namespace std;

stack<int> s;
char str[110];
char ans[110];

int main()
{
	while (scanf("%s", str) != EOF) {
		int i;
		for (i = 0; str[i] != 0; i++) {
			if (str[i] == '(') {
				s.push(i);
				ans[i] = ' ';
			} else if (str[i] == ')') {
				if (!s.empty()) {
					s.pop();
					ans[i] = ' ';
				} else {
					ans[i] = '?';
				}
			} else {
				ans[i] = ' ';
			}
		}

		while (!s.empty()) {
			ans[s.top()] = '$';
			s.pop();
		}

		ans[i] = 0;
		puts(str);
		puts(ans);
	}

	return 0;
}