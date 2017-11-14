package io;

import java.io.*;

/*
 * @author skyie
 * @date 2017/10/22
 * 写文件示例
 */
public class FileWriter {
    /*
        这个接口的问题：二进制写入打开后可能是乱码
     */
    public static void writeByByte(String path) throws IOException{
        OutputStream os = null;
        try {
            byte bWrite[] = {1,2,3,4};
            os = new FileOutputStream(path);
            for (int i = 0;i < bWrite.length;i++) {
                os.write(bWrite[i]);
            }
        } catch(IOException e) {
            System.out.println("write Exception");
        }
        finally {
            if (os != null) {
                os.close();
            }
        }
    }
    /*
        指定字符集写入，可以避免乱码
     */
    public static void writeByCharactor(String path) throws IOException{
        File f = new File(path);
        FileOutputStream os = new FileOutputStream(f);
        OutputStreamWriter writer = new OutputStreamWriter(os, "UTF-8");
        writer.append("这是中文");
        writer.append("\r\n");
        writer.append("this is english");
        writer.close();
        os.close();

    }

    public static void main(String[] args) throws IOException{
        String file = "./test.txt";
//        writeByByte(file);
        writeByCharactor(file);
    }


}
