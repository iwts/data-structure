/*
	选择排序速度是优于冒泡排序的，在php5.6下，选择排序的速度是
	冒泡排序的7倍。
	两者区别：
		冒泡排序是每一次比较如果需要交换，就直接进行一次交换，
		像冒泡一样，将最大（最小）的排到最上边。
		选择排序是在两层 for 循环中，内层循环时，发现最大值，
		记录其所在位置，最后出内层循环后，再进行统一交换。
*/

import java.util.Random;
import java.util.Scanner;

public class Test{
	public static void main(String[] args){
		Random random = new Random();
		Scanner input = new Scanner(System.in);
		
		int i;
		int j;
		// max 变量记录内层循环时较大的数的下标
		int max;
		int temp;
		System.out.println("请输入随机数的总数：");
		int[] arr = new int[input.nextInt()];
		System.out.println("请输入随机数的最大范围：");
		int indexMax = input.nextInt();
		
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
	算法：两层循环。外层循环控制整体，内层循环进行单次比较。
		  首先假设外层 i 下标的数据即为最大，然后在内层循环
		  中一直与之后的数据进行比较，发现更大的数据，就将
		  max 由之前的 i 更换为 j。
		  当内层循环结束后，max 值即为从 arr[i] 开始最大的数
		  据。如果 arr[i] 就是最大，不作为。否则，将max记录
		  的最大值对应的数据与 arr[i] 进行交换。
		  这样，每次外层循环，只进行一次交换操作。
*/

		for(i = 0;i<arr.length-1;i++){
			max = i;
			for(j = i+1;j<arr.length;j++){
				if(arr[max] < arr[j]){
					max = j;
				}
			}
			if(max != i){
				temp = arr[i];
				arr[i] = arr[max];
				arr[max] = temp;
			}
		}

/**********************核心代码**************************/

		System.out.println("\n");
		
		System.out.println("排序后数据如下：");
		for(i = 0;i<arr.length;i++){
			System.out.printf("%-5d",arr[i]);
			if((i+1)%10 == 0){
				System.out.println();
			}
		}
		
	}
}
