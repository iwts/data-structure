/*二叉查找树*/

/*
关于二叉查找树：
	二叉查找树是二叉树的一个应用，使二叉树成为二叉查找树的规则为：对于
树中每个节点，左子树中所有关键字的值都是小于节点，而右子树则是大于节点，
要求是绝对大的情况，例如下例：
			5
		2		8
	  1	  X
X的位置是必须是 >2 <5 只有这样是二叉查找树，即对根而言，左边的所有元素
都比根小，右边的全部大于根。
	可以说，如果自己创建二叉查找树的话，不可能出现上面那种情况。

关于重复：
	二叉查找树允许重复这种情况的存在，解决方法就是使用一个变量进行记录，
下面的代码使用了 times 作为记录，初始值都是 1 ，在插入之类的操作在进行
的时候更新 times 的值即可。

insert：
	可以看成一次更新，每次插入操作，要么是插入一个新叶，要么更新一个节
点的 times。可以看成一个查找，直到到达树叶，进行更新，或者更新 times。

Deate：
	有两种删除方法，懒惰删除和一般删除。
懒惰删除：
	最简单的删除方法，由于使用了数据域 times ，所以每个节点默认是 1。
那么在删除的时候可以直接更改 times 的值。那么如果使用懒惰删除，需要对应
地更改 find 等方法，添加判断 times 是否为 0。判断的位置要确定，只有对比
是否相等的时候才判断 times。
	使用懒惰删除，内存的占用不会随着删除操作而减少，变化的只是 times 而
已。所以进行大量删除操作后，进行其他操作的时间不会减少。
*/

public class SearchTree{
	public int data;
	public int times = 1;
	public SearchTree parent = null;
	public SearchTree left = null;
	public SearchTree right = null;

	SearchTree(int data){
		this.data = data;
	}

	public void makeEmpty(){
		this.left = null;
		this.right = null;
	}
	public boolean isEmpty(){
		if((left == null)&&(right == null)){
			return true;
		}else{
			return false;
		}
	}
	public SearchTree find(int data){
		if(this.data == data){
			return this;
		}
		if((data > this.data)&&(right != null)){
			return right.find(data);
		}
		if((data < this.data)&&(left != null)){
			return left.find(data);
		}
		return null;
	}
	public SearchTree findMax(){
		if(right != null){
			return right.findMax();
		}else{
			return this;
		}
	}
	public SearchTree findMin(){
		if(left != null){
			return left.findMax();
		}else{
			return this;
		}
	}
	public void insert(int data){
		if(this.data == data){
			times++;
			return;
		}
		if((data > this.data)&&(right != null)){
			return right.insert(data);
		}
		if((data < this.data)&&(left != null)){
			return left.insert(data);
		}
		if((data > this.data)&&(right == null)){
			right = new SearchTree(data);
			right.parent = this;
			return;
		}
		if((data < this.data)&&(left == null)){
			left = new SearchTree(data);
			left.parent = this;
			return;
		}
	}
	public void lazyDelete(int data){
		this.find(data).times--;
	}
	public void delete(int data,SearchTree last){
		if(data == this.data){
			if(left == null && right == null){
				last = null;
			}
			if(left != null && right == null){
				last = left;
			}
			if(left == null && right != null){
				last = right;
			}
			if(left != null && right != null){
				if(right.left == null){
					right.left = left;
					last = right;
				}else{
					last = right.left;
					right.left.left = left;
					right.left = right.left.right;
					right.left.right = right;
				}
			}
		}
		if((data > this.data)&&(right != null)){
			last = this.right;
			right.delete(data,last);
		}
		if((data < this.data)&&(left != null)){
			last = this.left;
			left.delete(data,last);
		}
	}
}
