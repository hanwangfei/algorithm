package day001;

import java.util.Arrays;

/**
 * 插入排序，时间复杂度最好情况O(N),最查情况O(N^2),但由于O都是按照最差情况估计，所以说插入排序的时间复杂度是O(N^2)
 */
public class InsertionSort {
    public static void insertionSort(int[] arr) {
        if (arr == null || arr.length < 2)
            return;

        for (int i = 0; i < arr.length; i++) {  //想要0 --i 范围做到有序
            for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) //从i位置往前看，已经做到0 - i-1位置有序了，如果前面的数比你大，则你往前移动然后继续与你前面的比较，直到你前面的数比你小或者越界停
                Utils.swapYiHuo(arr, j, j + 1);
        }
    }

    public static void main(String[] args) {
        int[] arr = Utils.getArray(10, 0, 100);
        System.out.println(Arrays.toString(arr));
        insertionSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
