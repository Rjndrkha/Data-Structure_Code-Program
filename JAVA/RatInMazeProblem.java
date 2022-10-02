class Solution 
{
    public static ArrayList<String> findPath(int[][] m, int n) {
       // Your code here
       ArrayList<String> ans = new ArrayList<>();
       if(m[0][0]==0)return ans;
       boolean[][] visited = new boolean[n+1][n+1];
       visited[0][0] = true;
       RatPath(m,n,0,0,"",ans,visited);
       Collections.sort(ans);
       return ans;
   }
   
   public static void RatPath(int[][]m,int n,int i,int j,String S,ArrayList<String>ans,boolean[][] visited){
       //Up command
       if(i==n-1 && j==n-1){
           ans.add(S);
           return;
       }
       
       //Down command
       if(i+1<n && visited[i+1][j]==false && m[i+1][j]==1){
           visited[i][j] = true;
           RatPath(m,n,i+1,j,S+"D",ans,visited);
           visited[i][j] = false;
       }
       //Left command
       if(j-1>=0 && visited[i][j-1]==false && m[i][j-1]==1){
           visited[i][j] = true;
           RatPath(m,n,i,j-1,S+"L",ans,visited);
           visited[i][j] = false;
       }
       //Right command
       if(j+1<n && visited[i][j+1]==false && m[i][j+1]==1){
           visited[i][j] = true;
           RatPath(m,n,i,j+1,S+"R",ans,visited);
           visited[i][j] = false;
       }
       
       if(i>0 && visited[i-1][j]==false && m[i-1][j]==1){
           visited[i][j] = true;
           RatPath(m,n,i-1,j,S+"U",ans,visited);
           visited[i][j] = false;
       }
   }
}
