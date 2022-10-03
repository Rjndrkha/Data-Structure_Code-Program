import java.util.Scanner;


class sol {
    public static int romanToInt(String s) {
        int sum=0;
        for(int i=0;i<s.length();i++)
        {
            char c = s.charAt(i);
            if((c=='I')&&(i+1!=s.length()))
            {
                if(s.charAt(i+1)=='V'){
                    sum+=4;
                    i+=1;
                    continue;
                }
                else if(s.charAt(i+1)=='X'){
                    sum+=9;
                    i+=1;
                    continue;
                }
            }
            if((c=='X')&&(i+1!=s.length())){
                if(s.charAt(i+1)=='L'){
                    sum+=40;
                    i+=1;
                    continue;
                }
                else if(s.charAt(i+1)=='C'){
                    sum+=90;
                    i+=1;
                    continue;
                }
            }
            if((c=='C')&&(i+1!=s.length())){
                if(s.charAt(i+1)=='D'){
                    sum+=400;
                    i+=1;
                    continue;
                }
                else if(s.charAt(i+1)=='M'){
                    sum+=900;
                    i+=1;
                    continue;
                }
            }
            switch(c)
            {
                case'I':{
                    sum+=1;
                    break;
                }
                case'V':{
                    sum+=5;
                    break;
                }
                case'X':{
                    sum+=10;
                    break;
                }
                case'L':{
                    sum+=50;
                    break;
                }
                case'C':{
                    sum+=100;
                    break;
                }
                case'D':{
                    sum+=500;
                    break;
                }
                case'M':{
                    sum+=1000;
                    break;
                }
            }
        }
        return sum;
    }
}
public class Roman{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String n;
        n=sc.nextLine();
        sol ob = new sol();
        int r=ob.romanToInt(n);
        System.out.println(r);
    }
}