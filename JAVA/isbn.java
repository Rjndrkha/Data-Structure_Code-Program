import java.util.*;
class isbn
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        long n,m,i=1,sum=0,d;
        System.out.println("Enter a number");
        n=sc.nextLong();
        m=n;
        while(m>0)
        {
            d=m%10;
            sum=sum+d*i;
            i++;
            m/=10;
        }
        System.out.println(sum);
        if(sum%11==0)
        System.out.println("ISBN number");
        else
        System.out.println("Not an ISBN number");
    }
}