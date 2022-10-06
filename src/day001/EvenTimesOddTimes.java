package day001;

import javax.sound.midi.Soundbank;

/**
 * 异或面试题
 */
public class EvenTimesOddTimes {
    /**
     * 在一个数组中，只有一个数出现奇数次，其余数都出现偶数次，求该奇数？
     *
     * @param arr
     */
    public static void printOddTimesNum1(int[] arr) {
        int eor = 0;
        for (int cur : arr)   //所有出现偶数次的数异或完全抵消为0，0异或任何数等于任何数本身，最后剩下的就是那个出现奇数次的数
            eor ^= cur;
        System.out.println(eor);
    }


    /*
    有两个数a,b出现奇数次，剩下的都出现偶数次，怎么找到这两个数？
     */
    public static void printOddTimesNum2(int[] arr) {
        int eor = 0, onlyOne = 0;
        for (int cur : arr)
            eor ^= cur;          //eor = a^b,a!=b,  所以eor!=0,eor必然有一个位置上是1，假设我们现在要找到最右侧的1

        int rightOne = eor & (~eor + 1);  //提取出这个一个不等于0的数最右侧的1，剩下位置全变0
        for (int cur : arr) {
            if ((cur & rightOne) == 0) {  //这里将整个数组中的数按照某一位是0还是1分为两组，a,b一定各占一组，onlyOne选择其中一组进行异或，得到的就一定是a或者b,这里可以写等于0或者等于rightOne都行，就是看要异或那一组
                onlyOne ^= cur;         //循环结束,onlyOne一定是a或者b
            }
        }
        System.out.println(onlyOne + "  " + (eor ^ onlyOne));
    }


    public static void main(String[] args) {
        int[] arr={1,1,2,3,2,1,5,3};
        printOddTimesNum2(arr);
    }
}
