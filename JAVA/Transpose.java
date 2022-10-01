import java.lang.*;
public class Transpose{
    public static void main(String arg[])
    {
        int A[][] = {{1,2,3},{4,5,6},{7,8,9}};
        int B[][] = new int[3][3];
        System.out.println("Matrix:");
        for(int x[]:A)
        {
            for(int y:x)
            {
                System.out.print(y+" ");
            }
            System.out.println();
        }
        for(int i=0;i<A.length;i++)
        {
            for(int j=0;j<A[0].length;j++)
            {
                B[i][j]=A[j][i];
            }
        }
        System.out.println("Transposed Matrix:");
        for(int x[]:B)
        {
            for(int y:x)
            {
                System.out.print(y+" ");
            }
            System.out.println();
        }
    }
}