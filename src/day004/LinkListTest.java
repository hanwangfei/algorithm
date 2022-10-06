package day004;

import day001.Utils;

import java.util.Arrays;

public class LinkListTest {
    public static LinkList<Integer> list = new LinkList<>();

    public static void test1(){
        int[] arr = Utils.getArray(10,0,100);

        list.add(Arrays.stream(arr).boxed().toArray(Integer[]::new));   //将int数组转为Integer数组
        System.out.println(list);

    }

    public static void test2(){
        Integer[] arr = {1};
        System.out.println("测试回文 {1}：");
        list.add(arr);
        System.out.println(list.isPalindrome1(list.getHead()));
        System.out.println(list.isPalindrome2(list.getHead()));
        System.out.println(list.isPalindrome3(list.getHead()));

        list.clear();
        System.out.println("测试回文 {1,3,4,3,3,4,3,1}：");
        Integer[] arr2 = {1,3,4,3,3,4,3,1};
        list.add(arr2);
        System.out.println(list.isPalindrome1(list.getHead()));
        System.out.println(list.isPalindrome2(list.getHead()));
        System.out.println(list.isPalindrome3(list.getHead()));

        list.clear();
        System.out.println("测试回文 {1,3,4,3,3,2,4,3,1}：");
        Integer[] arr3 = {1,3,4,3,3,2,4,3,1};
        list.add(arr3);
        System.out.println(list.isPalindrome1(list.getHead()));
        System.out.println(list.isPalindrome2(list.getHead()));
        System.out.println(list.isPalindrome3(list.getHead()));


    }
    public static void main(String[] args) {
        test2();

    }
}
