package serialize;


import java.io.*;

class Employ {
    private String name;
    private String email;
    private int age;
    public Employ(String name, String email, int age) {
        this.name = name;
        this.email = email;
        this.age = age;
    }

    public String getName() {
        return this.name;
    }
    public String getEmail() {
        return this.email;
    }
    public int getAge() {
        return this.age;
    }
}

class Serialize {
    public static void serialize(String filename) {
        Employ employ = new Employ("jack", "jack@163.com", 28);
        try {
            FileOutputStream fileOutput = new FileOutputStream(filename);
            ObjectOutputStream out = new ObjectOutputStream(fileOutput);
            out.writeObject(employ);
            out.close();
            fileOutput.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Serialize to " + filename + " success");
    }
}

class Deserialize {
    public static void deserialize(String filename) {
        Employ employ = null;
        try {
            FileInputStream fileInput = new FileInputStream(filename);
            ObjectInputStream in = new ObjectInputStream(fileInput);
            employ = (Employ)in.readObject();
        } catch (IOException e) {
            e.printStackTrace();
            return;
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
            return;
        }
        System.out.println("deserialize from " + filename + " success");
        System.out.println("employ name :" + employ.getName());
        System.out.println("employ email:" + employ.getEmail());
        System.out.println("employ age:" + employ.getAge());
    }
}

public class SerializeTest {
    public static void main(String args[]) {
        Serialize.serialize("./test");
        Deserialize.deserialize("./test");
    }
}
