#include<stdio.h>

int main()
{
	void hanoi(int n, char one, char two, char three);
	int m;
	
	printf("input the number of diskes:");
	scanf("%d", &m);
	printf("THe step of moving %d diskes:\n", m);
	hanoi(m, 'A', 'B', 'C');
}

//将n个盘子从one座移动到three座，借助two座
void hanoi(int n, char one, char two, char three)
{
	void move(char x, char y);
	if(n==1)
	{
		move(one, three);
	}
	else
	{
		hanoi(n-1, one, three, two);
		move(one,three);
		hanoi(n-1, two, one, three);
	}
}

void move(char x, char y)
{
	printf("%c -> %c\n", x, y);
}