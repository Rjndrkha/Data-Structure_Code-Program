import java.util.*;
public class CoinFlips {
	public static void main (String[] args) {
	    Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-- > 0){
		    int g=sc.nextInt();
		    while(g-- > 0)
		    {
		        int ans[]=new int[3];
		        Arrays.fill(ans,0);
		        int i=sc.nextInt();
		        int n=sc.nextInt();
		        int q=sc.nextInt();
		        if(n%2==0) System.out.println(n/2);
		        else if(n==1)
		        {
		            if(i==1) ans[2]=1;
		           else if(i==2) ans[1]=1;
		           System.out.println(ans[q]);
		        }
		        else
		        {
		            if(i==1) {ans[1]=n/2;ans[2]=(n/2)+1;}
		            else if(i==2) {ans[1]=(n/2)+1;ans[2]=n/2;}
		            System.out.println(ans[q]);
		        }
		        
		    }
		}
	}
}