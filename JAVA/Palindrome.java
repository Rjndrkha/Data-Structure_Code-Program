
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

import java.lang.*;
import java.util.*;
public class Palindrome
    {
        public static void main(String arg[])
        {
            int rev = 0;
            int rem,temp;
            Scanner in = new Scanner(System.in);
            System.out.println("Enter the number");
            int n = in.nextInt();
            temp = n;
            while(n>0)
            {
                rem = n%10;
                rev = rev*10+rem;
                n = n/10;
            }
            if(temp==rev){
                System.out.println("Palindrome Number");
            }
            else{
                System.out.println("Not Palindrome");
            }
        }
    }

