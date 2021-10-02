
class CountingSort {
	void sort(char arr[])
	{
		int n = arr.length;

	
		char output[] = new char[n];

		int count[] = new int[256];
		for (int i = 0; i < 256; ++i)
			count[i] = 0;

	
		for (int i = 0; i < n; ++i)
			++count[arr[i]];

		for (int i = 1; i <= 255; ++i)
			count[i] += count[i - 1];


		for (int i = n - 1; i >= 0; i--) {
			output[count[arr[i]] - 1] = arr[i];
			--count[arr[i]];
		}

		for (int i = 0; i < n; ++i)
			arr[i] = output[i];
	}

	public static void main(String args[])
	{
		CountingSort ob = new CountingSort();
		char arr[] = { 'D','E','M','O','I','C','N'};

		ob.sort(arr);

		System.out.print("Sorted character array is ");
		for (int i = 0; i < arr.length; ++i)
			System.out.print(arr[i]);
	}
}

