package day004;

import java.util.Stack;

public class LinkList<T> {
    // 节点类,单指针
    class Node {
        private T data;
        private Node next;

        public Node(T data) {
            this.data = data;
        }

        public T getData() {
            return data;
        }

        public void setData(T data) {
            this.data = data;
        }

        public Node getNext() {
            return next;
        }

        public void setNext(Node next) {
            this.next = next;
        }
    }

    //节点类，双指针
    class DoubleNode {
        public T value;
        public DoubleNode last;
        public DoubleNode next;

        public DoubleNode(T data) {
            this.value = data;
        }
    }

    private Node head;   //头节点

    public Node getHead() {
        return head;
    }

    //头插法
    public LinkList<T> addFirst(T data) {
        Node node = new Node(data);
        if (this.head != null) {
            node.next = this.head;      //如果链表不为空，将头节点插入新来的节点后面
        }
        this.head = node;    //更新头节点
        return this;
    }

    //尾插法
    public LinkList<T> addLast(T data) {
        Node node = new Node(data);
        Node cur = this.head;
        if (this.head == null)
            this.head = node;
        else {         //找到链表最后一个节点并插入
            while (cur.next != null)
                cur = cur.next;
            cur.next = node;
        }

        return this;
    }

    public void clear() {
        while (this.head != null) {
            Node cur = this.head.next;
            this.head.next = null;
            this.head = cur;
        }
    }

    //尾插，一整个数组
    public LinkList<T> add(T[] data) {
        for (T datum : data) {
            this.addLast(datum);
        }
        return this;
    }


    @Override
    public String toString() {
        Node cur = head;
        String str = "";
        while (cur != null) {
            str = (str + " " + cur.getData());
            cur = cur.next;
        }
        return "LinkList{" +
                str + "}";
    }

    //判断一个链表是否是回文结构
    //思路1：准备一个栈，遍历链表，每个元素都压入栈中，然后在次遍历，链表走一个，栈中弹出一个，比较是否相等，如果都相等则是回文结构
    public boolean isPalindrome1(Node head) {
        Stack<Node> stack = new Stack<>();
        Node cur = head;
        while (cur != null) {
            stack.push(cur);
            cur = cur.next;
        }
        cur = head;
        while (cur != null) {
            if (cur.data != stack.pop().getData()) {
                return false;
            }
            cur = cur.next;
        }
        return true;
    }

    //思路二： 节省一半的空间，快慢指针，快指针一次走两个，慢指针走一个，快指针走完，慢指针来到中点位置，然后只需要将后面的一半入栈，然后和前面的一半比较是否相等即可
    public boolean isPalindrome2(Node head) {
        if (head == null || head.next == null)
            return true;
        Node right = head.next;
        Node cur = head;
        while (cur.next != null && cur.next.next != null) {
            right = right.next;
            cur = cur.next.next;
        }
        Stack<Node> stack = new Stack<>();
        while (right != null) {
            stack.push(right);
            right = right.next;
        }
        cur = head;
        while (!stack.isEmpty()) {
            if (cur.data != stack.pop().getData())
                return false;
            cur = cur.next;
        }
        return true;
    }

    //最省空间的思路
    public boolean isPalindrome3(Node head){
        if(head==null||head.next==null)
            return true;
        Node n1 = head;
        Node n2=head;
        while (n2.next!=null&&n2.next.next!=null){
            n1=n1.next;
            n2=n2.next.next;
        }
        n2=n1.next;
        n1.next=null;
        Node n3 = null;
        while (n2!=null){
            n3=n2.next;
            n2.next=n1;
            n1=n2;
            n2=n3;
        }
        n3=n1;
        n2=head;
        boolean res = true;
        while (n1!=null&&n2!=null){
            if(n1.data!=n2.data) {
                res = false;
                break;
            }
            n1=n1.next;
            n2=n2.next;
        }
        n1=n3.next;
        n3.next=null;
        while (n1!=null){
            n2=n1.next;
            n1.next=n3;
            n3=n1;
            n1=n2;
        }
        return res;
    }




}
