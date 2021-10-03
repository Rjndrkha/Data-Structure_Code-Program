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