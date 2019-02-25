package oop;

public class Cat extends Animal {
    public Cat(String name, int id) {
        super(name, id);
    }
    // 重写父类的方法
    /* 重写的原则：
        1.final和static的方法不能重写；
        2.没有继承的方法不能重写，例如声明为private的
        3.构造函数不能重写

    */

    public void eat() {
        System.out.println("I'm a cat.");
        super.eat();
    }

    /*
    * 重载：
    * 参数列表必须修改，返回类型和扔出异常和访问修饰符可以改或不改
    *
    *
    */
    public void sleep(String reason) {
        System.out.println("sleep for " + reason);
    }

    // 子类自己定义的方法
    public void play() {
        System.out.println("playing");
    }
}