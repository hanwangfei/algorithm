package day001;

import java.util.Arrays;
/**
 * 选择排序
 * 有限几个变量的空间，空间复杂度O(1)
 * 时间复杂度0(N^2)
 */
public class SelectionASort {
    public static void selectionSort(int[] arr) {
        if (arr == null || arr.length < 2) {  //洗掉捣乱参数
            return;
        }
        for (int i = 0; i < arr.length - 1; i++) {  // i --  N-1
            int minIndex = i;   //假定最开始最小值就是i位置
            for (int j = i + 1; j < arr.length; j++) {    // i+1 -- N上寻找是否有比MinIndex上更小的值
                minIndex = arr[j] < arr[minIndex] ? j : minIndex;   //如果有，更换最小值的坐标
            }
            Utils.swapPuTong(arr, i, minIndex);   //交换i位置的数和最小值
        }
    }



    public static void main(String[] args) {
        int[] arr = Utils.getArray(10,0,100);
        System.out.println(Arrays.toString(arr));
        selectionSort(arr);
        System.out.println(Arrays.toString(arr));
    }

}
