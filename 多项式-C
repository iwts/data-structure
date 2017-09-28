#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node{
    int coef; // 系数
    int expn; // 指数
    struct Node *next;
}Node,* Polynomail;

// 判断2个数值那个大，下面的方法需要用
int cmp(int a_expn,int b_expn){
    if(a_expn == b_expn){
        return 0;
    }else{
        if(a_expn > b_expn){
            return 1;
        }else{
            return -1;
        }
    }
}

// 创建一个空的多项式
void creat_poly(Polynomail *poly){
    (*poly) = (Polynomail)malloc(sizeof(Node));
    if(!poly){
        exit(0);
    }
    (*poly)->next = NULL;
}

// 销毁一个多项式
void free_poly(Polynomail poly){
    Polynomail free_key = poly;
    Polynomail free_key_last;
    while(free_key){
        free_key_last = free_key;
        free_key = free_key_last->next;
        free(free_key_last);
    }
}

// 打印一个多项式
void print_poly(Polynomail poly){
    printf("f(x)=");
    Polynomail key = poly->next;
    if(key){
        printf("%dx^%d",key->coef,key->expn);
        key = key->next;
    }
    while(key){
        if(key->coef > 0){
            printf("+%dx^%d",key->coef,key->expn);
        }else{
            printf("%dx^%d",key->coef,key->expn);
        }
        key = key->next;
    }
    printf("\n");
}

// 返回多项式的项数
int length(Polynomail poly){
    Polynomail key = poly->next;
    int num = 0;
    while(key){
        num++;
        key = key->next;
    }
    return num;
}

// 给多项式添加一个项
void insert_poly(Polynomail poly,int coef,int expn){
    Polynomail key = poly;
    int br = 0;
    int ok = 0;
    while(key->next){
        switch(cmp(key->next->expn,expn)){
            case 1: {
                        Polynomail newPoly = (Polynomail)malloc(sizeof(Node));
                        if(!newPoly){
                            exit(0);
                        }
                        newPoly->coef = coef;
                        newPoly->expn = expn;
                        newPoly->next = key->next;
                        key->next = newPoly;
                        br = 1;
                        ok = 1;
                    }break;
            case 0: {
						key->next->coef += coef;
						ok = 1; 
					}break;
            case -1: break;
        }
        if(br == 1){
            break;
        }
        key = key->next;
    }
    if(ok == 0){
    	Polynomail newPoly = (Polynomail)malloc(sizeof(Node));
        if(!newPoly){
        	exit(0);
        }
        newPoly->coef = coef;
        newPoly->expn = expn;
        newPoly->next = key->next;
        key->next = newPoly;
    }
    if(poly->next == NULL){
        Polynomail newPoly = (Polynomail)malloc(sizeof(Node));
        if(!newPoly){
            exit(0);
        }
        newPoly->coef = coef;
        newPoly->expn = expn;
        newPoly->next = NULL;
        poly->next = newPoly;
    }
}

// 多项式相加
void add_polys(Polynomail a_poly,Polynomail b_poly){
    Polynomail a_key = a_poly;
    Polynomail b_key = b_poly;
    while(a_key->next && b_key->next){
		switch(cmp(a_key->next->expn,b_key->next->expn)){
            case 1: {
                        Polynomail newPoly = (Polynomail)malloc(sizeof(Node));
                        if(!newPoly){
                            exit(0);
                        }
                        newPoly->coef = b_key->coef;
                        newPoly->expn = b_key->expn;
                        newPoly->next = a_key->next;
                        a_key->next = newPoly;
                        a_key = a_key->next;
                        b_key = b_key->next;
                    }break;
            case 0: {
                        a_key->next->coef += b_key->next->coef;
                        if(a_key->next->coef == 0){
                            Polynomail free_key = a_key->next;
                            a_key->next = free_key->next;
                            free(free_key);
                        }
                        if(a_key->next && b_key->next){
                        	a_key = a_key->next;
                        	b_key = b_key->next;
                        }
                        if(a_key->next && b_key->next == NULL){
                        	a_key = a_key->next;
                        }
                        if(a_key->next == NULL && b_key->next){
                        	b_key = b_key->next;
                        }
                    }break;
            case -1: a_key = a_key->next;break;
        }
    }
    if(a_key->next == NULL && b_key->next != NULL){
        a_key->next = b_key->next;
    }
}

// 多项式相减
void sub_polys(Polynomail a_poly,Polynomail b_poly){
    Polynomail a_key = a_poly;
    Polynomail b_key = b_poly;
    while(a_key->next && b_key->next){
        switch(cmp(a_key->next->expn,b_key->next->expn)){
            case 1: {
                        Polynomail newPoly = (Polynomail)malloc(sizeof(Node));
                        if(!newPoly){
                            exit(0);
                        }
                        newPoly->coef = (-1)*b_key->coef;
                        newPoly->expn = b_key->expn;
                        newPoly->next = a_key->next;
                        a_key->next = newPoly;
                        a_key = a_key->next;
                        b_key = b_key->next;
                    }break;
            case 0: {
                        a_key->next->coef -= b_key->next->coef;
                        if(a_key->next->coef == 0){
                            Polynomail free_key = a_key->next;
                            a_key->next = free_key->next;
                            free(free_key);
                        }
                        if(a_key->next && b_key->next){
                            a_key = a_key->next;
                            b_key = b_key->next;
                        }
                        if(a_key->next && b_key->next == NULL){
                            a_key = a_key->next;
                        }
                        if(a_key->next == NULL && b_key->next){
                            b_key = b_key->next;
                        }
                    }break;
            case -1: a_key = a_key->next;break;
        }
    }
    if(a_key->next == NULL && b_key->next != NULL){
        a_key->next = b_key->next;
    }
}

int main(){
    Polynomail poly_head;
    Polynomail test_poly;
    Polynomail test_poly2;
    Polynomail test_poly3;
    creat_poly(&poly_head);
    // 创建f(x) = 3x^2+5x^3-1x^6
    insert_poly(poly_head,3,2);
    insert_poly(poly_head,-1,6);
    insert_poly(poly_head,5,3);
    print_poly(poly_head);
    // 查看此时有多少项
    printf("%d\n",length(poly_head));
    // 创建test,f(x) = 3x^2+5x^3-1x^6
    creat_poly(&test_poly);
    insert_poly(test_poly,3,2);
    insert_poly(test_poly,1,6);
    // 相加，结果理论上为：f(x)=6x^2+5x^3
    add_polys(poly_head,test_poly);
    print_poly(poly_head);
    // 创建test2,f(x) = 3x^2+1x^6
    creat_poly(&test_poly2);
    insert_poly(test_poly2,3,2);
    insert_poly(test_poly2,1,6);
    // 相加，结果理论上为：f(x)=9x^2+5x^3+1x^6
    add_polys(poly_head,test_poly2);
    print_poly(poly_head);
    // 创建test3,f(x) = 3x^2+1x^6
    creat_poly(&test_poly3);
    insert_poly(test_poly3,3,2);
    insert_poly(test_poly3,1,6);
    // 相加，结果理论上为：f(x)=6x^2+5x^3
    sub_polys(poly_head,test_poly3);
    print_poly(poly_head);
}
