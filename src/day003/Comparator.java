package day003;

import java.util.Arrays;
import java.util.PriorityQueue;

/**
 * java比较器：实现任意两个对象按照自己定义的规则进行排序的功能
 * 两种方式：1.使用Comparable接口,适用于自然排序，该接口定义在类的内部，实现后让该类重写CompareTo方法，
 * 返回规则：如果当前对象this大于形参对象obj，则返回正整数，
 * 如果当前对象this小于形参对象obj，则返回负整数，
 * 如果当前对象this等于形参对象obj，则返回零。
 * 2.使用Comparator接口，该接口适用于定制排序，使用场景主要是当要比较的类不适合进行修改或者要比较的类已经实现了Comparable接口但是它的比较规则不适合当前业务需求的时候。使用方法，采用匿名内部类的写法，Comparator = new Comparator(){},内部重写compare(Object o1,Object o2)方法，比较o1,o2大小。
 * 返回规则：如果方法返回正整数，则表示o1大于o2；
 * 如果返回0，表示相等；
 * 返回负整数，表示o1小于o2。
 * 3.两种方式的比较
 * Comparable接口的方式一旦一定，保证Comparable接口实现类的对象在任何位置都可以比较大小。
 * Comparator接口属于临时性的比较。
 */
public class Comparator {
    public static class Student implements Comparable<Student> {
        public String name;
        public int id;
        public int age;

        public Student(String name, int id, int age) {
            this.name = name;
            this.id = id;
            this.age = age;
        }

        @Override //类本身实现，如果不传外部比较器，则系统默认使用该比较策略
        public int compareTo(Student o) {
            return this.id - o.id;
        }

        @Override
        public String toString() {
            return "Student{" +
                    "name='" + name + '\'' +
                    ", id=" + id +
                    ", age=" + age +
                    '}';
        }
    }


    //按id升序的比较器
    public static class IdAscendingComparator implements java.util.Comparator<Student> {
        @Override
        public int compare(Student o1, Student o2) {
            return o1.id - o2.id;  //返回正数时，表示o1大于o2,所以o2在前面(从小到大)
        }
    }

    //按年龄降序的比较器
    public static class AgeAscendingComparator implements java.util.Comparator<Student>{

        @Override
        public int compare(Student o1, Student o2) {
            return o2.age-o1.age;

        }
    }



    public static void test1() {
        Student student1 = new Student("A", 2, 20);
        Student student2 = new Student("B", 3, 21);
        Student student3 = new Student("C", 1, 22);

        Student[] students = new Student[]{student1, student2, student3};

        System.out.println("排序前: "+Arrays.toString(students));
        Arrays.sort(students,new AgeAscendingComparator());
        System.out.println("排序后: "+Arrays.toString(students));


    }


    public static void test2(){     //比较器与堆结构的联合使用
        PriorityQueue<Student> heap = new PriorityQueue<>(new AgeAscendingComparator());
        heap.add(new Student("A",2,20));
        heap.add(new Student("B",3,21));
        heap.add(new Student("C",1,22));
        while (!heap.isEmpty())
            System.out.println(heap.poll());
    }




    public static void main(String[] args) {
        //test1();
        test2();
    }

}
