/*

	Problem: Given a sorted array of integers and a target, find if there’s a pair of elements that add up to the target.
	
*/

import java.util.*;

class TwoSumInSortedArray {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int arr[] = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int k = sc.nextInt();

        boolean res = twoSumInSortedArray(n, arr, k);

        String ans = (res) ? "Present" : "Not Present";

        System.out.println(ans);

    }

    static boolean twoSumInSortedArray(int n, int arr[], int k) {

        Set<Integer> hash = new HashSet<>();

        for(int i=0;i<n;i++) {

            if(hash.contains((k-arr[i]))) {

                return true;
            }
            hash.add(arr[i]);

        }
        return false;
    }
}