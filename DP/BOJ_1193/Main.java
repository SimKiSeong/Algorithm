import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int counter = 1;
        int i = 0;
        int before = 0;

        for(; i < x ; counter++){
            before = i;
            i = i+counter;
        }

        counter--;

        if(counter %2==0){
            System.out.println((1+(x-before-1))+"/"+(counter-(x-before-1)));

            return;
        }

        System.out.println((counter-(x-before-1))+"/"+(1+(x-before-1)));
        return;
    }

}
