/*
基于有环链表的一些问题，整体还是比较简单的。为了描述方便，其实重复了很多代码。
只要我们添加两个指针：入环结点、相遇点。那么代码就能化简很多，这里就不再写了。
配合个人博客食用更佳：
https://blog.csdn.net/iwts_24/article/details/83421853
*/



#include<iostream>

using namespace std;

struct Node {
    int val;
    struct Node *next;
}head,a,b,c,d,e,f;

// 比较简单明了地创建链表
void create_list() {
    a.val = 1;
    b.val = 2;
    c.val = 3;
    d.val = 4;
    e.val = 5;
    f.val = 6;
    head.next = &a;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &c;
}

// 测试链表是否正确
void test_link_list() {
    Node *temp = head.next;
    for (int i = 0; i < 10; i++) {
        cout << temp->val << endl;
        temp = temp->next;
    }
}

// 是否有环，1为存在，0为不存在
int have_ring() {
    Node *slow = &head;
    Node *fast = &head;
    if (fast->next != NULL) fast = fast->next->next;
    slow = slow->next;
    while (slow != NULL && fast != NULL) {
        if (slow == fast) return 1;
        slow = slow->next;
        if (fast->next == NULL) return 0;
        fast = fast->next->next;
    }
    return 0;
}

// 获得入环结点
Node * get_ring_node() {
    Node *p_head = &head;
    Node *p_meet;
    Node *slow = &head;
    Node *fast = &head;
    if (fast->next != NULL) fast = fast->next->next;
    slow = slow->next;
    while (slow != NULL && fast != NULL) {
        if (slow == fast){
            p_meet = slow;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    while (p_head != p_meet) {
        p_head = p_head->next;
        p_meet = p_meet->next;
    }
    return p_head;
}

// 获得链表结点总数
int get_length() {
    Node *p_head = &head;
    Node *p_meet;
    Node *slow = &head;
    Node *fast = &head;
    if (fast->next != NULL) fast = fast->next->next;
    slow = slow->next;
    while (slow != NULL && fast != NULL) {
        if (slow == fast) {
            p_meet = slow;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    int a = 0;
    while (p_head != p_meet) {
        p_head = p_head->next;
        p_meet = p_meet->next;
        a++;
    }
    int x = 0;
    // 此时slow指针是指向相遇点没有变的
    while (p_head != slow) {
        p_head = p_head->next;
        x++;
    }
    return 2*a + x - 1;
}

// 获得链表环上结点总数
int get_ring_length() {
    Node *p_head = &head;
    Node *p_meet;
    Node *slow = &head;
    Node *fast = &head;
    if (fast->next != NULL) fast = fast->next->next;
    slow = slow->next;
    while (slow != NULL && fast != NULL) {
        if (slow == fast) {
            p_meet = slow;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    int a = 0;
    while (p_head != p_meet) {
        p_head = p_head->next;
        p_meet = p_meet->next;
        a++;
    }
    int x = 0;
    // 此时slow指针是指向相遇点没有变的
    while (p_head != slow) {
        p_head = p_head->next;
        x++;
    }
    return a + x;
}

int main() {
    create_list();
    // test_link_list();

    system("pause");
    return 0;
}
