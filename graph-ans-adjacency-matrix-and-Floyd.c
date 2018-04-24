/*
    属于图的综合运用？每个顶点与边都有自己的属性，使用邻接矩阵表示。
同时是一个无向有权图。有一些基本的图操作，最后是一个Floyd算法求最短
路径。利用Floyd算法与字符串的操作完成路径查询的操作。
    关于路经查询，我觉得使用深度优先搜索，并且进行优化，实际效果是
比Floyd的效果好的。Floyd一次实现了多源最短路，但是实际上可能很多都
没有用，使用优化的深搜可以保证效率。
*/

/*
1   A   家属楼
2   B   理工一
3   C   理工二
4   D   理工三
5   E   梦溪湖
6   F   二食堂
7   G   体育馆
8   H   崇师楼
9   I   一食堂
10  J   大广场
11  K   图书馆
邻接矩阵
0  4  M  M  M  M  M  2  M  M  M
4  0  1  M  1  M  M  M  M  M  M
M  1  0  1  M  2  M  M  M  M  M
M  M  1  0  M  M  1  M  M  M  3
M  1  M  M  0  2  M  4  M  M  M
M  M  2  M  2  0  M  M  M  M  2
M  M  M  1  M  M  0  M  11 10 5
2  M  M  M  4  M  M  0  9  M  M
M  M  M  M  M  M  11 9  0  2  3
M  M  M  M  M  M  10 M  2  0  M
M  M  M  3  M  2  5  M  3  M  0
输入数据测试-34行
1 2 4
1 8 2
2 1 4
2 5 1
2 3 1
3 2 1
3 6 2
3 4 1
4 3 1
4 11 3
4 7 1
5 8 4
5 2 1
5 6 2
6 5 2
6 3 2
6 11 2
7 4 1
7 11 5
7 9 11
7 10 10
8 1 2
8 5 4
8 9 9
9 8 9
9 11 3
9 7 11
9 10 2
10 7 10
10 9 2
11 6 2
11 4 3
11 7 5
11 9 3
家属楼666info
理工一666info
理工二666info
理工三666info
梦溪湖666info
二食堂666info
体育馆666info
崇师楼666info
一食堂666info
大广场666info
图书馆666info
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_VERTEX_NUM 12
#define M 101

typedef int VRType; // 权值类型
typedef char InfoType;// 弧信息类型
// 一个顶点的信息
typedef struct {
    InfoType info[99];
}VertexType[MAX_VERTEX_NUM];
// 一个弧的信息
typedef struct ArcCell {
    VRType adj;
    char moveInfo[999]; //从A点到B点的路径信息
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
// 一个图的信息
typedef struct {
    VertexType vexs; // 图的顶点集合
    AdjMatrix arcs; // 图的邻接矩阵
    int vexnum, arcnum; // 图的顶点数与弧数
}MGroup;

// 初始化一个图
void creatMGroup(MGroup *G) {
    int i = 0;
    int j = 0;
    for (; i < MAX_VERTEX_NUM; i++) {
        for (j = 1; j < MAX_VERTEX_NUM; j++) {
            G->arcs[i][j].adj = 0;
        }
    }
    G->vexnum = 11;
    G->arcnum = 34;
    int arcs = G->arcnum;
    int vexs = G->vexnum;
    int begin, end, adj;
    while (arcs--) {
        // 输入起始点、终止点、权值，构造邻接矩阵
        scanf("%d%d%d", &begin, &end, &adj);
        G->arcs[begin][end].adj = adj;
        char b[3], e[3], a[3];
        sprintf(b, "%d", begin);
        sprintf(e, "%d", end);
        sprintf(a, "%d", adj);
        strcpy(G->arcs[begin][end].moveInfo, b);
        strcat(G->arcs[begin][end].moveInfo, "->");
        strcat(G->arcs[begin][end].moveInfo, e);
    }
    // 完善邻接矩阵
    i = 1;
    j = 1;
    for (; i < MAX_VERTEX_NUM; i++) {
        for (j = 1; j < MAX_VERTEX_NUM; j++) {
            if (i == j) {
                G->arcs[i][j].adj = 0;
                strcpy(G->arcs[i][j].moveInfo, "站在此地不要走动");
            }else {
                if (G->arcs[i][j].adj == 0) {
                    G->arcs[i][j].adj = M;
                }
            }
        }
    }
    InfoType info[99];
    // 按照顺序输入景点信息
    i = 1;
    for (; i < MAX_VERTEX_NUM; i++) {
        scanf("%s", info);
        strcpy(G->vexs[i].info, info);
    }
}

// 输出邻接矩阵
void printAdjMatrix(MGroup G) {
    int i = 1;
    int j = 1;
    for (; i < MAX_VERTEX_NUM; i++) {
        for (j = 1; j < MAX_VERTEX_NUM; j++) {
            if (G.arcs[i][j].adj == M) {
                printf("M  ");
            }else {
                printf("%d  ", G.arcs[i][j]);
            }
        }
        printf("\n");
    }
}

// 遍历输出景点以及景点信息
void printVertexInfo(MGroup G) {
    int i = 1;
    for (; i < MAX_VERTEX_NUM; i++) {
        printf("%d. %s\n", i,G.vexs[i].info);
    }
}

// 输出X景点的信息
void printAVertexInfo(MGroup G, int i) {
    printf("%s\n", G.vexs[i].info);
}

void floyd(MGroup *G) {
    int i, j, k;
    for (i = 1; i < MAX_VERTEX_NUM; i++) {
        for (j = 1; j < MAX_VERTEX_NUM; j++) {
            for (k = 1; k < MAX_VERTEX_NUM; k++) {
                if (G->arcs[j][k].adj > G->arcs[j][i].adj + G->arcs[i][k].adj) {
                    G->arcs[j][k].adj = G->arcs[j][i].adj + G->arcs[i][k].adj;
                    strcpy(G->arcs[j][k].moveInfo, G->arcs[j][i].moveInfo);
                    if (G->arcs[i][j].moveInfo[1] == '-') {
                        strcat(G->arcs[j][k].moveInfo, &G->arcs[i][k].moveInfo[1]);
                    }else {
                        strcat(G->arcs[j][k].moveInfo, &G->arcs[i][k].moveInfo[2]);
                    }
                }
            }
        }
    }
}

void printFloyd(MGroup G, int begin, int end) {
    printf("%s    最短路径距离为：%d\n", G.arcs[begin][end].moveInfo, G.arcs[begin][end].adj);
}

int main() {
    // 准备
    MGroup G;
    creatMGroup(&G);
    floyd(&G);
    system("cls");
    printf("---------哈师大校内地图导航------------\n");
    printf("---------------------------------------\n");
    printf("学校景点编号如下：\n");
    printf("1   A   家属楼\n");
    printf("2   B   理工一\n");
    printf("3   C   理工二\n");
    printf("4   D   理工三\n");
    printf("5   E   梦溪湖\n");
    printf("6   F   二食堂\n");
    printf("7   G   体育馆\n");
    printf("8   H   崇师楼\n");
    printf("9   I   一食堂\n");
    printf("10  J   大广场\n");
    printf("11  K   图书馆\n");
    while (1) {
        printf("---------------------------------------\n");
        printf("请输入需要的要求编号:\n");
        printf("0.查询景点信息\n");
        printf("1.路径查询\n");
        printf("2.退出\n");
        int input;
        scanf("%d", &input);
        switch (input) {
            case 0: {
                int i;
                printf("请输入景点编号\n");
                scanf("%d", &i);
                printAVertexInfo(G, i);
            }break;
            case 1: {
                int i,j;
                printf("请输入当前景点编号与终点景点编号\n");
                scanf("%d%d", &i, &j);
                printFloyd(G, i, j);
            }break;
            case 2: exit(0);break;
        }
    }

    system("pause");
    return 0;
}
