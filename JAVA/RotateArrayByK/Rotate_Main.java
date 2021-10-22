import java.util.*;
public class Rotate_Main
{
	public static void main(String args[])
    {
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter the size of array : ");
		int l= sc.nextInt();
		int a[]=new int[l];
		System.out.println("Enter the array elements");
		for (int i=0; i<l;i++)
		{
			a[i]=sc.nextInt();
		}
                
		System.out.println("Enter the number of places to rotate an array : ");
		int n=sc.nextInt();
		System.out.println("Enter the Initial array is: ");
		for (int i=0; i<l;i++)
		{
			System.out.print(a[i]+" ");
		}
		System.out.println();
                RotateArrayByK ob = new RotateArrayByK();
                ob.rotate(a, n);
		
	}
}