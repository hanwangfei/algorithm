package test;

public class Test {
    public static void change(Student student) {
        student.age = 0;
        student = new Student("小灰", 20);

    }

    public static void change(Integer num) {
        num = 0;
    }

    public static void main(String[] args) {
        Student stu1 = new Student("小明", 18);
        change(stu1);
        System.out.println(stu1);
//        Integer a = 10;
//        change(10);
//        System.out.println(a);

    }
}
