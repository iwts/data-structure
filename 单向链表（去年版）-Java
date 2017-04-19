// 链表的数据域，可以扩增数据
class Node{
	int date;
	Node(){
		this(0);
	}
	Node(int date){
		this.date = date;
	}
}

// 链表类，使用 creatNewLink 方法创建头结点对象，其他操作全部使用该对象
public class Link{
	Node node;
	Link next;

	Link(){
		node = null;
		next = null;
	}
	Link(int date){
		node = new Node(date);
		next = null;
	}

	// 创建头结点，静态方法，直接赋给对象
	public static Link creatNewLink(int date){
		Link headLink = new Link(date);
		return headLink;
	}
	// 正插法，在 headLink 后插入链表
	public void addLink(int date){
		Link newLink = new Link(date);
		newLink.next = this.next;
		this.next = newLink;
	}
	// 查找，Node 里有大量数据时才有意义，利用 key 来获取其他信息
	public Link find(int date){
		Link findNode = this;
		Link errorNode = null;
		while(findNode.next != null){
			if(findNode.node.date == date){
				return findNode;
			}else{
				findNode = findNode.next;
			}
		}
		return errorNode;
	}
	// 删除
	public int remove(int date){
		Link removeNode = this;
		Link topNode = this;
		while(removeNode.next != null){			if(removeNode.node.date == date){
				topNode.next = removeNode.next;
				removeNode.next = null;
				return 1;
			}else{
				topNode = removeNode;
				removeNode = removeNode.next;
			}
		}
		if(removeNode.node.date == date){
			topNode.next = removeNode.next;
			removeNode.next = null;
			return 1;
		}
		return 0;
	}
	// 修改
	public int alter(int date,int newDate){
		Link alterNode = find(date);
		if(alterNode != null){
			alterNode.node.date = newDate;
			return 1;
		}else{
			return 0;
		}
	}
	// 遍历链表并输出，默认10个数据为1行。
	public void print(){
		Link nextNode = this;
		int i = 0;
		while(nextNode != null){
			System.out.printf("%5d",nextNode.node.date);
			nextNode = nextNode.next;
			i++;
			if(i%10 == 0){
				System.out.println();
			}
		}
	}
}


// 上面的插入实际上是后来的插到head后，有尾插法：
public void insert(){
	Link newLink = new Link(data);
	newLink.top.next = newLink;
	newLink.top = newLink;
}

// top 指向最末位
top = this;
