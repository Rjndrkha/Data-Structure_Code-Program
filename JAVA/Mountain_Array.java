//Problem - 852. Peak Index in a Mountain Array (LEETCODE)
//Link -- https://leetcode.com/problems/peak-index-in-a-mountain-array/

public class Mountain_Array {
    public static void main(String[] args) {
        int[] arr={0,10,5,2};
        System.out.println(peakIndexInMountainArray(arr));
    }
    private static int peakIndexInMountainArray(int[] arr) {
        int start=0,end=arr.length-1;
        while(start<end) {
            int mid=start+(end-start)/2;
            if(arr[mid]<arr[mid+1])
                start=mid+1;
            else
                end=mid;
        }
        return start;
    }
}
