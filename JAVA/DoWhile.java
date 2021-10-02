import java.util.Scanner;  // Import the Scanner class
public class PracDoWhile {
     public static void main(String[] args){
        int number,fac,i;
        System.out.println("=====Program Calculate Factorial Values With for======");
//         System.out.println("Enter Number :");
        System.out.print("Enter Number :");
        Scanner input = new Scanner(System.in);
        number = input.nextInt();
        fac = 1;
        i = 1;
        do{
            fac = fac * i;
            i++;
        }
        while(i<=number);
        System.out.printf("Factorial value of that Number is : %d \n",fac);
    }
}
