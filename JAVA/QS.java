// extensive modularity with quickosort and easy to understand comments

import java.util.Scanner;
import java.util.Arrays;

class QS{

	static void QuickSort(int[] arr,int a, int b)
	   {

		int low=a;
		int high=b;
		int pivot=0;                          // dummy initialization to pivot variable

		if(low>high)
			  {

			return;
			}

		pivot=Partition(arr,low,high);        // find the pivotal location
		QuickSort(arr,low,pivot-1);		 // sort the elements on the right subarray
		QuickSort(arr,pivot+1,high);        // sort the elements on the left subarray
	   }

	static int Partition(int[] arr,int a,int b)
		{
		int low=a;
		int high=b;
		int i=low+1;
		int j=high;
		int pivot=arr[low];   // dummy initialization as we don't know the pivotal position yet. this initialization will be useful later for swapping as it will be used as temporary variable

		while(i<=j)
		{
	
			while ((arr[i]<pivot) && (i<high))     
				i++;

			while(arr[j]>pivot)                    
				j--;

			if(i==j)           // this condition will be satisfied when j is the pivot element
			i++;

			if(i<j){           // this condition will be satisfied when there is an element greater than arr[low] to the left  and an element greater than arr[low] to the right
				int temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
				i++;
					}
													
		 }

//swap the pivot element and jth element

	arr[low]=arr[j];
	arr[j]=pivot;
	return j;     //j is the pivotal position
}



public static void main(String[] args)
	{
		/*Scanner x=new Scanner(System.in);
		System.out.println("enter the number of elements");
		int n=x.nextInt();
		int[] arr=new int[n];

		for(int i=0;i<n;i++)
		{
			System.out.println("enter element "+i);
			arr[i]=x.nextInt();
		}*/
	
		int arr[] = new int[]{10, 9, 4, 7, 11, 16};
		int n=arr.length;


		//System.out.print("original array - ");
		//System.out.println(Arrays.toString(arr));
		//System.out.println(" ");
		QuickSort(arr,0,n-1);
		//System.out.print("Sorted Array - ");
		System.out.println(Arrays.toString(arr));
	}

}
