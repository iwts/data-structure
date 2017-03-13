/*
	选择排序是抽象了两个数组，参考打扑克时抽牌的情形：
	牌组是乱序数组 arr ，自己手上的牌是正序数组 arrSorting
	此时，从牌组中抽取的牌，经过比较，插入到手牌中的
	正确位置。
*/

import java.util.Random;
import java.util.Scanner;

public class Test{
	public static void main(String[] args){
		Random random = new Random();
		Scanner input = new Scanner(System.in);
		
		int i;
		int j;
		int temp;
		System.out.println("请输入随机数的总数：");
		int[] arr = new int[input.nextInt()];
		System.out.println("请输入随机数的最大范围：");
		int indexMax = input.nextInt();
		
		// 定义正序数组
		int[] arrSorting = new int[20];
		
		// 随机给数组赋值
		for(i = 0;i<arr.length;i++){
			arr[i] = random.nextInt(indexMax);
		}
		
		// 输出一次排序前数据
		System.out.println("排序前数据如下：");
		for(i = 0;i<arr.length;i++){
			System.out.printf("%-5d",arr[i]);
			if((i+1)%10 == 0){
				System.out.println();
			}
		}
		
/**********************核心代码**************************/

/*
	算法：两层循环。外层循环控制整体，内层循环进行抽牌后的
		  插入。
		  首先构造正序数组，刚开始只有乱序数组 arr[0]，将
		  其作为 arrSorting[0]。之后每进行一次外层循环，就
		  是在正序数组的末尾添加一个数据，所以要写
		  arrSorting[i] = arr[i];
		  内层循环对新数据进行插入，从末尾开始，依次与前一
		  个数组元素进行比较，如果新数据大，就交换位置，直
		  到位置确定，那么就插入成功，退出内层循环。
		  所以内层循环使用了 if-else 结构。
		  注意内层循环时，由于元素一直是前移的，所以交换部
		  分代码是对arrSorting直接进行 j 与 j-1 的比较。
*/
		
		arrSorting[0] = arr[0];
		for(i = 1;i<arr.length;i++){
			arrSorting[i] = arr[i];
			for(j = i;j>0;j--){
				if(arrSorting[j] > arrSorting[j-1]){
					temp = arrSorting[j];
					arrSorting[j] = arrSorting[j-1];
					arrSorting[j-1] = temp;
				}else{
					break;
				}
			}
		}

/**********************核心代码**************************/

		System.out.println("\n");
		
		System.out.println("排序后数据如下：");
		for(i = 0;i<arr.length;i++){
			System.out.printf("%-5d",arrSorting[i]);
			if((i+1)%10 == 0){
				System.out.println();
			}
		}
		
	}
}
