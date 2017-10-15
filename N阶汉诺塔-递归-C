/*
汉诺塔的思想主要是：
1.将1到n-1的盘子全部放在辅助位
2.将n放在目标位
3.将辅助位的盘子全部放在目标位
注意：
1.形参的xyz不代表实际xyz3个柱子，而是代表：初始为、辅助位、目标位
2.每次调用的时候，根据3个位置填不同的参数，因为是递归，所以只用考
  虑位置，不用考虑实际xyz所代表的意义。
3.汉诺塔的思想就是将复杂的问题分成最小化，即：我有一个盘子，我应该
  在下一步将其放在哪。
4.注意结束递归，即n==1的情况。
*/

#include<stdio.h>
#include<stdlib.h>

void move(int n, char begin, char end) {
	printf("move %d form %c to %c\n", n, begin, end);
}

void hanoi(int n, char x, char y, char z) {
	if (n == 1) {
		move(1, x, y);
	}else {
		hanoi(n - 1, x, z, y);
		move(n, x, z);
		hanoi(n - 1, y, x, z);
	}
}

int main() {
	int n;
	printf("please input hanoi's level: ");
	scanf("%d", &n);
	hanoi(n, 'x', 'y', 'z');

	system("pause");
	return 0;
}
