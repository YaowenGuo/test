import java.io.IOException;
import java.io.FileWriter;

public class FileWriterDemo{

    public static void main(String[] args) throws IOException {
        FileWriter fw = new FileWriter("demo.txt");
        //调用writer的write方法写入数据
        //其实数据写入到了临时缓冲区中
        fw.write("abcddfasf");
        fw.flush();//进行刷新，将数据写入
    }
}

