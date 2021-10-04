/*
Example:-
Input m & n
100
500
Fascinating Numbers: 192  219  273  327
Frequency Of Fascinating Numbers:4
*/

package com.company;
import java.util.*;
public class Fascinating
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Input m & n");
        int m=sc.nextInt();
        int n=sc.nextInt();
        int a,b,c;
        String s="",f=" ",a1,b1,c1;
        int freq=0;
        for(int i=m;i<n;i++)
        {
            a=i*1;
            a1=a+"";
            b=i*2;
            b1=b+"";
            c=i*3;
            c1=c+"";
            s=a1+""+b1+""+c1;
            if(fascinate(s))
            {
                f+=i+"  ";
                freq++;
            }
            else
                continue;
        }
        if(freq==0)
        {
            System.out.println("No Fascinating Number");
        }
        else
        {
            System.out.println("Fascinating Numbers:"+f);
            System.out.println("Frequency Of Fascinating Numbers:"+freq);
        }
    }
    static boolean fascinate(String s)
    {
        String s1="";
        String n="";
        char ch;
        for(int i=0;i<s.length();i++)
        {
            ch=s.charAt(i);
            if(ch=='0')
                continue;
            else
            {
                s1+=ch;
            }
        }
        if(s1.length()==9)
        {
            for(int i=1;i<=9;i++)
            {
                n=i+"";
                if(s1.indexOf(n)==s1.lastIndexOf(n))
                {
                    continue;
                }
                else
                    return false;
            }
            return true;
        }
        else
            return false;
    }
}

