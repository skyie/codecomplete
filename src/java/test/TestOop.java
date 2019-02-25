package test;

import oop.Animal;
import oop.Cat;

public class TestOop {
    public static void main(String args[]) {
        Animal cat = new Cat("Tom", 1);
        cat.eat();
        //cat.sleep("late");
    }
}
