/*
设A和B是两个按元素值递增有序的单链表，写
一算法将A和B归并为按元素值递减有序的单链
表C试分析算法的时间复杂度
*/

/*
懒得写函数。。所以代码没有复用，重复的部分很多。。

插入部分所有的插入都是头插，这样保证插入的时候可以是递增，而
链表顺序遍历并且归并到新链表的时候正好变成递减。

void creat_A_and_B()函数，创建2个链表用于测试。使用while循环、
利用基数i获取递增的数据。

void sum_A_and_B_for_C()函数，创建第三个链表并且将2个链表进行
计算后归并到第三个链表上。
这里直接提取A、B的value创建了新的Node连接到链表c上。
使用了双指针遍历a、b链表，最后如果有1个链表遍历结束则跳出while
再次进入while将没有结束的链表的数据直接加到链表c上。
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct Node{
    Elemtype value;
    struct Node *next;
}Node,*List;

void creat_A_and_B(List *head_A,List *head_B){
    int i = 2;
    *head_A = (List)malloc(sizeof(Node));
    if(!head_A){
        return exit(0);
    }
    (*head_A)->next = NULL;
    while(i--){
        List newList = (List)malloc(sizeof(Node));
        newList->value = i*3+1;
        newList->next = (*head_A)->next;
        (*head_A)->next = newList;
    }

    i = 3;
    *head_B = (List)malloc(sizeof(Node));
    if(!head_B){
        return exit(0);
    }
    (*head_B)->next = NULL;
    while(i--){
        List newList = (List)malloc(sizeof(Node));
        newList->value = i*3+1;
        newList->next = (*head_B)->next;
        (*head_B)->next = newList;
    }
}

void sum_A_and_B_for_C(List head_A,List head_B,List *head_C){
    List key_a = head_A->next;
    List key_b = head_B->next;
    *head_C = (List)malloc(sizeof(Node));
    if(!head_C){
        return exit(0);
    }
    (*head_C)->next = NULL;
    while(key_a != NULL && key_b != NULL){
        if(key_a->value <= key_b->value){
            List newList = (List)malloc(sizeof(Node));
            if(!newList){
                return exit(0);
            }
            newList->value = key_a->value;
            newList->next = (*head_C)->next;
            (*head_C)->next = newList;
            key_a = key_a->next;
        }else{
            List newList = (List)malloc(sizeof(Node));
            if(!newList){
                return exit(0);
            }
            newList->value = key_b->value;
            newList->next = (*head_C)->next;
            (*head_C)->next = newList;
            key_b = key_b->next;
        }
    }
    if(key_a == NULL){
        while(key_b != NULL){
            List newList = (List)malloc(sizeof(Node));
            if(!newList){
                return exit(0);
            }
            newList->value = key_b->value;
            newList->next = (*head_C)->next;
            (*head_C)->next = newList;
            key_b = key_b->next;
        }
    }else{
        while(key_a != NULL){
            List newList = (List)malloc(sizeof(Node));
            if(!newList){
                return exit(0);
            }
            newList->value = key_a->value;
            newList->next = (*head_C)->next;
            (*head_C)->next = newList;
            key_a = key_a->next;
        }
    }
}

int main(){
    List head_A;
    List head_B;
    List head_C;
    creat_A_and_B(&head_A,&head_B);
    sum_A_and_B_for_C(head_A,head_B,&head_C);

    int i = 2;

    List pr_a = head_A->next;
    printf("the List A is: "); 
    while(i--){
        printf("%d ",pr_a->value);
        pr_a = pr_a->next;
    }

    i = 3;
    List pr_b = head_B->next;
    printf("\nthe List B is: ");
    while(i--){
        printf("%d ",pr_b->value);
        pr_b = pr_b->next;
    }

    List pr_c = head_C->next;
    printf("\nthe List C is: ");
    while(pr_c != NULL){
    	printf("%d ",pr_c->value);
        pr_c = pr_c->next;
    }
}
