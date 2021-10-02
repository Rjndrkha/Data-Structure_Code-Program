import java.util.Scanner;

public class StarNestedFor {

    public static void main(String[] args) {
        int i, z, N;
        System.out.println("Input the Value of N :");
        Scanner input = new Scanner(System.in);
        N = input.nextInt();
        for (i = 1; i <= N; i++) {
            for (z = 1; z <= i; z++) {
                System.out.print(" ");
            }
            for (z = N; z >= i; z--) {
                System.out.print("*");
            }
            for (z = N; z > i; z--) {
                System.out.print("*");
            }
            System.out.println();
        }
        for (i = 2; i <= N; i++) {
            for (z = N; z >= i; z--) {
                System.out.print(" ");
            }
            for (z = 1; z <= i; z++) {
                System.out.print("*");
            }
            for (z = 1; z < i; z++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
