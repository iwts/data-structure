/*树*/

/*主要根据是，数据结构-邓俊辉 http://www.bilibili.com/video/av6838401/index_30.html?t=63*/

/*
	对于一棵一般的树而言，使用 child 与 sibling 来控制。参考《数据结构与算法》的解释：
将树横向来看，对每一个节点而言定义有3个数据域（除了 root）：
	parent			指向父亲节点
	firstChild		指向该节点的第一个儿子
	nextSibling		指向该节点的下一个兄弟
这样对于一棵树而言，就可以横向遍历到所有节点。
	数据结构-邓俊辉，对树的构造与上面的方法相类似，利用了“秩”的概念（Rank）。用下表来
表示树：		R
			A   B   C
		  D   E     F
		  		  G H K
parent	-1 0  0  0  1  1  3  6  6  6
data	R  A  B  C  D  E  F  G  H  K
rank 	0  1  2  3  4  5  6  7  8  9
Rank 就类似于地址的作用，标志了每一个节点，而每个节点只用记忆自己的 rank 与 parent 的
rank 即可。
那么这样的方法向下遍历的时候是失败的，因为算法是 O(n) ，需要像桶排序一样，将 child 的
rank 作为链表绑定在父亲的数据上。
*/

/*数据结构-邓俊辉 Java 实现*/
class Tree{
	private char data;
	private int rank;
	private int parent;
	private Child firstChild;
}

class Child{
	private int rank;
	private Child nextChild;
}

/*数据结构与算法 Java 实现*/
class Tree{
	private int data;
	private Tree firstChild;
	private Tree nextSibling;
}
