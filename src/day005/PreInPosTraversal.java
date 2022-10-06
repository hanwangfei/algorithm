package day005;

import java.util.Stack;

/**
 * 二叉树的遍历：递归的方法最本质的原理是递归序，在递归的不同时间段做出不同的行为,注意二叉树的深度优先遍历指的就是先序，中序，后序三种遍历
 * 先序遍历：头左右   中序遍历：左头右    后序遍历：左右头
 */
public class PreInPosTraversal {
    //递归序的本质，每一个节点必然来到三次，如何递归遍历一棵树，只需要在不同的位置进行值的展示
    public static void f(Node head) {
        //1.第一次来到该节点，先序遍历
        if (head == null)
            return;
        f(head.left);
        //2.第二次来到该节点，中序遍历
        f(head.right);
        //3.第三次来到该节点，后序遍历
    }

    //先序遍历，只在第一次到达该节点时打印
    public static void preOrderRecur(Node head) {
        if (head == null)
            return;
        System.out.print(head.value + " ");
        preOrderRecur(head.left);
        preOrderRecur(head.right);
    }

    //中序遍历，只在第二次到达该节点时打印
    public static void inOrderRecur(Node head) {
        if (head == null)
            return;
        inOrderRecur(head.left);
        System.out.print(head.value + " ");
        inOrderRecur(head.right);
    }

    //后序遍历，只在第三次到达该节点时打印
    public static void posOrderRecur(Node head) {
        if (head == null)
            return;
        posOrderRecur(head.left);
        posOrderRecur(head.right);
        System.out.print(head.value + " ");
    }

    /**
     * 非递归行为实现先序遍历
     * 思路：首先准备一个栈，起步将头节点扔到栈里面去。 然后：1.将栈顶元素弹出，进行处理（打印）  2.先将该元素的右孩子放入栈中，再将该元素的左孩子放入栈中，如果没有就跳过  3.重复1和2，直到栈空
     *
     * @param head
     */
    public static void preOrderUnRecur(Node head) {
        System.out.print("pre-order: ");
        if (head != null) {
            Stack<Node> stack = new Stack<>();
            stack.add(head);
            while (!stack.isEmpty()) {
                head = stack.pop();
                System.out.print(head.value + " ");
                if (head.right != null)
                    stack.push(head.right);
                if (head.left != null)
                    stack.push(head.left);

            }
        }
        System.out.println();
    }

    /**
     * 非递归行为实现后序遍历
     * 思路：首先准备两个个栈，一个容器栈，一个收集栈，起步将头节点扔到容器栈里面去.  然后：1.弹出容器栈的栈顶元素扔到收集栈中去 2.将该元素先左孩子后右孩子放到容器栈中去,如果没有则跳过  3.重复1和2，直到栈空,然后将收集栈中的节点依次到出来，就是后序遍历
     *
     * @param head
     */
    public static void posOrderUnRecur(Node head) {
        System.out.print("pos-order: ");
        if (head != null) {
            Stack<Node> s1 = new Stack<>();
            Stack<Node> s2 = new Stack<>();
            s1.push(head);
            while (!s1.isEmpty()) {
                head = s1.pop();
                s2.push(head);
                if (head.left != null)
                    s1.push(head.left);
                if (head.right != null)
                    s1.push(head.right);
            }
            while (!s2.isEmpty())
                System.out.print(s2.pop().value + " ");
        }
        System.out.println();
    }

    /**
     * 非递归行为实现中序遍历
     * 思路：首先将整棵树的左边界进栈，依次弹出的过程中：弹出就打印，如果弹出的节点有右节点，对它的右数也这么干，即右数的左边界进栈，然后弹出
     *
     * @param head
     */
    public static void inOrderUnRecur(Node head) {
        System.out.print("in-order: ");
        if (head != null) {
            Stack<Node> stack = new Stack<>();
            while (!stack.isEmpty() || head != null) {
                if (head != null) {   //这个分支在不停的将左边界进栈
                    stack.push(head);
                    head = head.left;
                } else {            //当head延左窜到空的位置时，开始弹出并打印
                    head = stack.pop();
                    System.out.print(head.value + " ");
                    head = head.right;    //head去往它的右孩子，如果它有右孩子，那么又会进入逻辑分支1，继续处理左边界
                }
            }
        }
        System.out.println();
    }

}
