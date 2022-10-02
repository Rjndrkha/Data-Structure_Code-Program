import java.util.Arrays;
import java.util.Scanner;

class Knight
{
	static boolean is_safe(int n,int x, int y, int[][] sol)
	{	
		return(x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1);
	}

	static boolean knightTour(int n,int x,int y, int counter, int[][] sol,int[] xmoves, int[] ymoves)
	{
		if(counter==n*n)
		{	for(int[] i:sol)
			{
				System.out.println(Arrays.toString(i));
			}
			return true;
		}
		
		for(int k=0;k<8;k++)
		{
			int nextx=x+xmoves[k];
			int nexty=y+ymoves[k];
			
			if(is_safe(n,nextx,nexty,sol))
			{
				sol[nextx][nexty]=counter;
				if(knightTour(n,nextx,nexty,counter+1,sol,xmoves,ymoves))
				{
					return true;
				}

				else
				{
					sol[nextx][nexty]=-1;
				}
			}
		}
		

		return false;
	}

		

	
	
		
	public static void main(String[] args)
	{
		Scanner x=new Scanner(System.in);
		int n=x.nextInt();
		int[][] sol=new int[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				sol[i][j]=-1;
			}
		}
		for(int[] i:sol)
		{
			System.out.println(Arrays.toString(i));
		}


		sol[0][0]=0;
		int[] xmoves=new int[]{2, 1, -1, -2, -2, -1, 1, 2};
		int[] ymoves=new int[]{ 1, 2, 2, 1, -1, -2, -2, -1 };

		knightTour(n,0,0,1,sol,xmoves,ymoves);
	}
}
