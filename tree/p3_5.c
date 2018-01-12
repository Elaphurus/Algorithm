/*
 * binary sort tree
 * 1s 32M
 * input:(1 <= n <= 100)
 * 5
 * 1 6 5 9 8
 * output:(remove repeated numbers)
 * 1 6 5 9 8 
 * 1 5 6 8 9 
 * 5 8 9 6 1 
 */
#include <stdio.h>
#include <string.h>

struct node {
	struct node *lchild;
	struct node *rchild;
	int c;
}tree[110];

int loc;

struct node *create()
{
	tree[loc].lchild = tree[loc].rchild = NULL;
	return &tree[loc++];
}

void postOrder(struct node *t)
{
	if (t->lchild != NULL)
		postOrder(t->lchild);
	if (t->rchild != NULL)
		postOrder(t->rchild);
	printf("%d ", t->c);
}

void inOrder(struct node *t)
{
	if (t->lchild != NULL)
		inOrder(t->lchild);
	printf("%d ", t->c);
	if (t->rchild != NULL)
		inOrder(t->rchild);
}

void preOrder(struct node *t)
{
	printf("%d ", t->c);
	if (t->lchild != NULL)
		preOrder(t->lchild);
	if (t->rchild != NULL)
		preOrder(t->rchild);
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
	int i;
	int x;
	struct node *t;
	while (scanf("%d", &n) != EOF) {
		loc = 0;
		t = NULL;
		for (i = 0; i < n; i++) {
			scanf("%d", &x);
			t = insert(t, x);
		}

		preOrder(t);
		printf("\n");
		inOrder(t);
		printf("\n");
		postOrder(t);
		printf("\n");
	}

	return 0;
}