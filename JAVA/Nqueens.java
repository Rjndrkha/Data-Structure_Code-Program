import java.util.*;
public class Nqueens {
    static List<String> res=new ArrayList<>();

    static List<List<String>> resu=new ArrayList<>();
    public static void main(String args[]){
        boolean[][] arr=new boolean[4][4];
        queens(arr,0);
        System.out.print(resu);


    }
    static void queens(boolean[][] board,int row){
        if (row==board.length){
            addBoard(board);
            return;
            
        }

        for (int col=0;col<board.length;col++){
            if (isSafe(board,row,col)){
                board[row][col]=true;
                queens(board, row+1);
                board[row][col]=false;
                
            }
        }
    }
    private static boolean isSafe(boolean[][] board, int row, int col) {
        //VERTICAL CHECK;
        for(int i=0;i<row;i++){
            if (board[i][col]){
                return false;
            }
        }
        int Left=Math.min(row,col);
         //DIAGONAL LEFT
        for (int i=1;i<=Left;i++){
            if (board[row-i][col-i]){
                return false;

            }
        }

        //DIAGONAL RIGHT
        int Right=Math.min(row,board.length-1-col);
        for (int i=1;i<=Right;i++){
            if (board[row-i][col+i]){
                return false;
            }
        }

        return true;
    }
    private static  void addBoard(boolean[][] board) {
        String ans="";
        List<String> res=new ArrayList<>();
        System.out.println(Arrays.deepToString(board));
        System.out.println("---------------------------------------------------------");
        for (boolean[] row:board ){
            for (boolean elem:row){
                if (elem){
                    ans+="Q";

                }
                else{
                    ans+=".";
                }
            }
            res.add(ans);
            ans="";
           
        }
        
        resu.add(res);

    }
}