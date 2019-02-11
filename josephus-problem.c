/*
约瑟夫环问题，链表算法。

假设有N个人围成一个环，从第K个人开始从1开始数数
，当数到M的时候，这个人出列（和谐siwang）。然后
下一个人继续从1开始数，直到所有的人都出列。求这、
些人的出列顺序。

链表解决的时候注意构造循环链表，指针的移动，临界
条件的选择。
*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define N 6
#define K 3
#define M 4

typedef struct Person{
    int number;
    struct Person *next;
}Person,*List;

void creatList(List *head){
    *head = (List)malloc(sizeof(Person));
    if(!head){
        exit(0);
    }
    (*head)->number = 1;
    (*head)->next = *head;
    int i = N;
    for(;i > 1;i--){
        List newList = (List)malloc(sizeof(Person));
        if(!newList){
            exit(0);
        }
        newList->number = i;
        newList->next = (*head)->next;
        (*head)->next = newList;
    }
}

void deleteList(List head,int key){
    List index = head;
    while(1){
        if(index->next->number == key){
            List delete_list = index->next;
            index->next = delete_list->next;
            free(delete_list);
            break;
        }else{
            index = index->next;
        }
    }
}

void runList(List head,int leave_person[]){
    int k = K;
    int m = M;
    int i = 0;
    List key = head;
    int leave = 0;
    for(;i < k-1;i++){
        key = key->next;
    }
    while(leave != N){
        m = M-1;
        while(m--){
            key = key->next;
        }
        leave_person[leave] = key->number;
        /* 
        这句话第一次写的时候忘记了，如果删除
        当前节点，key却没有及时移动，那么除了
        第一次成功出列，其他情况直接由于链表
        被切断而指向内存其他空间造成错误。   
        */
        key = key->next;
        deleteList(head,leave_person[leave]);
        leave++;
    }
}

int main(){
    List head;
    int leave_person[N];
    creatList(&head);
    int i = 0;
    runList(head,leave_person);
    printf("the leave order is : ");
    for(;i < N;i++){
        printf("%d ",leave_person[i]);       
    }
}
