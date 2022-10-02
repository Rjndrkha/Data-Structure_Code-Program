import java.util.Arrays;
import java.util.Scanner;

class RatMaze
{
	static boolean issafe(int n, int x, int y,int[][] maze,int[][] sol)                                       //checking if position is safe
	{
		return( x<n && y<n && x>=0 && y>=0 && maze[x][y]==1);
	}


	static boolean path(int n,int x, int y, int [] xmoves, int[] ymoves, int[][] maze, int[][] sol)          //moving in the path
	{

		if(x==n-1 && y==n-1)                                                                               //destination reached
		{	
			sol[x][y]=1;
			System.out.println("the solution path is as follows");
			for(int [] i:sol)                                                                            //print all the rows of maze solution
			{
				System.out.println(Arrays.toString(i));
			}
			return true;
			
		}

//iterative  checking of paths

		if(issafe(n,x,y,maze,sol))                                                                         //checking for next positions if safe, continue, else backtrack
		{
			sol[x][y]=1;
			for(int k=0;k<2;k++)
			{
	
				if(path(n,x+xmoves[k],y+ymoves[k],xmoves,ymoves,maze,sol))                            //next move will lead to a feasible soltion
				{
					return true;
				}
			
			}
			
			sol[x][y]=0;                                                                                // did not return means the path dosen't exist, so backtrack
			return false;                                                                               // no path exists down this road , so return false
		}

	
//manual checking of paths

				
		/*if(issafe(n,x,y,maze))
		{
			sol[x][y]=1;
			
			if(path(n,x+1,y,xmoves,ymoves,maze,sol))
			{
				return true;
			}
			
			if(path(n,x,y+1,xmoves,ymoves,maze,sol))
			{
				return true;
			}

			sol[x][y]=0;
			return false;
		}

		return false;*/
		return false;

	}
		

	public static void main(String[] args)
	{
		int[][] maze={{1,1,1,0},                                           //0 indicates block, 1 indicates clear road of the maze
				  {0,1,1,0},
				  {1,1,0,0},
				  {1,1,1,1}};
		System.out.println("the maze is as follows");

		for(int [] i :maze)
		{
			System.out.println(Arrays.toString(i));
		}
		int n=maze.length;
		int[][] sol=new int[n][n];

		for(int i=0;i<n;i++)                                             // intialize solution matrix to zero																										
		{
			for(int j=0;j<n;j++)
			{
				sol[i][j]=0;
			}
		}
		
		sol[0][0]=1;

		int[] xmoves={1,0};
		int[] ymoves={0,1};

		if(!path(n,0,0,xmoves,ymoves,maze,sol))
		{
			System.out.println(" no solution exists for the given maze");
		}

	}

}

		

		
