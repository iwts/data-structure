/*
关于二叉树的3种遍历，主要算法写在最前，剩下的只写了构造二叉搜索树的
标准函数，不是重点。也去除了相关注释，如果不理解二叉搜索树请看之前的
二叉搜索树代码。
遍历全部使用了递归，可以画图来理解这种算法。
*/

#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

typedef int ElemType;
typedef struct SearchTree {
	ElemType data;
	int times;
	struct TreeNode *Left;
	struct TreeNode *Right;
}TreeNode, *Root;

void printElemtype(Root root) {
	printf("%d ", root->data);
}

// 先序遍历
void Preorder_traversal(Root root) {
	if (root) {
		Preorder_traversal(root->Left);
		printElemtype(root);
		Preorder_traversal(root->Right);
	}
}

// 中序遍历
void Order_traversal(Root root) {
	if (root) {
		printElemtype(root);
		Order_traversal(root->Left);
		Order_traversal(root->Right);
	}
}

// 后序遍历
void Posterior_traversal(Root root) {
	if (root) {
		Posterior_traversal(root->Left);
		Posterior_traversal(root->Right);
		printElemtype(root);
	}
}

void InitSearchTree(Root *root) {
	*root = (Root)malloc(sizeof(TreeNode));
	if (!(*root)) {
		exit(0);
	}
	(*root)->times = 0;
	(*root)->data = NULL;
	(*root)->Left = NULL;
	(*root)->Right = NULL;
}

int isEmpty(Root root) {
	if (root->data) {
		return 0;
	}
	else {
		return 1;
	}
}

void InsertSearchTree(Root root, ElemType data) {
	if (isEmpty(root)) {
		root->data = data;
	}
	if (data - root->data == 0) {
		root->times++;
	}
	else {
		if (data - root->data > 0) {
			if (root->Right == NULL) {
				Root newNode = (Root)malloc(sizeof(Root));
				newNode->data = data;
				newNode->times = 1;
				newNode->Left = NULL;
				newNode->Right = NULL;
				root->Right = newNode;
			}
			else {
				InsertSearchTree(root->Right, data);
			}
		}
		else {
			if (root->Left == NULL) {
				Root newNode = (Root)malloc(sizeof(Root));
				newNode->data = data;
				newNode->times = 1;
				newNode->Left = NULL;
				newNode->Right = NULL;
				root->Left = newNode;
			}
			else {
				InsertSearchTree(root->Left, data);
			}
		}
	}
}

int main() {
	Root search_tree;
	InitSearchTree(&search_tree);
	InsertSearchTree(search_tree, 6);
	InsertSearchTree(search_tree, 2);
	InsertSearchTree(search_tree, 8);
	InsertSearchTree(search_tree, 1);
	InsertSearchTree(search_tree, 5);
	InsertSearchTree(search_tree, 3);
	InsertSearchTree(search_tree, 4);
	Preorder_traversal(search_tree);
	printf("\n");
	Order_traversal(search_tree);
	printf("\n");
	Posterior_traversal(search_tree);

	system("pause");
	return 0;
}
