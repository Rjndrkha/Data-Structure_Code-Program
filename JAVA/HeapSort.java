import java.util.*;
public class HeapSort 
{
    public static void main(String args[])
    {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the size of array : ");
        int n=sc.nextInt();
        int num[]= new int[n];
        System.out.println("Enter the array elements :");
        for (int i =0; i<n; i++)
            num[i]=sc.nextInt();
        System.out.println("The unsorted array is :");
        for (int i =0; i<n; i++)
            System.out.print(num[i]+" ");
        // heap sort algorithm
        for (int i =n/2-1; i>=0; i--)
            heapify(num, n,i);
        for(int i=n-1;i>0;i--)
        {
            //swap root and last element
            int temp= num[0];
            num[0]=num[i];
            num[i]=temp;
            heapify(num, i, 0);
        }
        System.out.println("\nAfter Performing Heap Sort");
        System.out.println("The Sorted array is :");
        for (int i =0; i<n; i++)
            System.out.print(num[i]+" ");
    }
    public static void heapify(int arr[], int n, int i)
    {
        int largest=i;
        int left_child=2*i+1;
        int right_child=2*i+2;
        if (left_child<n && arr[left_child]>arr[largest])
            largest=left_child;
        if (right_child<n && arr[right_child]>arr[largest])
            largest=right_child;
        if (largest!=i)
        {
            //swap parent with the largest node
            int t=arr[largest];
            arr[largest]=arr[i];
            arr[i]=t;
            //recursively heapify the rest
            heapify(arr, n, largest);
        }
        
    }
    
}
