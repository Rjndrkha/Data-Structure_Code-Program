// Function that takes an array of integers and integer value
var removeElement = function(nums, val) {
    //Declare the pointer
    let pointer = 0;
    
    for(let i =0;i<nums.length;i++){
        //If item is not the same as the element to remove
        if(nums[i] != val){
            //Update pointer value to the item
            nums[pointer] = nums[i]
            //Increment the pointer for next index check
            pointer++
            
        }
    }
    return pointer
};
