/*桶排序----简单版本*/

/*
	桶排序的前提在于原数组的总数已经确定，如果不是 number 类
仍然可以通过 ASCII 码等方式来辅助排序。
	时间复杂度为 O(M+N)
	优点是速度快，但是缺点很明显：
	1.浪费内存。数组可能开的非常大。
	2.不算是完全的排序，浮点型直接gg。
	3.只能跟与整数有关的数据进行排序，人名字典顺序排序直接gg。
*/

import java.util.Random;

public class Main{
	public static void main(String[] args){
		Random random = new Random();

		int[] a = new int[10];
		int[] book = new int[10];
		/*
		这里为了初始化数组所以 for 循环分开写，实际上可以合并
		并且在实际上没必要这样做，直接核心部分排序。
		*/
		for(int i = 0;i < 10;i++){
			a[i] = random.nextInt(10);
		}
		/*
			核心循环。算法中心思想在于定义数组，下标即为该数。通过第一次遍历
		原数组，将每次出现的数字在 book 数组中对应的元素处标记。然后遍历 book
		数组，双重循环输出。这样在构造 book 数组的同时已经拍完序了。（正序与
		逆序可以通过改变 i++ 与 i-- 完成）
		*/
		for(int i = 0;i < 10;i++){
			book[a[i]]++;
		}
		for(int i = 0;i < 10;i++){
			for(int j = 0;j < book[i];j++){
				System.out.printf("%d ",i);
			}
		}
	}
}

/*
桶排序是一种很好的思想，即利用数组下标来完成问题。在刷ACM的时候已经很多次使用
这样的方法。不一定创建 int 数组，ACM题中尤其涉及矩阵，构造 boolean 数组更好。
*/
