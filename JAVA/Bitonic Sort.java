
public class BitonicSort
{

	void compAndSwap(int a[], int i, int j, int dir)
	{
		if ( (a[i] > a[j] && dir == 1) ||
			(a[i] < a[j] && dir == 0))
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}


	void bitonicMerge(int a[], int low, int cnt, int dir)
	{
		if (cnt>1)
		{
			int k = cnt/2;
			for (int i=low; i<low+k; i++)
				compAndSwap(a,i, i+k, dir);
			bitonicMerge(a,low, k, dir);
			bitonicMerge(a,low+k, k, dir);
		}
	}

	void bitonicSort(int a[], int low, int cnt, int dir)
	{
		if (cnt>1)
		{
			int k = cnt/2;


			bitonicSort(a, low, k, 1);

		
			bitonicSort(a,low+k, k, 0);

			bitonicMerge(a, low, cnt, dir);
		}
	}

	void sort(int a[], int N, int up)
	{
		bitonicSort(a, 0, N, up);
	}

	static void printArray(int arr[])
	{
		int n = arr.length;
		for (int i=0; i<n; ++i)
			System.out.print(arr[i] + " ");
		System.out.println();
	}


	public static void main(String args[])
	{
		int a[] = {3, 7, 4, 8, 6, 2, 1, 5};
		int up = 1;
		BitonicSort ob = new BitonicSort();
		ob.sort(a, a.length,up);
		System.out.println("\nSorted array");
		printArray(a);
	}
}
