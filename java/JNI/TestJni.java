package test;

public class TestJni {

    // 载入本地库
    static {
        System.out.println(System.getProperty("java.library.path"));
        // 1. 库文件名是　libhello.so，这里要写 hello. 不能带　lib 和　so 后缀
        // 2. 不能带路径，路径通过在运行的时候，-D 参数指定。如
        // java -Djava.library.path=. test.TestJni
        System.loadLibrary("hello");
    }
    // 所有使用native关键字修饰的都是对本地方法的声明。
    public native int displayHelloWorld();


    
    public static void main(String[] args) {
	    new TestJni().displayHelloWorld();
    }
}
