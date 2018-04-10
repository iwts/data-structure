/*
AVL树，建立在二叉查找树的基础上。区别在于利用旋转获得了自平衡性。从而
避免了二叉查找树的退化，将搜索算法时间复杂度稳定在O(logn)。但是也是由
于旋转，在增、删过程中非常复杂，由于递归，可能存在多重旋转。所以在实
际应用上要少于红黑树。但是逻辑比红黑树简单的多。
*/

#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

typedef int ElemType;
typedef struct AVLTree {
	ElemType data;
	int times;  // 使用懒惰增删，即使用times储存该数据的出现次数
	int height;
	struct TreeNode *Left;
	struct TreeNode *Right;
}TreeNode, *Root;

int Max(int a, int b) {
	return a > b ? a : b;
}

// 初始化一个空的AVL树
void InitAVLTree(Root *root) {
	*root = (Root)malloc(sizeof(TreeNode));
	if (!(*root)) {
		exit(0);
	}
	(*root)->times = 0;
	(*root)->height = 0;
	(*root)->data = NULL;
	(*root)->Left = NULL;
	(*root)->Right = NULL;
}

void DestroyTree(Root root) {
	root->Left = NULL;
	root->Right = NULL;
	free(root);
}

void MakeEmpty(Root root) {
	InitAVLTree(&root);
}

// 判断AVL树是否为空，空则返回1，否则返回0
int isEmpty(Root root) {
	if (root->data) {
		return 0;
	}else {
		return 1;
	}
}

// 返回数的高，这里定义根的高为1（有的文献定义根为0）
int getHeight(Root root) {
	if (root) {
		return root->height;
	}else {
		return 0;
	}
}

// 查找数据
void FindAVLTree(Root root,ElemType data) {
	if (isEmpty(root)) {
		printf("the search tree is empty\n");
		exit(0);
	}
	if (data - root->data == 0) {
		if (root->times == 0) {
			printf("sorry,no find it!\n");
		}else {
			printf("find it!\n");
		}
	}else {
		if (data - root->data > 0) {
			if (root->Right == NULL) {
				printf("sorry,no find it!\n");
			}else {
				FindAVLTree(root->Right, data);
			}
		}else {
			if (root->Left == NULL) {
				printf("sorry,no find it!\n");
			}else {
				FindAVLTree(root->Left, data);
			}
		}
	}
}

// 查找整个查找树的最大数据，并返回
ElemType FindAVLTreeMax(Root root) {
	if (root->Right == NULL) {
		return root->data;
	}else {
		FindAVLTreeMax(root->Right);
	}
}

// 查找整个查找树的最小数据，并返回
ElemType FindAVLTreeMin(Root root) {
	if (root->Left == NULL) {
		return root->data;
	}else {
		FindAVLTreeMin(root->Left);
	}
}

//AVL树的旋转分为4种，详情自搜，不再赘述
Root left_left_rotation(Root root) {
	Root temp = root->Left;
	root->Left = temp->Right;
	temp->Right = root;
	root->height = Max(getHeight(root->Left), getHeight(root->Right))+1;
	temp->height = Max(getHeight(temp->Left), root->height) + 1;
	return temp;
}

Root right_right_rotation(Root root) {
	Root temp = root->Right;
	root->Right = temp->Left;
	temp->Left = root;
	root->height = Max(getHeight(root->Left), getHeight(root->Right)) + 1;
	temp->height = Max(getHeight(temp->Left), getHeight(temp->Right)) + 1;
	return temp;
}

Root left_right_rotation(Root root) {
	root->Left = right_right_rotation(root->Left);
	return left_left_rotation(root);
}

Root right_left_rotation(Root root) {
	root->Right = left_left_rotation(root->Right);
	return right_right_rotation(root);
}

// 插入,必须保证自平衡，具体算法参考书《数据结构与算法分析（C语言）》
Root InsertAVLTree(Root root, ElemType data) {
	// 由于是递归判断节点，那么节点不存在就说明该插入了
	if (root == NULL) {
		root = (Root *)malloc(sizeof(Root));
		root->data = data;
		root->Left = NULL;
		root->Right = NULL;
		root->times = 1;
		root->height = 1;
	}else {
		if (root->data) {
			// 懒惰插入，times++
			if (data - root->data == 0) {
				root->times++;
			}
			if (data - root->data > 0) {
				// 递归过程，可以构建一棵树自己演算来理解
				root->Right = InsertAVLTree(root->Right, data);
				if (getHeight(root->Right) - getHeight(root->Left) == 2) {
					// 具体旋转方式的判断算法，自己手写演示即可理解
					Root temp = root->Right;
					if (data > temp->data) {
						root = right_right_rotation(root);
					}else {
						root = right_left_rotation(root);
					}
				}
			}else {
				root->Left = InsertAVLTree(root->Left, data);
				if (getHeight(root->Left) - getHeight(root->Right) == 2) {
					Root temp = root->Left;
					if (data < temp->data) {
						root = left_left_rotation(root);
					}else {
						root = left_right_rotation(root);
					}
				}
			}
		}else {
			root->data = data;
			root->times = 1;
			root->height = 1;
		}
	}
	// 每次递归的最后都更新节点的高
	root->height = Max(getHeight(root->Left), getHeight(root->Right))+1;
	return root;
}

// 由于AVL树的删除不是很重要，并且非常繁琐，推荐使用懒惰删除
void DeleteAVLTree(Root root,ElemType data) {
	if (isEmpty(root)) {
		printf("the search tree is empty\n");
		exit(0);
	}
	if (data - root->data == 0) {
		if (root->times == 0) {
			printf("sorry,no find it!\n");
		}else {
			root->times--;
		}
	}else {
		if (data - root->data > 0) {
			if (root->Right == NULL) {
				printf("sorry,no find it!\n");
			}else {
				DeleteAVLTree(root->Right, data);
			}
		}else {
			if (root->Left == NULL) {
				printf("sorry,no find it!\n");
			}else {
				DeleteAVLTree(root->Left, data);
			}
		}
	}
}

/*
给出4种旋转的测试数据，修改insert函数的data参数
LL:8 4 12 2 6 1
LR:8 4 12 2 6 5
RL:8 4 12 10 14 9
RR:8 4 12 10 14 13
*/
int main() {
	Root avl_tree;
	InitAVLTree(&avl_tree);
	if (isEmpty(avl_tree)) {
		printf("is a empty!\n");
	}else {
		printf("is not empty!\n");
	}
	avl_tree = InsertAVLTree(avl_tree, 8);
	avl_tree = InsertAVLTree(avl_tree, 12);
	avl_tree = InsertAVLTree(avl_tree, 4);
	avl_tree = InsertAVLTree(avl_tree, 10);
	avl_tree = InsertAVLTree(avl_tree, 14);
	avl_tree = InsertAVLTree(avl_tree, 13);
	printf("%d\n", FindAVLTreeMax(avl_tree));
	printf("%d\n", FindAVLTreeMin(avl_tree));
	FindAVLTree(avl_tree, 13);
	DeleteAVLTree(avl_tree, 2);
	FindAVLTree(avl_tree, 2);

	system("pause");
	return 0;
}
