import java.util.*;
public class WaveSort {
    public static void main(String args[]) {
      Scanner scn=new Scanner(System.in);
      int n=scn.nextInt();
      int []a=new int[n];
      for(int i=0;i<n;i++)
      a[i]=scn.nextInt();
      for(int i=0;i<n;i+=2)
      {
        if(i>0 && a[i-1]>a[i])
        {
          int t=a[i];
          a[i]=a[i-1];
          a[i-1]=t;
        }
        if(i<=n-2 && a[i+1]>a[i])
        {
          int t=a[i];
          a[i]=a[i+1];
          a[i+1]=a[i];
        }
      }
      for(int i=0;i<n;i++)
      System.out.print(a[i]+" ");
    }
}
