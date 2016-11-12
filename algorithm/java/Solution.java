class Solution{
    public static int strStr(String source, String target){
        int index = -1;
        if( source == null || target == null){
            return -1;
        }
        int j = 0;
        for( int i = 0; i < source.length()- target.length()+1; i++ ){
            for( j = 0; j < target.length(); j++ ){
                if( source.charAt(i+j) != target.charAt(j) ){
                    break;
                }
            }
            if( j == target.length() ){
                index = i;
                break;
            }
        }
        return index;
    }


    public static void main(String[] args){
        String str = "Hello World! I'm xcvzssxvss!";
        System.out.println("index: " + strStr(str, "I'm"));

    }
}
