import java.util.Scanner;
public class DeleteElement {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] array = {2,5,7,9,11,13,15,17,19};
         System.out.print("The Number is = ");
        for(int i= 0; i < array.length ;i++){
            System.out.print(array[i]+" ");
        }
        System.out.println();
        System.out.print("Enter the Element you want to be deleted  based on position (1 - 9): ");
        int del = in.nextInt();
        for(int i = 0; i < array.length; i++){
            if(i == (del-1)){
                for(int a = i; a < array.length - 1; a++){
                    array[a] = array[a+1];
                }
                break;
            }
        }
         System.out.println();
        System.out.println("So the Elements -- " );
        for(int i = 0; i < (array.length-1); i++){
            System.out.print(" " + array[i]);
        }
         System.out.println();
    }
}
