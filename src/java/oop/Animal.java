package oop;

public class Animal {
    private String name;
    private int id;

    public Animal(String name, int id) {
        this.name = name;
        this.id = id;
    }
    public void eat() {
        System.out.println(name + " eating");
    }
    public void sleep() {
        System.out.println(name + " is sleeping");
    }
}



