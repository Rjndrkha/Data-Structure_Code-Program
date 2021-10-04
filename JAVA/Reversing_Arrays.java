public class Reversing_Array {

    public static void main(String[] args) {
        int[] array = {1, 3, 6, 8, 24};

//        Reverse_Array(array);
          Reverse_Array2( array, 0, (array.length - 1));

        for(int i = 0; i< array.length; i++) {
            System.out.print(array[i] + ", ");
        }
    }

    // Iterative Method
    
//    public static void Reverse_Array(int[] arr){
//        int start = 0;
//        int end = arr.length - 1;
//        while (start < end){
//            int temp = arr[start];
//            arr[start] = arr[end];
//            arr[end] = temp;
//            start++;
//            end--;
//        }

    
    // Recursive Method
    
    public static void Reverse_Array2(int[] arr, int start, int end){
        if(start >= end){
            return;
        }

            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            Reverse_Array2(arr, start + 1, end - 1);
    }
}
