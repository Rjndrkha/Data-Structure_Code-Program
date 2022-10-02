/**
 * @param {string} s
 * @return {string}
 */
 var frequencySort = function(s) {
    
    //Create a map that will contain with keys of characters in the string  and the number of time it occurs;
    //E.g {'a':5}
      
    let map = {}
    
    //Iterate through the string and for each character compute the number of time it occurs
    for(let i =0;i<s.length;i++){
        
        //If the element exist increment the occurrece by one
        if(map[s[i]]){
            map[s[[i]]]++
        }else{
            // Create it with one ocurrence
            map[s[i]] = 1
        }
     }
     // Create another two dimension array which has an array with the characters of the string 
     // and the number of time it occurs in the string  e.g ['a','4'] etc
      
     let object = Object.entries(map)
  
     //Create another map of each number of character ocurrences with the array of its characters  
      // e,g {'1':[a','b'],'2':['e','f']}
     
     let secondMap = {}
     
     //Iterate through the number of occurence of characters
     for(let i = 0;i<object.length;i++){
         //If the character number occurence exist
        if(secondMap[object[i][1]] ){
            // add the new character to the number of occurence
          secondMap[object[i][1]] = [...secondMap[object[i][1]],object[i][0]]
        }else{
            //Create new array array with the character occurence as the first element
         secondMap[object[i][1]] = [object[i][0]]
        }
     } 
     //Create an array of the number of character occurences;
     let keys = Object.keys(secondMap)
   
     //Create the final String 
     let str = ''
     //Iterate through the number of characters occurences from the highest number;
     for(let i = keys.length-1;i>=0;i--){
         //Iterate through the alphabets for a ocurrence
         for( let j = 0;j<secondMap[keys[i]].length;j++){
            // multiply a character with the number of time it occurs and increment it to the string
           str+= secondMap[keys[i]][j].repeat(parseInt(keys[i]))
         }
     } 
     return str
  };