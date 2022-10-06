package day002;

import day001.Utils;

import java.util.Arrays;

/**
 * 快速排序3.0，时间复杂度最差O(N^2),但由于借助随机选取了划分值，破环了该随机性，每一个元素被选中为划分值的概率是随机的，因此需要对N种情况求数学期望，最终得出快排的时间复杂度是O(N*logN)，空间复杂度为logN (与划分值的选取有关系，这里也是一个数学期望的结论)
 */

/**
 * 荷兰国旗问题，也就是下面的partition过程，问题描述：给定一个数组和一个数Num,要求对数组一番操作后，等于Num的数全放在中间，小于Num的数全放在左边，大于Num的数全放在右边，也就是将数组分为小于，等于，大于Num的三个区域，在这些区域内部是不要求有序的。
 * 解法思路： 三指针操作，左指针less初始指向-1位置，右指针more初始指向数组最后一个元素，指针L=数组第一个元素，划分值Num为数组最后一个数，开始遍历数组，做如下操作：
 * 当前数arr[L]<划分值arr[R],交换当前数和小于区域的下一个arr[++less],L往后移动，L++
 * 当前数arr[L]>划分值arr[R],交换当前值和大于区域的前一个arr[--more],L此时保持不动，因为由后面换到前面去的数要再次比较大小
 * 当前数arr[L]=划分值arr[R],L直接往后移动，L++
 * 上述判断一直持续到L指正进入了大于区域，也就是L>=more时结束，最后由于大于区域的最后一个划分元素Num,也就是arr[R],始终为栋，我们需要将这个数移动到中间来，那么交换一下arr[more]和arr[R]即可，至此，荷兰国旗问题解决，那么快速排序就是在荷兰国旗的问题上对左边小于区域和右边大于区域重复上述所有过程，也就是跑递归，就可以使得整个数组一定能达到有序状态。
 */
public class QuickSort {
    public static void quickSort(int[] arr) {
        if (arr == null || arr.length < 2)
            return;
        quickSort(arr, 0, arr.length - 1);
    }

    public static void quickSort(int[] arr, int L, int R) {
        if (L < R) {
            Utils.swapPuTong(arr, L + (int) (Math.random() * (R - L + 1)), R);       //随机选一个位置与最右侧的位置做交换，然后以最右侧位置的数做partition
            int[] p = partition(arr, L, R);
            quickSort(arr, L, p[0] - 1);      //小于区
            quickSort(arr, p[1] + 1, R);      //大于区
        }
    }

    /**
     * 处理arr[l...r]的函数,类似荷兰国旗问题
     *
     * @param arr 数组
     * @param L   左边界
     * @param R   右边界
     * @return 返回一个等于区域（左边界，右边界），也就是一个长度为2的数组res,res[0],res[1]
     */
    public static int[] partition(int[] arr, int L, int R) {
        int less = L - 1;     //<区右边界
        int more = R;         //>区左边界
        while (L < more) {          //L表示当前数的位置，arr[R]就是划分值
            if (arr[L] < arr[R])         //当前数小于划分值
                Utils.swapPuTong(arr, ++less, L++);
            else if (arr[L] > arr[R])
                Utils.swapPuTong(arr, --more, L);   //当前数大于划分值
            else
                L++;
        }
        Utils.swapPuTong(arr,more,R);
        return new int[]{less+1,more};
    }


    public static void main(String[] args) {
        int[] arr = Utils.getArray(10,0,100);
        System.out.println(Arrays.toString(arr));
        quickSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
