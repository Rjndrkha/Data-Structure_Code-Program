import java.io.*;
public class ClockwiseArrayRotation {
    public static void main(String args[])
	{
        int arr[]={1,2,3,4,5};
        int n=arr.length;
        int numOfRotation=2;
        int rotate[]=new int[n];
        for(int i=0;i<n;i++)
            rotate[i]=arr[i];
        for(int i=0;i<n;i++)
            arr[i]=rotate[(int)(i+n+numOfRotation)%n];
        for(int i=0;i<n;i++)
            System.out.print(arr[i]+"\t");
    }
}
