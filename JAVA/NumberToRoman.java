import java.util.Scanner;
import java.util.*;

class NumberToRoman
{
	public static void main(String args[])
	{
		int n=45;	
		String romans[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    		int nums[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
		int myNum=n;
		String result="";
		for(int i=12;i>=0;i--){
	    		while(myNum>=nums[i]){
	        		result+=romans[i];
	        		myNum-=nums[i];
	    		}
		}
		System.out.println (result);
	}
}
