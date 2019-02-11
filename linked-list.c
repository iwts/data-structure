#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int Elemtype;

typedef struct Node{
    Elemtype data;
    struct Node *next;
    int linkedList_size;
}Node,*List;

void creatList(List *head){
	*head = (List)malloc(sizeof(Node));
	if(!head){
		return exit(0);
	}
	(*head)->linkedList_size = 0;
	(*head)->next = NULL;
}

void insertList_head(List head,Elemtype data){
    List newList = (List)malloc(sizeof(Node));
    if(!newList){
    	return exit(0);
    }
    newList->data = data;
    newList->next = head->next;
    head->next = newList;
    if(head->next != newList){
        return exit(0);
    }
    head->linkedList_size++;
}

void insertList_foot(List head,Elemtype data){
	List newList = (List)malloc(sizeof(Node));
	if(!newList){
		return exit(0);
	}
	List key = head;
	while(key->next){
		key = key->next;
	}
	newList->data = data;
	newList->next = NULL;
	key->next = newList;
	head->linkedList_size++;
}

void deleteList(List head,int index){
	List delete_list = head;
	if(delete_list == NULL){
		return exit(0);
	}
	if(index < 0 || index >= head->linkedList_size){
		return exit(0);
	}
	int i = 1;
	for(;i < index;i++){
		delete_list = delete_list->next;
	}
	List freeList = delete_list->next;
	delete_list->next = freeList->next;
	free(freeList);
	if(freeList != NULL){
		//return exit(0);
	}
	head->linkedList_size--;
}

int main(){
    List head;
    creatList(&head);
    int i = 1;
    for(;i < 11;i++){
    	insertList_foot(head,i);
    }
    List p = head->next;
    List q = head->next;
    while(p){
    	printf("%d\n",p->data);
    	p = p->next;
    }
    printf("\n\n\n");
    deleteList(head,5);
    while(q){
    	printf("%d\n",q->data);
    	q = q->next;
    }
}
