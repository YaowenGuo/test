import java.util.Date;

public class Test extends Date{
    public static void main(String[] atgs){
        String s1 = "a";
        String s2 = s1 + "b";
        String s3 = "a" + "b";
        System.out.println(s3 == "ab");
    }

    public void test(){
        System.out.println(super.getClass().getName());
    }
}
