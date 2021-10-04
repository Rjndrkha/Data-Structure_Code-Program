package LinearSearch;
import java.util.Arrays;


public class MinMaxIn2D {
    public static void main(String[] args){
        int arr[][]={
            {2,85,81,94},
            {8,18,-1,82,},
            {76,9},
            {928,88},
            {5}
        };
        System.out.println("Minimum is: "+ mini(arr));
        System.out.println("Maximum is : "+ maxi(arr));
    }
    static int mini(int[][] arr){
        int min=arr[0][0];
        for(int row=0;row<arr.length;row++){
            for(int col=0;col<arr[row].length;col++){
                if(arr[row][col]<min)
                min=arr[row][col];
            }
        }
        return min;
    }
    static int maxi(int[][] arr){
        int max=Integer.MIN_VALUE;
        for(int[] intr:arr){
            for(int element: intr){
                if(element > max)
                max=element;
            }
        }
        return max;
    }
    
}
