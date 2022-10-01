import java.io.*;
class RomanToNumber {
    static int romanIntValue(char x){
        if(x=='I')
            return 1;
        if(x=='V')
            return 5;
        if(x=='X')
            return 10;
        if(x=='L')
            return 50;
        if(x=='C')
            return 100;
        if(x=='D')
            return 500;
        if(x=='M')
            return 1000;
        return -1;
    }
    
    public static void main(String[] args) throws IOException {
        String str="IV";
        int decimal=0;
        int n=str.length();
        for(int i=0;i<n;i++){
            int s1=romanIntValue(str.charAt(i));
            if(i!=n-1){
                int s2=romanIntValue(str.charAt(i+1));
                if(s1>=s2)
                    decimal=decimal+s1;
                else{
                    decimal=decimal+s2-s1;
                    i++;   
                }
            }
            else
                decimal=decimal+s1;
        }
        System.out.println(decimal);
    }
}