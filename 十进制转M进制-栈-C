/*
修改M的替换值，可以实现十进制转换为各种进制
*/

/*
N进制转M进制算法：
N = (N div M)*M + N mod M
即，1348转8进制2504为例：
N 		除数	余数
1348	168		4
168		21		0
21		2		5
2		0		2
从下到上获得2504
这个也是基础的数制转换方法

下面就以上面这个例子，使用栈来解决
*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define STACK_INIT_SIZE 100  //栈初始空间
#define STACK_ADD_SIZE 10    //栈空间增量
#define M 8

typedef int ElemType;
typedef struct Stack {
	ElemType *base;  //栈空间
	ElemType *top;  //指针指向栈顶
	int stack_size;  //栈的总大小
	int length;  //栈当前长度
}Stack;

// 创建一个空栈
void CreatStack(Stack *stack) {
	stack->base = (Stack *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!stack->base) {
		exit(0);
	}
	stack->top = stack->base;
	stack->stack_size = STACK_INIT_SIZE;
	stack->length = 0;
}

// 压栈
ElemType Push(Stack *stack, ElemType e) {
	if (!stack->base) {
		exit(0);
	}
	if (stack->length + 1 >= stack->stack_size) {  // 这里length+1，因为栈底永远是空的，用于判断base是否等于top
		stack->base = (Stack *)realloc(stack->base, (stack->stack_size + STACK_ADD_SIZE) * sizeof(ElemType));
		stack->stack_size += STACK_ADD_SIZE;
	}
	if (!stack->base) {
		exit(0);
	}
	stack->top++;
	*stack->top = e;
	stack->length++;
}

// 出栈
ElemType Pop(Stack *stack) {
	if (!stack->base || stack->top == stack->base) {
		return 0;
	}
	return *stack->top--;
}

// 是否是空栈，是返回1，否则返回0
int isEmpty(Stack stack) {
	if (stack.top == stack.base) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int n;
	Stack stack;
	CreatStack(&stack);
	printf("please input your number: ");
	scanf("%d", &n);
	while (n) {
		Push(&stack, n%M);
		n = n / M;
	}
	while (!isEmpty(stack)) {
		printf("%d", Pop(&stack));
	}
	system("pause");
}
