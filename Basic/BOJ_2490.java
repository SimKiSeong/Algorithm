import java.util.*;

public class Main {

    public static String[] result = new String[]{"A","B","C","D","E"};

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int t = 0;
        t = scanner.nextInt();

        for(int z = 0; z<t;z++){
            int h,w,n;
            h = scanner.nextInt();
            w = scanner.nextInt();
            n = scanner.nextInt();

            if(n%h==0){
                System.out.print(h);

                if(n/h<10){
                    System.out.print("0");
                }
                System.out.println(n/h);

            }else {
                System.out.print(n % h);
                if(n/h<9){
                    System.out.print("0");
                }
                System.out.println(n/h+1);
            }


        }
    }

}
