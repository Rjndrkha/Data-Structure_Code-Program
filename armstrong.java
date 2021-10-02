class second{
    int sum=0;
        }

class armstrong {
    public static void main(String[]args){
        int i,j,s,r=0;
        second k= new second();
        s=k.sum;
        for(i=1;i<=1000;i++)
        {
            j=i;
            while(j!=0){
                r=j%10;
                s=s+(r*r*r);
                j=j/10;
            }
            if(s==i){
                System.out.println(i);
            }
        
        s=k.sum;
		}
    }
}