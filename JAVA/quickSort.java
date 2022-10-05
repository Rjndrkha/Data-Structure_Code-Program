public class quickSort {
    public static void main(String[] args){
        int[] baseArray = { 20, 23, 54, 9, 18, 78 };
    
    for(int i = 0; i< baseArray.length ; i++){
        System.out.println(baseArray[i]);
    }
    }

    public static void QuickSort(int[] input, int begin, int end) {
        if (end - begin <2){
            return;
    }

    int index = partition(input,begin,end);
    QuickSort(input,begin,index);
    QuickSort(input,index+1,end);
    }

    public static int partition(int[] input, int begin, int end){
        int pivot =input[begin];
        int i= begin;
        int j= end;

        while(i<j){
            while (i<j && input[--j] >= pivot);
            if (i<j){
                input[i]=input[j];
            }
            while ( i<j && input[++i] <= pivot);
            if( i<j ){
                input[j]=input[i];
            }
        }
        input[j] = pivot;
        return j;
    }
}
