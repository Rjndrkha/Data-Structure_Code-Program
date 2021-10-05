class Solution {
    public int findMin(int[] nums) {
        
        
        int low = 0;
        int high = nums.length-1;
        int mid =0;
    
       /* if(nums.length==1)
            return nums[0];*/
        
        while(low<high)
        {
            
            mid = low+(high-low)/2;
           
            if(nums[mid]==nums[high])
                high--;
            else if(nums[mid]>nums[high])
                low = mid+1;
            else
                high = mid;
           
            }
            
             return nums[high];

        }
        

}
