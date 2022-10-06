package day003;

import day001.Utils;

import java.util.Arrays;

/**
 * 堆排序：二叉树版的冒泡排序，时间复杂度O(N*logN),空间复杂度O(1) 注意堆结构有个别名：优先级队列，它就是堆的一种
 * 思路简述：用户给的数组想像成用户需要一个一个的给你数，你每拿到一个数都要使其保持大根堆结构（heapInsert操作),当所有数据输入完毕后，交换头节点和堆的最后一个元素，然后heapSize--,将最大值断开堆结构，然后交换到头节点上的新元素进行heapify过程，使其仍然保持大更堆结构，然后继续交换头节点和最后一个元素，周而复始，这整个过程其实很像是冒泡排序，在找数组中最大的元素然后一个个的弹出，不过它用的是logN级别的二叉树结构，所以时间复杂度有了大幅度优化。
 * 1.什么是堆？堆是一种完全二叉树结构，完全二叉数是指一棵树从左到右依次变满的结构，即任意一个节点如果有右孩子则它一定有左孩子，满二叉树是一种特殊的完全二叉树，即左右孩子都有
 * 2.堆的性质，假如将数组下标0-n依次放入堆中，那么任意一个位置i，他的左孩子下标必定是2*i+1,右孩子下标必定是2*i+2,父节点下标必定是(i-1)/2,向下取整
 * 3.大根堆与小根堆，在一棵完全二叉树中，如果任意一棵子树，他的父节点大于所有他的子节点，则该堆为大根堆，相反小于所有子节点为小根堆
 */
public class HeapSort {


    /**
     * 放入的数现在在index位置，往上窜形成大根堆的过程
     *
     * @param arr   数组
     * @param index 新来的数现在所在的位置
     */
    //放入的数逐渐形成大根堆的过程，每一个新进来的元素都要找它的父节点比较，如果大于父节点，则交换，直到它没有父节点或者它比父节点小的时候停止
    public static void heapInsert(int[] arr, int index) {
        while (arr[index] > arr[(index - 1) / 2]) {     //当它没有父节点，index=0时，算出的(index-1)/2也会是0，不满足大于条件，停止
            Utils.swapPuTong(arr, index, (index - 1) / 2);
            index = (index - 1) / 2;   //交换之后该元素来到它父节点的位置，继续进行比较
        }

    }

    /**
     * 判断某个数在index位置，能否继续往下移动的过程。相当于有一个大根堆，现在我们拿掉它的头节点，要使得剩下的元素仍然保持一个大根堆结构，要如何操纵？
     * 首先，我们将头节点和最后一个节点交换，新上来的这个节点位置记为index，初始为0，现在让他和它的左右孩子中较大的那一个进行比较，如果它比它的孩子小，那么就交换，直到它没有孩子了或者它比它的孩子大停止
     *
     * @param arr      数组
     * @param index    从哪个位置往下开始窜
     * @param heapSize 堆的大小，有heapSize来判断是否有左孩子右孩子
     */
    public static void heapify(int[] arr, int index, int heapSize) {
        int left = index * 2 + 1;  //左孩子的下标
        while (left < heapSize) {  //下方还有孩子的时候
            //两个孩子中，谁的值大，吧谁的小标给largest
            int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
            //父和较大孩子之间，谁的值大，吧下标给largest
            largest = arr[largest] > arr[index] ? largest : index;
            if (largest == index)
                break;   //如果父和最大的孩子相等，停止下窜，退出
            Utils.swapPuTong(arr, largest, index);  //否则，交换父和他最大的孩子
            index = largest;   //父来到他最大孩子的位置，看是否要继续下窜
            left = index * 2 + 1;  //更新左孩子下标，进行下一轮循环
        }
    }


    public static void heapSort(int[] arr) {
        if (arr == null || arr.length < 2)
            return;
        for (int i = 0; i < arr.length; i++) {  //O(N)  //这里有更快一点点的方法
            heapInsert(arr, i);   //O(logN)
        }
//        for(int i = arr.length-1;i>=0;i--){        //将heapInsert的过程变成heapify,也可以使得整个数组变成大根堆，会比上面的方法快一点，但堆排序的性能核心是下面的heapify,所以不会对堆排序的时间复杂度造成影响
//            heapify(arr,i,arr.length);
//        }
        int heapSize = arr.length;
        Utils.swapPuTong(arr, 0, --heapSize);
        while (heapSize > 0) {   //O(N)
            heapify(arr, 0, heapSize);  //O(logN)
            Utils.swapPuTong(arr, 0, --heapSize);   //O(1)
        }
    }


    public static void main(String[] args) {
        int[] arr = Utils.getArray(10, 0, 100);
        System.out.println(Arrays.toString(arr));
        heapSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
