//Code by ShreyaDayma-cse
import java.util.*;
public class palindrome {
    int check(int n){
        int p=1;
        int s=0;
        while(n!=0){
            int d=n%10;
            s=s*10+d;
            n=n/10;
        }
        return s;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number:");
        int n=sc.nextInt();
        palindrome ob=new palindrome();
        int a=ob.check(n);
        if(n==a)
            System.out.println("Palindrome");
        else
            System.out.println("Not Palindrome");
    }
}
