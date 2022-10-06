package day002;

import java.util.Scanner;
import java.util.Stack;

/**
 * 递归方法求一个数组中的最大值
 */
public class GetMax {
    public static int getMax(int[] arr) {
        return process(arr, 0, arr.length - 1);
    }

    //arr[L...R]范围上求最大值
    public static int process(int[] arr, int L, int R) {
        if (L == R)  //范围内只有一个数了，直接返回，base case
            return arr[L];

        int mid = L + ((R - L) >> 1);  //求中点，这种写法是为了防止l+r溢出
        int leftMax = process(arr, L, mid);
        int rightMax = process(arr, mid + 1, R);
        return Math.max(leftMax, rightMax);
    }

}
