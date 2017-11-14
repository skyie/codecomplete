package io;

import java.io.*;
import java.util.ArrayList;

/*
 * 测试目录API的示例
 */
public class DirectoryOp {

    public static void createDir(String dirname) {
        File dir = new File(dirname);
        /*
        mkdir( )方法创建一个文件夹，成功则返回true，失败则返回false。
        失败表明File对象指定的路径已经存在，或者由于整个路径还不存在，该文件夹不能被创建
        mkdirs()方法创建一个文件夹和它的所有父文件夹
         */
        dir.mkdirs();
        System.out.println("create dir...");
    }
    public static ArrayList<String> getDirs(String dirname) {
        File f1 = new File(dirname);
        ArrayList<String> dirs = new ArrayList<>();
        if (f1.isDirectory()) {
            System.out.println( "目录 " + dirname);
            String s[] = f1.list();
            for (int i=0; i < s.length; i++) {
                File f = new File(dirname + "/" + s[i]);
                if (f.isDirectory()) {
                    dirs.add(s[i]);
                    System.out.println(s[i] + " 是一个目录");
                } else {
                    System.out.println(s[i] + " 是一个文件");
                }
            }
        } else {
            System.out.println(dirname + " 不是一个目录");
        }
        return dirs;
    }
    public static void deleteDir(String dirname) {

    }
    public static void main(String[] args) {
        String targetDirname = "./testDir";
        createDir(targetDirname);
        getDirs(targetDirname);
//        deleteDir(targetDirname);
    }
}
