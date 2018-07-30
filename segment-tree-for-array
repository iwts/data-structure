/*
有2种query与update，正常的是单点更新，最基础的线段树。
后面加range的，是区间懒惰更新的线段树。build与init函数
是共用的

这里使用数组来模拟了线段树的所有节点，有时候感觉不是很好用
其实可以用结构体来模拟
*/

#include<iostream>
#include<string>
#define LL long long
#define MAX 1001

using namespace std;

int tree[MAX]; // 线段树
int lz[MAX]; // 延迟标记

void init(){
	memset(tree,0,sizeof(tree));
	memset(lz,0,sizeof(lz));
}

// 创建线段树
void build(int node,int l,int r){
	if(l == r){
		cin >> tree[node];
		return;
	}
	int mid = (l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node] = tree[node*2] + tree[node*2 + 1];
}

void pushup(int rt){
    if(tree[rt<<1]<tree[rt<<1|1]){
        tree[rt]=tree[rt<<1];
        pos[rt]=pos[rt<<1];
    }else{
        tree[rt]=tree[rt<<1|1];
        pos[rt]=pos[rt<<1|1];
    }
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

// 单点更新下的区间查找，LR为线段树范围，lr为查找区间范围
int query(int L,int R,int l,int r,int node){
	if(l <= L && r >= R) return tree[node];
	int mid = (L+R) / 2;
	int sum = 0;
	if(mid >= l) sum += query(L,mid,l,r,node*2);
	if(mid < r) sum += query(mid+1,R,l,r,node*2+1);
	return sum;
}

// 单点更新，n为更新值，index为更新点，lr为更新范围
void update(int n,int index,int l,int r,int node){
	if(l == r) {
		tree[node] = n; // 更新方式，可以自由改动
		return;
	}
	int mid = (l+r) / 2;
	// push_down(node,mid-l+1,r-mid); 若既有点更新又有区间更新，需要这句话
	if(index <= mid){
		update(n,index,l,mid,node*2);
	}else{
		update(n,index,mid+1,r,node*2+1);
	}
	tree[node] = tree[node*2] + tree[node*2 + 1];
}

void push_down(int node,int l,int r){
	if(lz[node]){
		int mid = (l+r) / 2;
		lz[node*2] += lz[node];
		lz[node*2 + 1] += lz[node];
		tree[node*2] += 1LL*(mid - l + 1)*lz[node];
		tree[node*2 + 1] += 1LL*(r - mid)*lz[node];
		lz[node] = 0;
	}
}

// 区间更新，lr为更新范围，LR为线段树范围，add为更新值
void update_range(int node,int l,int r,int L,int R,int add){
	if(l <= L && r >= R){
		lz[node] += 1LL*add;
		tree[node] += 1LL*(R - L + 1)*add; // 更新方式
		return;
	}
	push_down(node,L,R);
	int mid = (L+R) / 2;
	if(mid >= l) update_range(node*2,l,r,L,mid,add);
	if(mid < r) update_range(node*2 + 1,l,r,mid+1,R,add);
	tree[node] = tree[node*2] + tree[node*2 + 1];
}

// 区间查找
LL query_range(int node,int L,int R,int l,int r){
	if(l <= L && r >= R) return tree[node];
	push_down(node,L,R);
	int mid = (L+R) / 2;
	LL sum = 0;
	if(mid >= l) sum += query_range(node*2,L,mid,l,r);
	if(mid < r) sum += query_range(node*2 + 1,mid+1,R,l,r);
	return sum;
}

int main() {
	init();
	build(1,1,8);
	cout << query(1,8,3,7,1);

	system("pause");
	return 0;
}
