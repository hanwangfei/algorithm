package day001;


import java.util.Arrays;
import java.util.Random;

/**
 * 冒泡排序，时间复杂度O(N^2),空间复杂度O(1),冒泡和插入的区别：冒泡是比较交换比较交换，可能发生多次交换，插入是比较比较最后交换，每循环一轮只交换一次
 */
public class BubbleSort {
    public static void bubbleSort(int[] arr) {
        if (arr == null || arr.length < 2)
            return;
        for (int e = arr.length-1; e > 0; e--) {   //总0到n上轮回
            for (int i = 0; i < e; i++) {   //第一次从0到n上比较，比较玩最后一个最大，第二次从0到n-1上比较，比较完后N-1位置第二大。。。。
                if (arr[i] > arr[i + 1]) {
                    Utils.swapYiHuo(arr, i, i + 1);
                }
            }
        }
    }


    public static void main(String[] args) {
        System.out.println("这是测试更改后重新推送到git");
        int[] arr = Utils.getArray(10,0,100);
        System.out.println(Arrays.toString(arr));
        bubbleSort(arr);
        System.out.println(Arrays.toString(arr));


    }
}
