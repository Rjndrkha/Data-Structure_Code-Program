public class TaskNumber2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int number,totN,i,z;
        float avg;
        System.out.println("Enter the Number range(>0) :");
        number = input.nextInt();
        z =0;
        for(i=1;i<=number;i+=2){
            z += i*i;
        }
        totN = number+1;
        totN = totN/2;
        System.out.println("The number of even number from 1 to "+ number + " is " +totN);
        System.out.println("Total of even number from 1 to "+ number + " is " +z);
        avg =(float)z/totN;
        System.out.printf("The Average of even number from 1 to " +number+" is %.2f \n", avg);
    }
}
