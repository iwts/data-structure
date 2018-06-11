/*
这里没有应用。。。可以去做hodj1232或者poj2524，这2题都是并查集基础运用
*/

/*
按秩合并的并查集，其实按什么合并不重要，秩只是用的更多（任何与权值相关都可以
考虑秩），所以要在不同的情况用不同的规则。所以数组上有2个数组，uset表示并查集
集合，rank表示秩集合。
并查集，简单地说类似一个数，每一个数作为元素在uset中存放的数据是这个数的上级。
所以并查集也跟LCA算法有关。当这个数没有上级的时候，就是本身。这样，如果很多个
数都属于一个集合，那么这些数一直往上找，根一定是一个数。而所有根是一个数的就
称为一个集合。
如果我们遍历整个查并集，并且将查并集的根存放在一个数组中，遍历数组中存放的数据
即可知道总共有几个集合（利用STL的vector，调用size函数更明显）。
下面的函数有单独的解释。推荐一个讲的很浅显易懂的博客：
	http://blog.csdn.net/u013546077/article/details/64509038
*/

#include<iostream>
#define MAX 233

using namespace std;

int uset[MAX];
int rank[MAX];

// 初始化，刚开始是假设单个的数都是单个的集合
void init(){
	for(int i = 0;i < MAX;i++){
		uset[i] = i;
	}
	memset(rank,0,sizeof(rank));
}

// 查找，非常简单，while循环一直向上遍历，直到根处即可。
int find(int x){
	int r = x;
	while(r != uset[r]){
		r = uset[r];
	}
	/*
	这里讨论一下路径压缩算法。如果我们每次合并就是直接并到后面，那么
	最坏的情况下查并集将退化成线性结构，查找的效率非常低，为了防止这
	样的情况，我们在查找的时候添加一个路径压缩算法。可以将x到根的这一
	路上所有的数据全部变成根的子树，那么就将(r-x)层缩减到了2层。之后
	查找的效率就会提高。算法十分简单，就是再遍历一次，并赋值到r即可。
	*/
	int path = x;
	while(r != uset[path]){
		int temp = uset[path];
		uset[path] = r;
		path = temp;
	}
	return r;
}

// 并集，如果在同一个集合就退出，如果不是，按秩合并
void unionset(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y) return ;
	if(rank[x] > rank[y]){
		uset[y] = x;
	}else{
		uset[x] = y;
		if(rank[x] == rank[y]){
			rank[y]++;
		}
	}
}

int main(){

	system("pause");
	return 0;
}
