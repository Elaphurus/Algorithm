/*
 * the same bst?
 * 1s 32M
 * input:
 * 2(1 <= n <= 20)
 * 567432(len < 10)
 * 543267
 * 576342
 * 0
 * output:
 * YES
 * NO
 */
#include <stdio.h>
#include <string.h>

struct node {
	struct node *lchild;
	struct node *rchild;
	int c;
}tree[12];

int loc;

struct node *create()
{
	tree[loc].lchild = tree[loc].rchild = NULL;
	return &tree[loc++];
}

char str1[25], str2[25];
int size1, size2;
char *str;
int *size;

void postOrder(struct node *t)
{
	if (t->lchild != NULL)
		postOrder(t->lchild);
	if (t->rchild != NULL)
		postOrder(t->rchild);
	str[(*size)++] = t->c + '0';
}

void inOrder(struct node *t)
{
	if (t->lchild != NULL)
		postOrder(t->lchild);
	str[(*size)++] = t->c + '0';
	if (t->rchild != NULL)
		postOrder(t->rchild);
}

struct node *insert(struct node *t, int x)
{
	if (t == NULL) {
		t = create();
		t->c = x;
		return t;
	} else if (x < t->c)
		t->lchild = insert(t->lchild, x);
	else if (x > t->c)
		t->rchild = insert(t->rchild, x);

	return t;
}

int main()
{
	int n;
	struct node *t;
	char tmp[12];
	struct node *t2;
	int i;
	while (scanf("%d", &n) != EOF && n != 0) {
		loc = 0;
		t = NULL;
		scanf("%s", tmp);
		for (i = 0; tmp[i] != 0; i++)
			t = insert(t, tmp[i] - '0');

		size1 = 0;
		str = str1;
		size = &size1;
		postOrder(t);
		inOrder(t);
		str[size1] = 0;

		while (n-- != 0) {
			scanf("%s", tmp);
			t2 = NULL;
			for (i = 0; tmp[i] != 0; i++)
				t2 = insert(t2, tmp[i] - '0');

			size2 = 0;
			str = str2;
			size = &size2;
			postOrder(t2);
			inOrder(t2);
			str[size2] = 0;

			puts(strcmp(str1, str2) == 0 ? "YES" : "NO");
		}
	}

	return 0;
}