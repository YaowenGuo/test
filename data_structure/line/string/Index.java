
public class Index {
    public int index(String src, String tag, int start) {
        if (src == null || tag == null) return -1;
        
        int i = start, j = 0;
        while(i < src.length() && j < tag.length()) {
            if (src.charAt(i) == tag.charAt(j)) {
                i += 1;
                j += 1;
            } else {
                i = i - j + 1;
                j = 0;
            }
        }
            
        if (i >= src.length()) {
            return -1;
        } else {
            return i - j;
        }
    }

    public static void main(String[] args) {
        String a = "12345324234234";
        String b = "532";
        Index search = new Index();
        System.out.println(search.index(a, b, 0));
    }

}
