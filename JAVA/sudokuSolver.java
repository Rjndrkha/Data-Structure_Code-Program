class Solution {
    
    public boolean isSafe(char[][] board, int row, int col, char num){
        for(int i = 0; i < 9; i++){
            if(num == board[i][col]){
                return false;
            }
            if(num == board[row][i]){
                return false;
            }
        }
        int startR = row - row%3;
        int startC = col - col%3;
        for(int i=startR; i<startR+3; i++){
            for(int j=startC; j<startC+3; j++){
                if(board[i][j]==num) return false;
            }
        }
        return true;
    }
    
    public boolean solution(char[][] board){
        for(int row=0; row<9; row++){
            for(int col = 0; col< 9; col++){
                
                if(board[row][col] == '.'){
                    
                    for(char i='1';i<='9';i++){
                        if(isSafe(board, row, col, i)){
                            board[row][col] = i;
                            
                            if(solution(board)==true){
                                return true;
                            }
                            else{
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    public void solveSudoku(char[][] board) {
        solution(board);
    }
}
