/*
关于队列，有顺序储存结构与链式储存结构。但是在使用顺序储存结构的时候
类似栈，但是由于2个指针front与rear的移动，可能（很大几率）会发生队列
头到达队列尾，但是由于一直是出队列，导致整个base的空间全部浪费。所以
队列最好还是使用链式储存结构。
队列的顺序储存结构实际上是用来写循环队列的。
*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/*
2个结构体，一个声明队列中的对象，并且以链表的形式连接。另一个声明指
针组合，声明队列头与队列尾。
*/
typedef int Elemtype;
typedef struct QNode{
	Elemtype data;
	struct QNode *next;
}QNode, *Queue;
typedef struct {
	Queue front;
	Queue rear;
	int length;
}QueueLink;

// 创建一个空队列
void CreatQueue(QueueLink *ql){
	ql->front = (Queue)malloc(sizeof(QNode));
	if (!ql->front) {
		exit(0);
	}
	ql->rear = ql->front;
	ql->front->next = NULL;
	ql->length = 0;
}

// 销毁队列
void DestroyQueue(QueueLink *ql) {
	while (ql->front) {
		ql->rear = ql->front->next;
		free(ql->front);
		ql->front = ql->rear;
	}
	ql->length = 0;
}

// 清空队列
void ClearQueue(QueueLink *ql) {
	DestroyQueue(ql);
	CreatQueue(ql);
	ql->length = 0;
}

// 是否为空队列，是则返回1，否则返回0
int isEmpty(QueueLink ql) {
	if (ql.front == ql.rear) {
		return 1;
	}else {
		return 0;
	}
}

// 返回队列的长度
int Length(QueueLink ql) {
	return ql.length;
}

// 返回队列头的值
Elemtype GetHead(QueueLink ql) {
	if (isEmpty(ql)) {
		exit(0);
	}else {
		return ql.front->next->data;
	}
}

// 从队列尾插入一个对象
void EnQueue(QueueLink *ql,int data) {
	Queue newNode = (Queue)malloc(sizeof(QNode));
	if (!newNode) {
		exit(0);
	}
	newNode->data = data;
	newNode->next = NULL;
	ql->rear->next = newNode;
	ql->rear = newNode;
	ql->length++;
}

// 从队列头将一个对象移除，并将这个对象赋值给e
void DeQueue(QueueLink *ql,Elemtype *e) {
	if (ql->front == ql->rear) {
		exit(0);
	}
	Queue deleteNode = ql->front->next;
	*e = deleteNode->data;
	ql->front->next = deleteNode->next;
	free(deleteNode);
	// 判断是否队列已经空了，这时要手动将rear与front相等
	if (ql->front->next == NULL) {
		ql->rear = ql->front;
	}
	ql->length--;
}

int main() {
	QueueLink ql;
	Elemtype e;
	CreatQueue(&ql);
	if (isEmpty(ql)) {
		printf("queue is empty\n");
	}else {
		printf("queue isn't empty\n");
	}
	EnQueue(&ql, 1);
	EnQueue(&ql, 2);
	EnQueue(&ql, 3);
	printf("%d\n", GetHead(ql));
	DeQueue(&ql,&e);
	printf("%d\n", e);
	printf("%d\n", GetHead(ql));

	system("pause");
	return 0;
}
