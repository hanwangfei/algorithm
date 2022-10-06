package day003;

import java.util.PriorityQueue;

/**
 * 堆排序引出的问题，现有一组数，他们基本有序，已知他们每一个元素现在的位置与它排好序的位置不会相差超过k,问有没有一种办法，能够在堆排序的基础上继续优化时间复杂度，使得这个数组有序
 */
public class SortArrayDistanceLessk {
    public void sortedArrDistanceLessK(int[] arr, int k) {
        PriorityQueue<Integer> heap = new PriorityQueue<>();  //系统提供的堆结构，默认是小根堆
        int index = 0;
        for (; index < Math.min(arr.length, k); index++)  //先把前k个数放到小根堆里面,那么此时小根堆的第一个元素一定排好序，应为在小根堆范围内它就是最小的，超出范围它的移动距离就大于k,显然不符合题意
            heap.add(arr[index]);
        int i = 0;
        for (; index < arr.length; i++, index++) {
            heap.add(arr[index]);        //继续往小根堆加入数据，每加入一个，就将已经排好序的第一个数据弹出
            arr[i] = heap.poll();
        }
        while (!heap.isEmpty())  //所有数都加入后，依次弹出小根堆中剩余的数据即可
            arr[i++] = heap.poll();
    }
}
