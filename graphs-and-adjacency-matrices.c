/*
图的邻接矩阵，假设图有N的顶点，那么就用N*N的二维数组来存放图的弧。假设有M[i,j]
那么我们根据有向图、无向图、是否有权值，可以这样区分：
无向无权图：M[i][j]的值表示顶点i与顶点j存在弧
无向有权图：M[i][j]的值表示顶点i与顶点j存在弧，值为权值
有向无权图：M[i][j]的值表示存在路径i->j
有向有权图：M[i][j]的值表示存在路径i->j，值为权值
所以我们用2个结构体，ArcCell表示一个边的数据，同时声明N*N的二维数组作为邻接矩阵
ij值表示顶点，内值表示权值或者是否存在边。
MGroup表示一个图，其中包含了所有顶点的位置集合和一个邻接矩阵。
*/

#include<stdio.h>  
#define MAX_VERTEX_NUM 10

typedef int VRType; // 顶点关系，无权图0、1表示是否相邻，有权图表示权值
typedef int InfoType;// 弧信息类型
typedef int VertexType; // 顶点类型
						// 一个顶点的信息
typedef struct ArcCell {
	VRType adj;
	InfoType info;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
// 一个图的信息
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM]; // 图的顶点集合
	AdjMatrix arcs; // 图的邻接矩阵
	int vexnum, arcnum; // 图的顶点数与弧数
}MGroup;

// 初始化一个图，这里使用了有向有权图
void creatMGroup(MGroup *G) {
	G->vexnum = 0;
	int arcs, begin, end;
	// 输入弧数量
	scanf("%d", &arcs);
	G->arcnum = arcs;
	while (arcs--) {
		// 输入起始点、终止点
		scanf("%d%d", &begin, &end);
		G->vexs[begin] = 1;
		G->vexs[end] = 1;
		G->arcs[begin][end].adj = 1;
	}
	int i = 0;
	for (; i < MAX_VERTEX_NUM; i++) {
		if (G->vexs[i] == 1) {
			G->vexnum++;
		}
	}
}

// 利用邻接矩阵遍历（利用遍历二维数组，不是深搜或者广搜）
void printMGroup(MGroup G) {
	int i = 0;
	for (; i < MAX_VERTEX_NUM; i++) {
		int j = 0;
		for (; j < MAX_VERTEX_NUM; j++) {
			if (G.arcs[i][j].adj == 1) {
				printf("%d->%d\n", i, j);
			}
		}
	}
	printf("the vexnum is %d\n", G.vexnum);
	printf("the arcnum is %d\n", G.arcnum);
}

int main() {
	MGroup G;
	creatMGroup(&G);
	printMGroup(G);

	system("pause");
	return 0;
}
