import java.util.*;

public class Kadanes_Algorithm {

    static int MaxSubSumArray(int arr[]) {
        int currSum = 0;
        int MaxSum = 0;

        for (int i = 0; i < arr.length; i++) {
            currSum += arr[i];
            if (currSum > MaxSum) {
                MaxSum = currSum;
            }

            if (currSum < 0) {
                currSum = 0;
            }

        }
        return MaxSum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
          arr[i] = sc.nextInt();
        }
      
        int max = MaxSubSumArray(arr);
        System.out.println("Largest Sum : " + max);
    }
}
