// Algo for merge sort is mentioned here

Begin
   nLeft := m - left+1
   nRight := right – m
   define arrays leftArr and rightArr of size nLeft and nRight respectively
   for i := 0 to nLeft do
      leftArr[i] := array[left +1]
   done
   for j := 0 to nRight do
      rightArr[j] := array[middle + j +1]
   done
   i := 0, j := 0, k := left
   while i < nLeft AND j < nRight do
      if leftArr[i] <= rightArr[j] then
         array[k] = leftArr[i]
         i := i+1
      else
         array[k] = rightArr[j]
         j := j+1
         k := k+1
   done
   while i < nLeft do
      array[k] := leftArr[i]
      i := i+1
      k := k+1
   done
   while j < nRight do
      array[k] := rightArr[j]
      j := j+1
      k := k+1
   done
End
