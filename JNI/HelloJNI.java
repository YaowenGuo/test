package hellojni;

public class HelloJNI {
    public static void main(String[] args) {
	new HelloJNI().displayHelloWorld();
    }

    // 载入本地库
    static {
        System.out.println(System.getProperty("java.library.path"));
        System.loadLibrary("/Users/yaowen/test/JNI/libtest.so");
    }
    // 所有使用native关键字修饰的都是对本地方法的声明。
    public native int displayHelloWorld();
}
