class Solution {
    public int[] searchRange(int[] nums, int target) {
        
        int[] ans = new int[2];
        int mid=0;
        int low = 0;
        int high = nums.length-1;
        int f1 =-1;
        int l1 = -1;
         
        
        while(low<=high)
        {
            mid = low+(high-low)/2;
            
            if(nums[mid]>target)
                high=mid-1;
            else if(nums[mid]<target)
                low= mid+1;
            else
            {
                f1 = mid;
                high=mid-1;
            }
                
        }
        
        low = 0;
        high = nums.length-1;
        
         while(low<=high)
        {
            mid = low+(high-low)/2;
            
            if(nums[mid]>target)
                high=mid-1;
            else if(nums[mid]<target)
                low= mid+1;
            else
            {
                l1 = mid;
                low =mid+1;
            }
                
        }
         ans[0]=f1;
         ans[1]=l1;
        return ans;
        
    }
}
