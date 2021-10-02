import java.util.Scanner;

public class Fibonacci {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            System.out.print("Enter range : ");
            int range = sc.nextInt();

            int num1 = 0, num2 = 1, temp;
            for (int i = 0; i < range; i++) {
                System.out.print(num1 + " ");
                temp = num1 + num2;
                num1 = num2;
                num2 = temp;
            }

            System.out.println();
        } finally {
            sc.close();
        }
    }
}