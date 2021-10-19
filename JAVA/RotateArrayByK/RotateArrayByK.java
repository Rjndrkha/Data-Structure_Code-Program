//Given an array, rotate the array to the right by k steps, where k is non-negative.
//Sample Input: nums = [1,2,3,4,5,6,7], k = 3
//Sample Output: [5,6,7,1,2,3,4]
public class RotateArrayByK
{
  public void rotate(int[] nums, int k) 
  {
     
        int n= nums.length-1;
        k=k%nums.length;
        reverse(nums, 0, n);
        reverse(nums, 0 , k-1);
        reverse(nums, k, n);
	System.out.println("The final array rotated by k steps is : ");
	for (int i=0; i<nums.length;i++)
	{
            System.out.print(nums[i]+" ");
	}
  }
    public void reverse(int arr[], int s, int l)
    {
        while(s<l)
        {
            int a = arr[s];
            arr[s]=arr[l];
            arr[l]=a;
            s++;
            l--;
        }
    }
}