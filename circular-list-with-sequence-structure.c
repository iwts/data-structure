/*
循环队列可以使用顺序储存结构，注意临界值问题。当rear或者front的下标
已经到MAX_SIZE-1的情况下，需要重置为0。这个临界值判断要考虑到。当
rear与front相等的时候有2种情况，空队列或者队列满。所以要配合length的
值来判断队列为空还是满。
*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MAX_SIZE 100

typedef int Elemtype;
typedef struct Queue{
	Elemtype *base;
	int front;
	int rear;
	int length;
}Queue;

// 创建一个空队列
void CreatQueue(Queue *q){
	q->base = (Queue *)malloc(MAX_SIZE * sizeof(Elemtype));
	if (!q->base) {
		exit(0);
	}
	q->front = 0;
	q->rear = 0;
	q->length = 0;
}

// 销毁队列
void DestroyQueue(Queue *q) {
	free(q->base);
	q->base = NULL;
	q->front = 0;
	q->rear = 0;
	q->length = 0;
}

// 清空队列
void ClearQueue(Queue *q) {
	DestroyQueue(q);
	CreatQueue(q);
	q->length = 0;
}

// 是否为空队列，是则返回1，否则返回0
int isEmpty(Queue q) {
	if (q.front == q.rear) {
		return 1;
	}else {
		return 0;
	}
}

// 返回队列的长度
int Length(Queue q) {
	return q.length;
}

// 返回队列头的值
Elemtype GetHead(Queue q) {
	if (isEmpty(q)) {
		exit(0);
	}else {
		return q.base[q.front];
	}
}

// 从队列尾插入一个对象
void EnQueue(Queue *q,int data) {
	if (q->length == 100) {
		printf("\nwrong!the queue is empty!\n");
	}else {
		q->base[q->rear] = data;
		q->length++;
		if (q->rear == MAX_SIZE - 1) {
			q->rear = 0;
		}else {
			q->rear++;
		}
	}
}

// 从队列头将一个对象移除，并将这个对象赋值给e
void DeQueue(Queue *q,Elemtype *e) {
	if (q->length == 0) {
		exit(0);
	}
	*e = q->base[q->front];
	q->base[q->front] = 0;
	q->length--;
	if (q->front == MAX_SIZE - 1) {
		q->front = 0;
	}else {
		q->front++;
	}
}

int main() {
	Queue q;
	Elemtype e;
	CreatQueue(&q);
	if (isEmpty(q)) {
		printf("queue is empty\n");
	}else {
		printf("queue isn't empty\n");
	}
	EnQueue(&q, 1);
	EnQueue(&q, 2);
	EnQueue(&q, 3);
	printf("%d\n", GetHead(q));
	DeQueue(&q,&e);
	printf("%d\n", e);
	printf("%d\n", GetHead(q));

	system("pause");
	return 0;
}
