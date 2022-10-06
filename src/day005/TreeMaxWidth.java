package day005;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class TreeMaxWidth {

    /**
     * 宽度优先遍历，也就是层次遍历
     * 思路：用队列。 先吧头节点放入，然后弹出过程中，先放左在放右
     *
     * @param head
     */
    public static void withTraversal(Node head) {
        if (head == null) return;
        Queue<Node> queue = new LinkedList<>();
        queue.add(head);
        while (!queue.isEmpty()) {
            Node cur = queue.poll();
            System.out.println(cur.value + " ");
            if (cur.left != null) queue.add(cur.left);
            if (cur.right != null) queue.add(cur.right);
        }
    }


    /**
     * 获取一棵二叉树的最大宽度
     * 思路：我需要知道每一个节点在哪一层，将其登记到hashMap中，然后借助宽度优先遍历，从第一层开始统计，当节点跳转到下一层时，就可以得出上一层的节点数，看该数目是否大于max,更新max,然后开始统计下一层的节点
     * @param head
     * @return
     */
    public static int w(Node head) {
        if (head == null)
            return 0;
        Queue<Node> queue = new LinkedList<>();
        queue.add(head);
        HashMap<Node, Integer> levelMap = new HashMap<>();
        levelMap.put(head, 1);
        int curLevel = 1;   //当前在统计第几层
        int curLevelNodes = 0;   //当前层的节点数量
        int max = Integer.MIN_VALUE;   //max初始为系统最小

        while (!queue.isEmpty()) {
            Node cur = queue.poll();
            int curNodeLevel = levelMap.get(cur);
            if (curNodeLevel == curLevel) {
                curLevelNodes++;    //是当前层，节点树++
            } else {
                max = Math.max(max, curLevelNodes);  //不是当前层，上一层可以进行计算了，跟新max值
                curLevel++;   //统计层数来到下一层
                curLevelNodes = 1;   //当前已经发现一个节点了，重置发现的节点数量
            }

            if (cur.left != null) {
                levelMap.put(cur.left, curNodeLevel + 1);
                queue.add(cur.left);
            }

            if (cur.right != null) {
                levelMap.put(cur.right, curNodeLevel + 1);
                queue.add(cur.right);
            }

        }
        return max;
    }
}
