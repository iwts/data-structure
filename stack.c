#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define STACK_INIT_SIZE 100  //栈初始空间
#define STACK_ADD_SIZE 10    //栈空间增量

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


// 获取栈顶元素
ElemType GetTop(Stack stack) {
	if (stack.top == stack.base) {
		exit(0);
	}
	return *stack.top;
}

// 压栈
ElemType Push(Stack *stack, ElemType e) {
	if (!stack->base) {
		exit(0);
	}
	if (stack->length+1 >= stack->stack_size) {  // 这里length+1，因为栈底永远是空的，用于判断base是否等于top
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

// 销毁栈
void DestoryStack(Stack *stack) {
	free(stack->base);
	stack->top = NULL;
	stack->base = NULL;
	stack->stack_size = 0;
	stack->length = 0;
}

// 清空栈
void ClearStack(Stack *stack) {
	stack->top = stack->base;
	stack->length = 0;
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

// 获取栈当前长度
int GetLength(Stack stack) {
	return stack.length;
}

int main() {
	Stack stack;
	CreatStack(&stack);
	Push(&stack, 10);
	Push(&stack, 9);
	printf("%d\n", Pop(&stack));
	printf("%d\n", GetTop(stack));
	isEmpty(stack);
	ClearStack(&stack);
	isEmpty(stack);
	DestoryStack(&stack);
	system("pause");
}
