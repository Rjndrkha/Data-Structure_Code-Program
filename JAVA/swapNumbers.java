public class swapNumbers {
    public static void main(String[] args) {
        int num1 = 5, num2 = 15;
        num2=num1 + num2 -(num1=num2);//b=a+b-(a=b)
        System.out.println("After swapping:\n num1\t"+num1+"\n num2\t"+num2);
    }
}
