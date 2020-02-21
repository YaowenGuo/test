package tech.yaowen.kotlin;

import java.io.*;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.nio.charset.Charset;

public class FileTest {

    public static void main(String[] args) {

        try (FileWriter outputStream = new FileWriter("./test.txt")){
            BufferedWriter bufferedOutputStream = new BufferedWriter(outputStream);
            bufferedOutputStream.write("sdsd");
            bufferedOutputStream.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

        try (FileChannel fc = new FileOutputStream("./test.txt").getChannel()) {
            fc.write(ByteBuffer.wrap("Some test".getBytes()));

        } catch (Exception e) {
            e.printStackTrace();
        }

        try (FileChannel fc = new FileInputStream("./test.txt").getChannel()) {
            ByteBuffer buffer =  ByteBuffer.allocate(1024);
            fc.read(buffer);
            buffer.flip();
            System.out.println(Charset.defaultCharset().decode(buffer));

        } catch (Exception e) {
            e.printStackTrace();
        }


        try (ServerSocketChannel sc = ServerSocketChannel.open()) {
            sc.bind(new InetSocketAddress(8080));
            sc.configureBlocking(false); // 设置非阻塞
            SocketChannel socketChannel = sc.accept();
            ByteBuffer buffer =  ByteBuffer.allocate(1024);
            while (true) {
                if (socketChannel == null) continue; // 由于是非阻塞的，当 sc.accept() 没有接受到内容时，返回 null
                if (socketChannel.read(buffer) == -1) break;
                buffer.flip();
                socketChannel.write(buffer);
                buffer.clear();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
