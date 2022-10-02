// merge sort code with modularity and good variable naming. easy to understand and very fast to implement


import java.util.Scanner;
import java.util.Arrays;
class MergeSort{

static void MS(int[] arr,int a,int b)
{
	int low=a;
	int high=b;
	if(low<high)
	{
		int mid=(low+high)/2;
		MergeSort(arr,low,mid);
		MergeSort(arr,mid+1,high);
		Merge(arr,low,high,mid);               //  low==high means that the subarray has a single element, so we don't write the case seperately and return the element as it is
	}
}

static void Merge(int[] arr,int a,int b,int c){
	int low=a;
	int high=b;
	int mid=c;
	int i=low;                            // i is used for indexing the left subarray.
	int h=0;                             // h literal is used for indexing the temporary array.
	int j=mid+1;                        // j is used for indexing the right subarray.
	int temp[]=new int[high-low+1];    

	while((i<=mid) && (j<=high))            //merge the sorted subarrays into temporary array
	{
		if (arr[i]<=arr[j])	
		{
			temp[h++]=arr[i++];
		}
		else
		{
			temp[h++]=arr[j++];
		}
	}

	for(int k=j;k<=high;k++)	//copy the remaining elements of left subarray into the temporary array
	{
		temp[h++]=arr[k];
	}

	for(int k=i;k<=mid;k++)	       // copy the remaining elements of right subarray into the temporary array
	{
		temp[h++]=arr[k];
	}
}

	
  //update the original array with the values of the temporary array

	int k=low;                     
	for(int l=0;l<high-low+1;l++)
	{
		arr[k++]=temp[l];}

	}


public static void main(String[] args){
	/*Scanner x=new Scanner(System.in);
	System.out.println("enter the number of elements");
	int n=x.nextInt();
	int arr[]=new int[n];
	
	for(int i=0;i<n;i++)
	{
		System.out.println("enter element "+i);
		arr[i]=x.nextInt();
	}*/
	
	int [] arr = new int[] {12,11,13,5,6,7};
	int n=arr.length;

	System.out.println("before Sorting");
	System.out.println(Arrays.toString(arr));

	MergeSort(arr,0,n-1);
	System.out.println("after Sorting");
	System.out.println(Arrays.toString(arr));

	}
}
