import java.util.Scanner;
import java.util.*;

class NumberToRoman
{
	public static String convertToRoman(int n)
	{
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
	return result;
    }

	public static void main(String args[])
	{
		int N=45;	
		System.out.println (convertToRoman(N));
	}
}
