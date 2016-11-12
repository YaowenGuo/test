import java.util.Scanner;

public class Main{
    public static void main( String[] args ){
        Scanner scanner = new Scanner(System.in);
        String str;
        //String[] strArr  = new String;
        while(scanner.hasNext()){
            str = scanner.nextLine();
            /*if(str != null && !str.equals("")){
                strArr = str.split(" ");
            }
            str = "";
            for( int i = 0; i < strArr.length; i++ ){
                if( i != 0 ){
                    str += " " + strArr[i];
                }
            }*/
            String reverseStr = new StringBuilder(str).split(" ").reverse().toString();
            System.out.println(reverseStr);

        }
    }
}
