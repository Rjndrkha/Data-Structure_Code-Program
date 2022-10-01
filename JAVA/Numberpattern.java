//Code by ShreyaDayma-cse
import java.util.*;
public class pattern {
    void make_pattern(int n){
        int c=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                System.out.print(c+" ");
            }
            c++;
            System.out.println();
        }
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of rows in the pattern:");
        int n=sc.nextInt();
        pattern ob=new pattern();
        ob.make_pattern(n);
    }
}
