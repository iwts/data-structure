#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

#define STACK_INIT_SIZE 100
#define STACK_ADD_SIZE 10

typedef char ElemType;
typedef struct Stack {
	ElemType *base;
	ElemType *top;
	int stack_size;
	int length;
}Stack;

void CreatStack(Stack *stack) {
	stack->base = (Stack *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!stack->base) {
		exit(0);
	}
	stack->top = stack->base;
	stack->stack_size = STACK_INIT_SIZE;
	stack->length = 0;
}

ElemType GetTop(Stack stack) {
	if (stack.top == stack.base) {
		exit(0);
	}
	return *stack.top;
}

ElemType Push(Stack *stack, ElemType e) {
	if (!stack->base) {
		exit(0);
	}
	if (stack->length + 1 >= stack->stack_size) {
		stack->base = (Stack *)realloc(stack->base, (stack->stack_size + STACK_ADD_SIZE) * sizeof(ElemType));
		stack->stack_size += STACK_ADD_SIZE;
		if (!stack->base) {
			exit(0);
		}
	}
	stack->top++;
	*stack->top = e;
	stack->length++;
}

ElemType Pop(Stack *stack) {
	if (!stack->base || stack->top == stack->base) {
		exit(0);
	}
	return *stack->top--;
}

// 判断是否是运算符
int In(char c) {
	if (c == '+') return 1;
	if (c == '-') return 1;
	if (c == '*') return 1;
	if (c == '/') return 1;
	if (c == '(') return 1;
	if (c == ')') return 1;
	if (c == '#') return 1;
	return 0;
}

/* 
对比运算符优先级的，这里使用了算法，定义了每个运算符的值，
两者相减运算，得到的值来代替比大小。
*/
ElemType Precede(char stack_c, char c) {
	int int_stack_c;
	int int_c;
	switch (stack_c) {
	case '(': int_stack_c = 0; break;
	case '+': int_stack_c = 1; break;
	case '-': int_stack_c = 1; break;
	case '*': int_stack_c = 2; break;
	case '/': int_stack_c = 2; break;
	case ')': int_stack_c = 3; break;
	case '#': return '<'; break;
	}
	switch (c) {
	case '(': int_c = 0; break;
	case '+': int_c = 1; break;
	case '-': int_c = 1; break;
	case '*': int_c = 2; break;
	case '/': int_c = 2; break;
	case ')': int_c = 3; break;
	case '#': return '>'; break;
	}
	switch (int_stack_c - int_c) {
	case -3: return '='; break;
	case -2: return '<'; break;
	case -1: return '<'; break;
	case 0: return '<'; break;
	case 1: return '>'; break;
	case 2: return '>'; break;
	case 3: return '='; break;
	}
	exit(0);
}

ElemType Operate(char a, char theta, char b) {
	int int_a, int_b;
	int_a = a - 48;
	int_b = b - 48;
	switch (theta) {
	case '+': return (int_a + int_b) + 48; break;
	case '-': return (int_a - int_b) + 48; break;
	case '*': return (int_a * int_b) + 48; break;
	case '/': return (int_a / int_b) + 48; break;
	}
	exit(0);
}

ElemType EvaluateExpression() {
	Stack OPTR;
	Stack OPND;
	CreatStack(&OPTR);
	CreatStack(&OPND);

	Push(&OPTR, '#');
	char c;
	c = getchar();
	while (c != '#' || GetTop(OPTR) != '#') {
		if (!In(c)) {
			Push(&OPND, c);
			c = getchar();
		}
		else {
			switch (Precede(GetTop(OPTR), c)) {
			case '<': {
				Push(&OPTR, c);
				c = getchar();
			}break;
			case '=': {
				char temp;
				temp = Pop(&OPTR);
				c = getchar();
			}break;
			case '>': {
				char theta, a, b;
				theta = Pop(&OPTR);
				b = Pop(&OPND);
				a = Pop(&OPND);
				Push(&OPND, Operate(a, theta, b));
			}break;
			}
		}
	}
	return GetTop(OPND);
}

int main() {
	printf("%c\n", EvaluateExpression());

	system("pause");
	return 0;
}
