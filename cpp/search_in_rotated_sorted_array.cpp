class Solution {
public:
    int search(vector<int>& nums, int target) {
            
           int n=nums.size();
        int start=0;
        int end=n-1;
        int mid;
        while(start<=end){
            mid=(start+end)>>1;
            
            // when target is found
            if(nums[mid]==target){
                return mid;
            }
            
            // if left part is montonically increasing
            else if(nums[start]<=nums[mid]){
                // if target lies in the sorted part 
                if(target>=nums[start] && target<=nums[mid]){
                    end=mid;
                }
                else{
                    start=mid+1;
                }
            }
             // if right part is montonically increasing
             else if(nums[mid]<=nums[end]){
                  // if target lies in the sorted part 
                if(target>=nums[mid] && target<=nums[end]){
                    start=mid;
                }
                else{
                    end=mid-1;
                }
            }
        }
        // if target is not present then return -1
        return -1;
        
    }
};