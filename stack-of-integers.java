public class StackOfIntegers(){
	private int[] elements;
	private int top = -1;

	StackOfIntegers(){
		this(16);
	}
	StackOfIntegers(int capacity){
		elements = new int[capacity];
	}

	public boolean isEmpty(){
		if(top == -1){
			return true;
		}else{
			return false;
		}
	}
	public void peek(){
		if(isEmpty()){
			System.out.println("the stack is empty!");
		}else{
			System.out.println(elements[top]);
		}
	}
	public void push(int value){
		if(top == this.length-1){
			System.out.println("the index is over!");
		}else{
			elements[top++] = value;
		}
	}
	public void pop(){
		if(isEmpty()){
			System.out.println("the stack is empty!")
		}else{
			System.out.println(elements[--top]);
		}
	}
	public int getSize(){
		return elements.length;
	}
}
