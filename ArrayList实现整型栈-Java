import java.util.ArrayList;

public class StackOfIntegers(){
	private ArrayList<Integer> elements;
	private int top = -1;

	Test(){
		elements = new ArrayList<>();
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
			System.out.println(elements.get(top));
		}
	}
	public void push(int value){
		elements.add(value);
		top++;
	}
	public void pop(){
		if(isEmpty()){
			System.out.println("the stack is empty!");
		}else{
			System.out.println(elements.get(--top));
		}
	}
	public int getSize(){
		return elements.size();
	}
}
