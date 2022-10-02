// this is a heavily modular code with a lot of functionalities. this code can be used as the code base when trying to visualise knapsack algorithm 
// extensive modularity along with loose coupling
// very easy to debug


import java.util.Scanner;
import java.util.Arrays;

class knapsack
{
	static float[] density(float[] p, float[] w, int n)         //calculate the proift-to-weight ratio
	{
		float[] temp=new float[n];
		for(int i=0;i<n;i++)
		{
			temp[i] = p[i]/w[i];
		}
		System.out.println(Arrays.toString(temp));
		
		return temp;
	}

		
	static void decline(float p[], float[] w, float[] d, int n)    //arrange in descending order based on the densities
	{
		int k;
		float t;
		for(int i=0;i<n;i++)
		{	
			for(int j=i+1;j<n;j++)
			{
				if(d[j]>d[i])
				{
					t=d[i];
					d[i]=d[j];
					d[j]=t;
			
					t=p[i];
					p[i]=p[j];
					p[j]=t;
				
					t=w[i];
					w[i]=w[j];
					w[j]=t;
				}
			}
		}
		System.out.println(Arrays.toString(p));
		System.out.println(Arrays.toString(w));
		System.out.println(Arrays.toString(d));
	}


	static float total(float[] w,int n)                              //calculate the current weight of knapsack
	{
		float wt=0;

		for(int i=0;i<n;i++)
		{
			wt+=w[i];
		}

		return wt;
	}
		

	static boolean checking(float[] w, int n, float peak)            //checks if the curr weight of knapsack is less than the maximum
	{
		float tot=total(w,n);
		return tot>=peak;
	}


	static float vacivity(float[] knapsack, int n,float peak)             // returns the free space availible in knapsack
	{	
		return (peak-total(knapsack,n));
	}
	

	
	static float[] filling(float[] p,float[] w,int n, float peak)           //decides which type of filling is to be called(partial or full dump)
	{
		float[] d=density(p,w,n);
		decline(p,w,d,n);
		if(checking(w,n,peak))
		{
			return partial(p,w,n,peak);
		}
		else
		{
			return full(p);
		}

	}


	static float[] full(float[] p)                                 // if the sum of the weights of all the items is less than the bag's threshold, we dump all the items
	{
		return p;
	}


	static float[] partial(float[] p, float[] w, int n, float peak)       // selective filling by prioritizing denser items
	{
		float[] knapsack = new float[n];
		float space;
		float profit=0;
		for(int i=0;i<n;i++)
		{
			space=vacivity(knapsack,n,peak);
			System.out.println(space);
			if(space<w[i])
			{
				knapsack[i]=space;
				profit+=p[i]*space/w[i];                     //add only a fraction of each item in knapsack
				break;
			}
			
			else
			{
				knapsack[i]=w[i];
				profit+=p[i];
			}
		
		}
		System.out.println("the profit is ");
		System.out.println(profit);
		return knapsack;
	}

	
	static float[] fractions(float[] knapsack, float[] w, int n)                    //finds the fraction of each item placed in knapsack
	{
		float[] f=new float[n];
		for(int i=0;i<n;i++)
		{
			f[i]=knapsack[i]/w[i];
		}
		
		return f;
	}

	static float[][] solving(float[] p, float[] w, int n, float peak)                    //calling the functions
	{
		float[] k=filling(p,w,n,peak);                                               // array k stores the weights filled in
		float[] f=fractions(k,w,n);                                                  // array f stores the fraction of original weights filled in 
		float[][] sol={k,f};
		return sol;
	}

	public static void main(String[] args)                                            // driver code
	{
		/*Scanner x=new Scanner(System.in);
		int n=x.nextInt();
		float peak=x.nextFloat();
		float[] p=new float[n];
		float[] w=new float[n];
		for(int i=0;i<n;i++)
		{
			p[i]=x.nextFloat();
		}
		for( int i =0;i<n;i++)
		{
			w[i]=x.nextFloat();
		}*/
		
		float[] p = new float[] {10, 4, 9, 11};
		float[] w = new float[] {3,5,6,2};
		int n= p.length;
		float peak = 7;                                      //maximum capacity of the knapsack
			
		float[][] solution={{0},{0}};
		solution=solving(p,w,n,peak);
		System.out.println(Arrays.toString(solution[0]));            // prints the weights filled in 
		System.out.println(Arrays.toString(solution[1]));	     // prints the fraction of original weights filled in 
	}
}
