/*
二叉查找树，每次插入与删除都要求符合某节点左侧的数小于节点，右侧则是
大于。这样二叉树具有顺序性，但是由于二叉查找树是不具备平衡性的，所以
在查找以及其他操作中时间复杂度为O（logn）到O（n），当O（n）时，二叉
查找树退化为线性表。因为没有平衡性，所以有退化的可能，AVL树则解决了这
个问题。
*/

#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

typedef int ElemType;
typedef struct SearchTree {
	ElemType data;
	int times;  // 使用懒惰添加，即使用times储存该数据的出现次数
	struct TreeNode *Left;
	struct TreeNode *Right;
}TreeNode, *Root;

// 初始化一个空的二叉平衡树
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

void DestroyTree(Root root) {
	root->Left = NULL;
	root->Right = NULL;
	free(root);
}

void MakeEmpty(Root root) {
	InitSearchTree(&root);
}

// 判断二叉查找树是否为空，空则返回1，否则返回0
int isEmpty(Root root) {
	if (root->data) {
		return 0;
	}else {
		return 1;
	}
}

// 查找数据
void FindSearchTree(Root root,ElemType data) {
	if (isEmpty(root)) {
		printf("the search tree is empty\n");
		exit(0);
	}
	if (data - root->data == 0) {
		printf("find it!\n");
	}else {
		if (data - root->data > 0) {
			if (root->Right == NULL) {
				printf("sorry,no find it!\n");
			}else {
				FindSearchTree(root->Right, data);
			}
		}else {
			if (root->Left == NULL) {
				printf("sorry,no find it!\n");
			}else {
				FindSearchTree(root->Left, data);
			}
		}
	}
}

// 查找整个查找树的最大数据，并返回
ElemType FindSearchTreeMax(Root root) {
	if (root->Right == NULL) {
		return root->data;
	}else {
		FindSearchTreeMax(root->Right);
	}
}

// 查找整个查找树的最小数据，并返回
ElemType FindSearchTreeMin(Root root) {
	if (root->Left == NULL) {
		return root->data;
	}else {
		FindSearchTreeMin(root->Left);
	}
}

// 插入
void InsertSearchTree(Root root, ElemType data) {
	// 由于初始化头结点就是数的根，所以第一个插入元素应修改根数据
	if (isEmpty(root)) {
		root->data = data;
	}
	// 懒惰插入，即有重复数据出现的时候用一个整型记录数量。可减小树的深度
	if (data - root->data == 0) {
		root->times++;
	}else {
		// 插入算法，比较大小向左、右移动。一直进行递归，直到到达树叶。每次插入一定是树叶
		if (data - root->data > 0) {
			if (root->Right == NULL) {
				Root newNode = (Root)malloc(sizeof(Root));
				newNode->data = data;
				newNode->times = 1;
				newNode->Left = NULL;
				newNode->Right = NULL;
				root->Right = newNode;
			}else {
				InsertSearchTree(root->Right, data);
			}
		}else {
			if (root->Left == NULL) {
				Root newNode = (Root)malloc(sizeof(Root));
				newNode->data = data;
				newNode->times = 1;
				newNode->Left = NULL;
				newNode->Right = NULL;
				root->Left = newNode;
			}else {
				InsertSearchTree(root->Left, data);
			}
		}
	}
}

/*
删除难度比较大，主要是由于数据必须符合规则，每次删除的时候要考虑如何控制数据插入位置。
语言描述比较困难，推荐百度查找树恢复示意图。
分为2种情况：
1.删除节点有2个孩子。这里的算法是：找到右孩子的最小子孙，即利用
  FindSearchTreeMin方法，然后将该节点的数据更新到需要删除的节点。这样
  原来的数据就消失了，但是节点的内存地址不变。此时，递归删除节点的右
  孩子，将代替的数据删除，同时重新完成查找树。
2.删除节点有1个孩子或者没有孩子。这里的算法是：直接让删除节点的父亲的
  左/右孩子更换为删除节点的左/右孩子，使用temp来将删除节点free掉。这里
  注意不需要单独要求传入一个父亲指针。root就是指针，是指向删除节点的指
  针。平常使用root->Left等来操作，会下意识以为root是删除节点，其实root
  是指向删除节点的指针。
*/
void DeleteSearchTree(Root root,ElemType data) {
	if (isEmpty(root)) {
		printf("the search tree is empty\n");
		exit(0);
	}
	if (data - root->data == 0) {
		if (root->times != 1) {
			root->times--;
		}else {
			if (root->Left && root->Right) {
				ElemType temp_data;
				temp_data = FindSearchTreeMin(root->Right);
				root->data = temp_data;
				DeleteSearchTree(root->Right, temp_data);
			}else {
				Root temp = (Root)malloc(sizeof(Root));
				temp = root;
				if (root->Left) {
					root = root->Left;
				}else {
					if (root->Right) {
						root = root->Right;
					}
				}
				free(temp);
			}
		}
	}else {
		if (data - root->data > 0) {
			if (root->Right == NULL) {
				printf("sorry,no find it!\n");
			}else {
				DeleteSearchTree(root->Right, data);
			}
		}else {
			if (root->Left == NULL) {
				printf("sorry,no find it!\n");
			}else {
				DeleteSearchTree(root->Left, data);
			}
		}
	}
}

// 生成的树自己根据插入顺序可以画出来。
int main() {
	Root search_tree;
	InitSearchTree(&search_tree);
	if (isEmpty(search_tree)) {
		printf("is a empty!\n");
	}else {
		printf("is not empty!\n");
	}
	InsertSearchTree(search_tree, 6);
	InsertSearchTree(search_tree, 2);
	InsertSearchTree(search_tree, 8);
	InsertSearchTree(search_tree, 1);
	InsertSearchTree(search_tree, 5);
	InsertSearchTree(search_tree, 3);
	InsertSearchTree(search_tree, 4);
	printf("%d\n", FindSearchTreeMax(search_tree));
	printf("%d\n", FindSearchTreeMin(search_tree));
	FindSearchTree(search_tree, 2);
	DeleteSearchTree(search_tree, 2);
	FindSearchTree(search_tree, 2);

	system("pause");
	return 0;
}
