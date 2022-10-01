import java.io.*;
public class ImmediateSmallerThanX {
    public static void main(String args[])
	{
        int arr[]={4,67,13,12,15};
        int n=arr.length;
        int x=16;
        int result=-1;
        for(int i=0;i<n;i++)
            if(arr[i]<x && result<arr[i])
                result=arr[i];
        System.out.println(result+" is immediate smaller than "+x);
    }
}
