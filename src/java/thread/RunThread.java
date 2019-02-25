package thread;


//第一种方法，实现Runnable接口
class RunneableTest implements Runnable {
    private Thread t;
    private String threadName;

    public RunneableTest(String name) {
        this.threadName = name;
    }

    public void run() {
        int i;
        try {
            for (i = 0; i < 3; i++) {
                System.out.println(" sleep " + i);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println("thread " + threadName + "interrupted");
        }
    }

    public void start() {
        System.out.println("start thread " + threadName);
        if (t == null) {
            t = new Thread(this, threadName);
            t.start();
        }
    }
}


//第二种方法，继承Thread
class ThreadTest extends Thread {
    private Thread t;
    private String threadName;
    public ThreadTest(String name) {
        threadName = name;
    }

    public void run() {
        int i;
        try {
            for (i = 0; i< 3;i++) {
               System.out.println("sleep " + i);
               Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println("thread " + threadName + "interrupted");
        }

    }

    public void start() {
        System.out.println("start thread " + threadName);
        if (t == null) {
            t = new Thread(this, threadName);
            t.start();
        }
    }
}

public class RunThread {
    public static void main(String args[]) {
        //RunneableTest runner = new RunneableTest("newThread");
        //runner.start();

        ThreadTest runner = new ThreadTest("newThread");
        runner.start();
    }
}
