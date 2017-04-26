/*逆波兰算法与中缀式转后缀式*/

/*
关于：
	计算器在计算的时候利用逆波兰算法与后缀表达式来解决优先级的问题。
逆波兰算法是建立在后缀表达式的基础上的，使用栈的数据结构来解决优先级
问题。正常书写的表达式是中缀表达式，为了使用逆波兰算法就必须转化为后
缀表达式。
*/

/*
中缀表达式与后缀表达式：
中缀式：a+b*c+(d*e+f)*g
后缀式：abc*+de*f+g*+
中缀式转后缀式实际上可以从栈中理解：
	1.从左向右读取中缀表达式
	2.分为两个区域，栈区与输出区
	3.读取到数的时候，直接写在输出区
	4.遇到操作符（+ - * / 以及左右括号），先压入栈
	5.判断压入栈之前栈顶是否有操作符
	6.如果栈顶操作符的优先级比较低，那么就将现在的操作符压入栈
	7.如果栈顶操作符的优先级比较高，那么就弹出栈中的操作符，直到出现优先级更低的操作符（同级的也弹出），然后再压入（括号特殊）
	8.左右括号一定是匹配入栈的并且拥有最高优先级，左括号入栈，然后进行与之前一样的操作，直到出现右括号
	9.当出现右括号时，丢弃右括号，同时无限出栈直到遇到左括号，然后丢弃左括号
	10.最后没有操作符的时候清空栈，弹出所有操作符
此时：栈为空，输出区得到后缀表达式
*/

/*
逆波兰算法：
得到后缀表达式后，就可以通过逆波兰算法进行计算，同样需要中栈：
	1.读取一个数，就直接压栈
	2.如果读取到操作符，就从栈中弹出两个数，进行操作，例如：
		ab- --> a-b		后弹出的作为减数，除法亦然
	3.然后将得到的数再压入栈
	4.最后栈中只有一个数，即为最后得到的数
*/

/*
Java 代码实现中缀表达式转后缀表达式
写了 choose 方法，以及自己写的 Stack 类
*/
class StackOfDouble{
	public double[] a;
	public int top = 0;

	StackOfDouble(int length){
		a = new double[length];
	}

	public boolean isEmpty(){
		if(top == 0){
			return true;
		}else{
			return false;
		}
	}
	public double pop(){
		return a[top--];
	}
	public double peek(){
		return a[top];
	}
	public void push(double index){
		top++;
		a[top] = index;
	}
}

class StackOfChar{
	public char[] a;
	public int top = -1;

	StackOfChar(int length){
		a = new char[length];
	}

	public boolean isEmpty(){
		if(top == -1){
			return true;
		}else{
			return false;
		}
	}
	public char pop(){
		top--;
		return a[top+1];
	}
	public char peek(){
		return a[top];
	}
	public void push(char index){
		top++;
		a[top] = index;
	}
}

public static String choose(String a){
	String b = "";
	StackOfChar stack = new StackOfChar(a.length());
	for(int i = 0;i < a.length();i++){
		char t = a.charAt(i);
		if((t >= 48)&&(t <= 57)){
			b = b+t;
		}else{
			if(stack.isEmpty()){
				stack.push(t);
			}else{
				switch(t){
					case '(':stack.push(t);break;
					case ')':while(stack.peek() != '('){
								b = b+stack.pop();
							}
							stack.pop();
							break;
					case '+':while(!stack.isEmpty()&&(stack.peek() != '(')){
								b = b+stack.pop();
							}stack.push(t);break;
					case '-':while(!stack.isEmpty()&&(stack.peek() != '(')){
								b = b+stack.pop();
							}stack.push(t);break;
					case '*':while(!stack.isEmpty()&&(stack.peek() != '(')&&(stack.peek() != '+')&&(stack.peek() != '-')){
								b = b+stack.pop();
							}stack.push(t);break;
					case '/':while(!stack.isEmpty()&&(stack.peek() != '(')&&(stack.peek() != '+')&&(stack.peek() != '-')){
								b = b+stack.pop();
							}stack.push(t);break;
				}
			}
		}
	}
	while(!stack.isEmpty()){
		b = b+stack.pop();
	}
	return b;
}
	
public static double polish(String a){
	StackOfDouble stack = new StackOfDouble(a.length());
	for(int i = 0;i < a.length();i++){
		char t = a.charAt(i);
		if((t >= 48)&&(t <= 57)){
			stack.push((double)(t-48));
		}else{
			switch(t){
				case '+':stack.push(stack.pop()+stack.pop());break;
				case '-':double temp1 = stack.pop();
						 stack.push(stack.pop()-temp1);
						 break;
				case '*':stack.push(stack.pop()*stack.pop());break;
				case '/':double temp2 = stack.pop();
						 stack.push(stack.pop()/temp2);
						 break;
			}
		}
	}
	return stack.pop();
}
