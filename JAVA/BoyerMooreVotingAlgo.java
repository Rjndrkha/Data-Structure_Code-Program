//Ques. Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.


// Basic idea is to use Boyer Moore Voting Algo
// there can be atmost 2 elements in the array which can become maximum element because
// 3*(n/3) = n it is possible that only 3 elements can occir exactly n/3 times in the array
// if any element is appearing more than n/3 times atmost 2 elements can be the maximun element...

// now we will maintain two variables num1 , num 2 to store the value of frequently appearing elements using extended boyer moore algo

				class BoyerMooreVotingAlgo {
          
          public static void main(String[] args) {
            int[] arr = {1,2,3,3,3,4,4,5,4,3};
            System.out.println(majorityElement(arr).toString());
          }
          
					public List<Integer> majorityElement(int[] nums) {
					   List<Integer> list = new ArrayList<>();
						 if(nums == null) return list;
						int num1=0;
						int num2=0;
						int count1=0;
						int count2=0;
						for(int i=0;i<nums.length;i++){
							int num3 = nums[i];
							if(count1>0 && count2>0){

								if(num3 == num1){
									count1++;
								}else if(num3 ==num2){
									count2++;
								}else{
									count1--;
									count2--;
								}

							}else if(count1 >0){

								if(num3 == num1){
									count1++;
								}else{
									num2 = num3;
									count2++;
								}

							}else if(count2>0){

								if(num3 == num2){
									count2++;
								}else{
									num1 = num3;
									count1++;
								}

							}else{
								num1 = num3;
								count1++;
							}
						}

				//         now we have the values that appears frequently in the array but it doesnot means that they both are maximum elements .........
				//         so we have to iterate again over the array to cehck for maximum element out of both .......

						count1=0;
						count2=0;

						for(int i=0;i<nums.length;i++){
							if(nums[i] == num1){
								count1++;
							}
							else if(nums[i] ==num2){
								count2++;
							}
						}
						if(count1>nums.length/3){
							list.add(num1);
						}
						if(count2>nums.length/3){
							list.add(num2);
						}

						return list;
					}
				} 
