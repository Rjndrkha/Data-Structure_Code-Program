import java.util.*;
import java.io.*;
import java.lang.*;
class GFG 
{ 
    

    static int maxCircularSum(int arr[], int n)
    {
    	int curr_min=arr[0];
    	int min=arr[0];//This functions helps in finding minimum subarray which is needed to find the max circular subarray after we subtract minimum subarray which we found from sum of all array
    	for(int i=1;i<n;i++){
    	    curr_min=Math.min(curr_min+arr[i],arr[i]);
    	    min=Math.min(min,curr_min);
    	}
    	int sum=0;
    	for(int i=0;i<n;i++){
    	    sum+=arr[i];
    	}
    	int circ_ans=sum-min;//here we find the circular subarray ans after subtracting minimum subarray which we got from above function
    	int curr_max=arr[0];
    	int max=arr[0];
    	for(int i=1;i<n;i++){
    	    curr_max=Math.max(curr_max+arr[i],arr[i]);//This function is normal function to find max subarray
    	    max=Math.max(curr_max,max);
    	}
    	if(max<0){
    	    return max;//this function helps if all values are negative then only maximum subarray ans is required
    	}
    	
    	
    	return(Math.max(max,circ_ans));
    }
    


    public static void main(String args[]) 
    { 
       int arr[] = {3,-4,5,6,-8,7}, n = 6;

       System.out.println(maxCircularSum(arr, n));

    } 

}
