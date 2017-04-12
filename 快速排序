/*
	快速排序，将数组分成两部分，属于一种分治法策略（类似归并但不完全是归并）。
分成的两部分不必要是数组的两半，快速排序从数组中选出一个元素，称为支点，然后重
新排列数组元素，从而：
	1.支点所在的位置就是该元素最终存在的位置。
	2.支点之前的元素全部大于（小于）或等于支点
	3.支点之后的元素全部小于（大于）或等于支点
这样一次排序称为一次划分。
使用递归：
	quickSort(a,first,last)
	if(first < last){
		pivotIndex = 支点索引
		quickSort(a,first,pivotIndex-1)
		quickSort(a,pivotIndex+1,last)
	}
使用递归的速度问题：
这里使用递归与斐波那契数列中使用递归在速度上有不同。原因就是因为方式从而导致的
速度不同。

关于快速排序中递归算法的效率问题，快排是不稳定的。平均的情况下时间复杂度是
O(n logn) 而在最坏的情况下是 O(n^2) 
与归并排序的比较：
归并排序更稳定，永远是 O(n logn) 。而快速排序则不稳定，但是在大部分时间内，速度
是优于归并排序的。并且不需要额外储存。

算法实现过程：
1.选择支点：
	支点的选择有多种方法，“三者取中值支点选择法”。即获得首位、末位、中间三位数，
然后进行排序，mid 即为支点。但是一般为了追求方便，一般直接将首位当做中间位，这样
同时省去了移动 mid 的过程
注意：使用三者取中的时候，在之后要进行一次划分调整。由于 first mid last 三者的顺
序已经确定，所以在计算的时候三者顺序不用再考虑。
2.递归划分：
	递归划分也有很多种，这是一种。
	整体就是从前后两个方向进发，先逆序查找，找到小于 key 值的数，然后停止，换成正
序查找，找到大于 key 值的数，然后与另一个数交换。知道 left = right。第一次查询结
束。然后将 key 值从 a[0] 移动到left所在位置（实际上 right 也在）。此时，key位置前
的元素全部小于 key 值，右边的全大于。
3.递归：
	递归时注意临界点选择就可以。
*/

/*Java 实现*/

import java.util.Random;

public class Main{
	public static void quickSort(int[] a,int left,int right){
		// quickSort 结束递归条件
		if(left > right){
			return;
		}

		int key = a[left];
		int l = left;
		int r = right;
		int temp = 0;
		// while 内是一次规划，直接分成左右两部分。
		while(l != r){
			while((a[r] >= key)&&(l < r)){
				r--;
			}
			while((a[l] <= key)&&(l < r)){
				l++;
			}
			if(l < r){
				temp = a[l];
				a[l] = a[r];
				a[r] = temp;
			}
		}
		// 将key值转到中间位置
		a[left] = a[l];
		a[l] = key;
		
		// 递归调用，注意left 与 right的选择，不能暴力使用 0 与 a.length
		quickSort(a,left,l-1);
		quickSort(a,l+1,right);
	}

	public static void main(String[] args){
		Random random = new Random();

		int[] a = new int[10];
		for(int i = 0;i < 10;i++){
			a[i] = random.nextInt(10);
		}
		for(int i = 0;i < 10;i++){
			System.out.printf("%d ",a[i]);
		}
		System.out.println();
		quickSort(a,0,a.length-1);
		for(int i = 0;i < 10;i++){
			System.out.printf("%d ",a[i]);
		}
	}
}
