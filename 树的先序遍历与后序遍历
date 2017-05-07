/*通过 UNIX 文件树的操作理解先/后序遍历《数据结构与算法分析》（第二版）*/

/*
一些问题：
	树的表示不是 firstChild 与 nextSibling 的表示方式，而是最直观的树，即通过
链表存放所有的 child 。下面给出 UNIX 类。
	线序后序的意思是，先递归后操作，或者是先操作后递归，对于树而言都是由浅向
深遍历。
	以下给出先序遍历与后序遍历的实现代码，分别完成了一个功能，并且利用此来理
解两种遍历方式。先序遍历是打印出文件结构（树形）。后序遍历是得到整个 UNIX 系
统中所有文件的总大小。
*/
class UNIX<E>{
	String name;
	int size;// 当前程序大小（如果是文件夹则为0）（后序遍历求总大小时用）
	LinkedList<UNIX> children = new LinkedList<UNIX>();// 通过链表存放所有儿子
	public static int getSize(){
		return size;
	}
}

/*
先序遍历：
	O(n)，利用 depth 来控制空格的数量，每次输出一行，利用空格层次化输出文件列表。
使用了递归，但是由于对儿子节点的访问的迭代的，所以算法复杂度是 O(n)。
	先序遍历的一个要求是必须从根节点开始，否则只能得到从当前路径的上一层（不包括
上一层）开始的路径。
*/
public static void listDir(UNIX dir,int depth){
	// 输出静态方法
	print(dir,depth);
	if(!dir.children.isEmpty()){
		// UNIX 类中储存 children 的集合是 LinkedList，那么使用 for 迭代是否影响速度？
		for(int i = 0;i < dir.children.size();i++){
			listDir(dir.children.get(i),depth+1);
		}
	}else{
		return;
	}
}
// 输出静态方法，根据 depth 进行空格缩进。
public static void print(UNIX dir,int depth){
	for(int i = 0;i < depth;i++){
		System.out.printf(" ");
	}
	System.out.printf("%s",dir.name);
	System.out.println();
}
/*
后序遍历：
	利用递归，在栈中是从叶文件开始向上返回数据，虽然使用递归，但是同样也是遍历了整
个树，所以时间复杂度也是 O(n)。
*/
public static int sizeDirectory(UNIX dir){
	int totalSize = 0;
	if(!dir.children.isEmpty()){
		for(int i = 0;i < dir.children.size();i++){
			totalSize += sizeDirectory(dir.children.get(i));
		}
	}else{
		totalSize = dir.getSize();
		return totalSize;
	}
	return totalSize;
}
