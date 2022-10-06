package day003;

/**
 * 基数排序：
 * 1.在了解基数排序前，要现明白计数排序，也就是统计磁频，即比如有一群数范围是0-200，排大小，我们可以准备一个201这么大空间的数组，然后遍历这些数据，遇到一个数就在相应的位置上加1，最终能够统计出每个位置上有多少个数，诸如3个1，8个9，10个99...等等，然后就简单了，我们将这些数据从小到达写出来就可以了，这种排序是不基于比较的排序，局限性非常高，因为它要求数据有一个尽可能小的范围，否则加入要排整数，我们不可能准备一个21亿大小的数组来做统计，这就引出了我们的基数排序
 * 2.基数排序，以10进制为例，我们准备0-10共10个桶，然后以数据中最高为为标准，将其他数据对其，例如23，100，30.。。最高为为100三位，所以对其他数前面补0，23变成023，30变成030，然后从个为数开始，个为数为几就进几号桶，如23进3号桶，100进0号桶，30进0号桶，注意先进先出，然后将所有数据从左到右的桶到出来，就成了100，30，23，接着十位重复该过程，100进0号，030进3号，023进2号，到出来100 023 030，然后百位，100进1号，023进0号，030进0号，到出来 23 30 100就有序了
 */

import day001.Utils;

import java.util.Arrays;

/**
 * 以下代码在原思路上进行了大量优化,且只适用于非负整数
 */
public class RadixSort {

    public static void radixSort(int[] arr) {
        if (arr == null || arr.length < 2)
            return;
        radixSort(arr, 0, arr.length - 1, maxbits(arr));
    }

    /**
     * 计算最大值有几个十进制位
     *
     * @param arr
     * @return
     */
    public static int maxbits(int[] arr) {
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            max = Math.max(max, arr[i]);
        }
        int res = 0;
        while (max != 0) {
            res++;
            max /= 10;
        }
        return res;
    }

    /**
     * @param arr
     * @param L
     * @param R
     * @param digit 最大的值有几位？如1223有4位，190有三位
     */
    public static void radixSort(int[] arr, int L, int R, int digit) {
        final int radix = 10;  //10进制以10为基底
        int i = 0, j = 0;

        //有多少个数据准备多少个辅助空间
        int[] bucket = new int[R - L + 1];
        for (int d = 1; d <= digit; d++) {  //有多少位就进多少次
            int[] count = new int[radix];          //当前位是多少的数字有多少个，如count[0],当前位d位是0的有多少个
            for (i = L; i <= R; i++) {
                j = getDigit(arr[i], d);
                count[j]++;
            }
            for (i = 1; i < radix; i++)
                count[i] = count[i] + count[i - 1];
            for (i = R; i >= L; i--) {   //数组从右往左遍历
                j = getDigit(arr[i], d);
                bucket[count[j] - 1] = arr[i];
                count[j]--;
            }
            for (i = L, j = 0; i <= R; i++, j++)
                arr[i] = bucket[j];

        }
    }

    public static int getDigit(int x, int d) {
        return ((x / ((int) Math.pow(10, d - 1))) % 10);
    }

    public static void main(String[] args) {
        int[] arr = Utils.getArray(10, 0, 100);
        System.out.println(Arrays.toString(arr));
        radixSort(arr);
        System.out.println(Arrays.toString(arr));
    }

}
