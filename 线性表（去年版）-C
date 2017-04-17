#include <stdio.h>

// 控制顺序表的date数组的最大长度
#define MAXSIZE 20 

typedef struct{
	int date[MAXSIZE];
	int length;
}SqList;

// 创建空的顺序表
void creatList(SqList &L){
	L.length = 0;
}

// 返回顺序表当前的长度
int getLength(SqList &L){
	return L.length;
}

// 返回 index 下标的数据
int getIndex(SqList &L,int index){
	if((index >= 0)&&(index <= L.length-1)){
		return L.date[index];
	}else{
		return -1;
	}
}

// 查找 value 值的数据，并返回该值对应的下标
int find(SqList &L,int value){
	int i;
	for(i = 0;i < L.length;i++){
		if(value == L.date[i]){
			return i;
		}
	}
	return -1;
}

// 在 index 下标处插入 value 值。成功插入返回 1，否则返回0
int insert(SqList &L,int value,int index){
	int i;
	if((index < 0)&&(index > L.length)){
		return 0;
	}else{
		for(i = L.length;i > index;i--){
			L.date[L.length] = L.date[L.length-1];
		}
		L.date[index] = value;
		L.length++;
		return 1;
	}
}

// 删除 index 下标的数据，成功返回1，否则返回0
int deleteList(SqList &L,int index){
	int i;
	if((index >= 0)&&(index < L.length)){
		for(i = index;i < L.length-1;i++){
			L.date[i] = L.date[i+1];
		}
		L.length--;
		return 1;
	}else{
		return 0;
	}
}

// 每行5个数据，输出顺序表
void printList(SqList &L){
	int i;
	for(i = 0;i < L.length;i++){
		printf("%4d",L.date[i]);
		if((i+1)%5 == 0){
			printf("\n");
		}
	}
}

// 直接调用代码测试，没有写控制台。
int main(){
	SqList L;
	creatList(L);

	insert(L,1,0);
	insert(L,2,1);
	insert(L,3,2);
	
	printf("%d\n%d\n%d\n",L.date[0],L.date[1],L.date[2]);
	
	printf("%d\n",find(L,3));

	deleteList(L,2);

	printList(L);
}
