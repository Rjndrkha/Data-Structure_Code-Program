import java.util.Scanner;

public class Prime {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        try {
            System.out.print("Enter number : ");
            int num = in.nextInt();

            for (int i = 2; i < Math.sqrt(num); i++) {
                if (num % i == 0) {
                    System.out.println(num + " is not Prime.");
                    System.exit(0);
                }
            }
            System.out.println(num + " is Prime.");
        } finally {
            in.close();
        }
    }
}
