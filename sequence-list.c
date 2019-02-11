#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define LIST_SIZE 20
#define LIST_ADD_SIZE 10

typedef struct{
	int date;
}date;

typedef struct Date_List{
	date *elem;
	int length;
	int list_size;
}List;

void creatList(List *list){
	list->elem = (date *)malloc(LIST_SIZE*sizeof(date));
	if(!list->elem){
		return exit(0);
	}
	list->length = 0;
	list->list_size = LIST_SIZE;
}

void insertList(List *list,int key,date *newList){
	if(!(key >= 0 && key < list->length+1)){
		return exit(0);
	}
	if(list->length >= list->list_size){
		date *newBase = (date *)realloc(list->elem,(list->list_size+LIST_ADD_SIZE)*sizeof(date));
		if(!newBase){
			return exit(0);
		}
		list->elem = newBase;
		list->list_size += LIST_ADD_SIZE;
	}
	int i = list->length;
	for(;i > key;i--){
		*&list->elem[i] = *&list->elem[i-1];
	}
	*&list->elem[key] = *newList;
	list->length++;
}

void deleteList(List *list,int key){
	if(!(key >= 0 && key < list->length)){
		return exit(0);
	}
	for(;key < list->length-1;key++){
		*&list->elem[key] = *&list->elem[key+1];
	}
	list->length--;
}

int main(){
	List *list = (List *)malloc(sizeof(List));
	creatList(list);
	int i = 0;
	for(;i < 10;i++){
		date *newDate = (date *)malloc(sizeof(date));
		newDate->date = i;
		insertList(list,i,newDate);
	}
	for(i = 0;i < 10;i++){
		printf("%d\n",list->elem[i].date);
	}
	printf("\n\n\n");
	deleteList(list,5);
	for(i = 0;i < 9;i++){
		printf("%d\n",list->elem[i].date);
	}
}
