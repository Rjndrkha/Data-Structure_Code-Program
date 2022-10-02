public class Median_of_2SortedArrays {

	public static void main(String[] args) {
        int[] arr1 = { 2, 2, 2 };
        int[] arr2 = { 1, 5 };
        System.out.println("Median = " + findMedian(arr1, arr2));
    }

    public static double findMedian(int[] arr1, int[] arr2) {
        int m = arr1.length;
        int n = arr2.length;
        if (m > n)
            return findMedian(arr2, arr1); // Swapping to make A smaller
 
        int start = 0;
        int end = m;
        int realmidinmergedarray = (m + n + 1) / 2;
 
        while (start <= end) {
            int mid = (start + end) / 2;
            int leftAsize = mid;
            int leftBsize = realmidinmergedarray - mid;
            int leftA = (leftAsize > 0) ? arr1[leftAsize - 1] : Integer.MIN_VALUE;
            int leftB = (leftBsize > 0) ? arr2[leftBsize - 1] : Integer.MIN_VALUE;
            int rightA = (leftAsize < n) ? arr1[leftAsize] : Integer.MAX_VALUE;
            int rightB = (leftBsize < m) ? arr2[leftBsize] : Integer.MAX_VALUE;
 
            if (leftA <= rightB && leftB <= rightA) {
                if ((m + n) % 2 == 0)
                    return (Math.max(leftA, leftB) + Math.min(rightA, rightB)) / 2.0;
                return Math.max(leftA, leftB);
            }
        	else if (leftA > rightB) {
                end = mid - 1;
            }
            else
                start = mid + 1;
        }

        return 0.0;
    }

}
