package day001;

import java.util.Random;

public class Utils {
    public static int[] getArray(int size,int min,int max){
        Random random = new Random();
        int[] arr = random.ints(size,min,max).toArray();
        return arr;
    }

    public static void swapPuTong(int[] arr,int i,int j){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    /*
    异或：相同为0，不同为1，相当于无进位相加
    性质：0^N = N            N ^ N = 0
    满足交换律和结合律
     */
    //交换,借助异或运算的实现，这个函数成功的前提是两个交换变量的值可以相同，但内存不可以相同，意思就是i位置不可以等于j位置，否则会将该位置的数抹为0
    public static void swapYiHuo(int[] arr, int i, int j) {
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
    }
}
