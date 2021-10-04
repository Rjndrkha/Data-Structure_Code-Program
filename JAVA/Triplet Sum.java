public class Solution {  

    public static int findTriplet(int arr[], int x) {
    	int sum=0,temp=0,count=0;
        for(int i=0;i<arr.length;i++)
        { temp=arr[i];
		   for(int j=i+1;j<arr.length;j++)
           { 
               for(int k=j+1;k<arr.length;k++)
               {
               if(temp+arr[j]+arr[k]==x)
               {
                   count ++;
               }
           }
        }
    }
    return count;
    }
}
