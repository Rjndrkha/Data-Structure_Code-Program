//Input nums is an array with sorted element in ascending order
var removeDuplicates = function(nums) {
    //Last unique value is at nums[0]
    //Declaring the index of next unique value nums[1]
    let index = 1;
    //Iterating through nums array
     for(let i=1;i<nums.length;i++){
        //check if the last unique value is not the same with nums[i]
         if(nums[index-1]!= nums[i]){
            // if they are not next unique value is nums[i]
            nums[index] = nums[i];
            //increment index of next unique value
            index++
         }
     }
     //return the total iterations
     return index
 };