import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int sum = 0;
        Scanner s = new Scanner(System.in);
        System.out.println("Enter a number : ");
        int i = s.nextInt();
        System.out.println("Factors of " + i + " are :");
        for(int j = 1; j < i; j++){

            if (i%j == 0){
                System.out.println(j + "");
                sum = sum + j;
            }

        }
        System.out.println("Sum of factors of " + i + " are :" + sum);
        if(i == sum){
            System.out.println(i +" is a perfect number");
        }
        else{
            System.out.println(i +" is not a perfect number");
        }
    }
}