// javascript function to merge two arrays
const mergeTwoLists = function (arr1, arr2) {
  var newArray = [];
  if (arr1) {
    for (let i = 0; i < arr1.length; i++) {
      newArray.push(arr1[i]);
    }
  }
  if (arr2) {
    for (let j = 0; j < arr2.length; j++) {
      newArray.push(arr2[j]);
    }
  }
  if (newArray.length > 1) {
    for (let k = 0; k < newArray.length; k++) {
      for (let l = k + 1; l < newArray.length; l++) {
        if (newArray[k] > newArray[l]) {
          let temp = newArray[k];
          newArray[k] = newArray[l];
          newArray[l] = temp;
        }
      }
    }
  }
  return newArray;
};
