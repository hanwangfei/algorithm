package day002;

/**
 * 求小和的问题：给定一个数组如1 3 4 2 5,每一个元素比他左边数大，则产生该数的小和，所有元素小和的总和就是该数组的小和。如1无小和，3的小和是1，4的小和是1 + 3 =4，2的小和是1，5的小和是1 + 3+ 4+2=10，所以最终的小和是0+1+4+1+10=16
 * 求解该问题的思路：借助归并排序的特性，首先将问题逆向思维，1的右边有多少数比它大，就产生多少个1的小和，因此1产生4*1=4，3产生2*3=6,4产生1*4=4，2产生1*2=2,5产生0,最终小和是4+6+4+2=16
 */
public class SmallSum {
    public static int smallNum(int[] arr) {
        if (arr == null || arr.length < 2)
            return 0;
        return process(arr, 0, arr.length - 1);
    }

    //arr[L...R]既要排好序，也要求小和
    public static int process(int[] arr, int l, int r) {
        if (l == r)
            return 0;
        int mid = l + ((r - l) >> 1);
        return process(arr, l, mid)   //左侧排好求小和的数量
                + process(arr, mid + 1, r)    //右侧排好求小和的数量
                + merge(arr, l, mid, r);    //左右两侧merge求小和的数量
    }

    //只有一句代码和归并排序有区别
    public static int merge(int[] arr, int L, int m, int r) {
        int[] help = new int[r - L + 1];
        int i = 0;
        int p1 = L;
        int p2 = m + 1;
        int res = 0;
        while (p1 <= m && p2 <= r) {
            res += arr[p1] < arr[p2] ? (r - p2 + 1) * arr[p1] : 0;   //左侧比右侧小，则产生左侧元素*右侧数量的小和
            help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
        }
        while (p1 <= m)
            help[i++] = arr[p1++];
        while (p2 <= r)
            help[i++] = arr[p2++];
        for (i = 0; i < help.length; i++) {
            arr[L + i] = help[i];
        }
        return res;

    }

    public static void main(String[] args) {
        int[] arr = {1,3,4,2,5};
        System.out.println(smallNum(arr));
    }
}
