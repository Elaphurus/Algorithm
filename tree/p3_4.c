/*
 * binary tree
 * input:
 * ABC
 * BAC
 * FDXEAG
 * XDEFAG
 * output:
 * BAC
 * XEDGAF
 */
#include <stdio.h>
#include <string.h>

struct node{
	struct node *lchild;
	struct node *rchild;
	char c;
}tree[50];

int loc;

struct node *create()
{
	tree[loc].lchild = tree[loc].rchild = NULL;
	return &tree[loc++];
}

char str1[30], str2[30];

void postOrder(struct node *t)
{
	if (t->lchild != NULL)
		postOrder(t->lchild);
	if (t->rchild != NULL)
		postOrder(t->rchild);
	printf("%c", t->c);
}

struct node *build(int s1, int e1, int s2, int e2)
{
	int rootIdx;
	int i;

	struct node *ret = create();
	ret->c = str1[s1];
	for (i = s2; i <= e2; i++) {
		if (str2[i] == str1[s1]) {
			rootIdx = i;
			break;
		}
	}
	if (rootIdx != s2)
		ret->lchild = build(s1 + 1, s1 + (rootIdx - s2), s2, rootIdx - 1);
	if (rootIdx != e2)
		ret->rchild = build(s1 + (rootIdx - s2) + 1, e1, rootIdx + 1, e2);
	return ret;
}

int main()
{
	int len1, len2;
	struct node *t;
	while (scanf("%s", str1) != EOF) {
		scanf("%s", str2);
		loc = 0;
		len1 = strlen(str1);
		len2 = strlen(str2);
		t = build(0, len1 - 1, 0, len2 - 1);
		postOrder(t);
		printf("\n");
	}

	return 0;
}
