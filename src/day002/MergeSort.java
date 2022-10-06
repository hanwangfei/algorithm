package day002;

import day001.Utils;

import java.util.Arrays;

/**
 * 归并排序，先让左右两边分别有序，然后用两个指针指向左右两边的第一个元素(也就是左右两边最小的元素)，比较两边元素大小，准备一个辅助空间，哪边更小拷贝哪边的元素，然后对应的指针往后移动，当一边拷贝完时，指针越界，此时将另一边的剩余元素全拷贝下来，然后将数据写回原数组进行覆盖
 * 时间复杂度由master公式求解，排序过程分成了两个等规模过程，Merge过程为O(N),所以T(N) = 2T(N/2) + O(N),由Master公式，a=2,b=2,d=1,logbA=d,所以时间复杂度为O(N*logN),空间复杂度O(N)
 */
public class MergeSort {
    public static void mergeSort(int[] arr) {
        if (arr == null || arr.length < 2)
            return;
        process(arr, 0, arr.length - 1);

    }

    public static void process(int[] arr, int L, int R) {
        if (L == R)    //一个数直接返回
            return;
        int mid = L + ((R - L) >> 1);
        process(arr, L, mid);  //左边排好序
        process(arr, mid + 1, R);  //右边排好序
        merge(arr, L, mid, R);
    }

    public static void merge(int[] arr, int L, int M, int R) {
        int[] help = new int[R - L + 1];
        int i = 0;
        int p1 = L;  //左指针
        int p2 = M + 1;   //右指针
        while (p1 <= M && p2 <= R) {  //指针不越界的情况下
            help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++]; //哪边更小拷贝哪边
        }
        //下边两个while只可能执行其中的一个,p1 p2执行完上面的while循环后，必然有且只有一个越界
        while (p1 <= M)  //左边有剩余，拷贝左边
            help[i++] = arr[p1++];
        while (p2 <= R)    //右边有剩余，拷贝右边
            help[i++] = arr[p2++];
        for (i = 0; i < help.length; i++)  //拷贝回原数组
            arr[L + i] = help[i];

    }

    public static void main(String[] args) {
        int[] arr = Utils.getArray(10,-100,100);
        System.out.println(Arrays.toString(arr));
        mergeSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
