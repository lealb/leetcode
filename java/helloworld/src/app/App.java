package app;

public class App {

    public static void testNull(String str) {
        if (str!=null) {
            System.out.println(str);
        }

    }
    public static void main(String[] args) throws Exception {
      
        System.out.println("Hello Leal");
        // 
        testNull(null);
    }
}