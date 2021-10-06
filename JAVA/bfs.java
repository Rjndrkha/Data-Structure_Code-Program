import java.util.*;

public class bfs{

	public static void main(String[] args)
{
	Scanner sc=new Scanner(System.in);
	int V=sc.nextInt();
	int E=sc.nextInt();
	boolean edge[][]=new boolean[V][V];
	for(int i=0;i<E;i++)
	{
		int f=sc.nextInt();
		int s=sc.nextInt();
		edge[f][s]=true;
		edge[s][f]=true;
	}
	int a=sc.nextInt();
	int b=sc.nextInt();
	getpathbfs(edge,V,a,b);
			
			
			
}

private static void getpathbfs(boolean[][] edge, int v, int a, int b) {
	// TODO Auto-generated method stub
	Queue<Integer> pending=new LinkedList<Integer>();
	boolean visited[]=new boolean[v];
	HashMap<Integer,Integer> map=new 	HashMap<Integer,Integer>();
	pending.add(a);
	visited[a]=true;
	while(!pending.isEmpty())
	{
		int curr=pending.poll();
		for(int i=0;i<v;i++)
		{
			if(edge[curr][i]&&!visited[i])
			{
				pending.add(i);
				visited[i]=true;
				map.put(i, curr);
				if(i==b)
				{
					break;
				}
			}
		}
	}	
		//System.out.println("yes");
		if(map.containsKey(b))
		{
			//System.out.println("yes");
			int p=b;
			while(p!=a)
			{
				System.out.print(p+" ");
				p=map.get(p);
			}
			System.out.print(a);
		}else{
            return;
        }
	
	
}

}