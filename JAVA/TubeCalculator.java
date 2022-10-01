import java.util.Scanner;
public class Tube{
	public static void main(String[] args){
		Scanner input = new Scanner (System.in);
		int radius, height;
		float area, phi = 3.14f;
			System.out.print("Enter the Radius : ");
				radius = input.nextInt();
			System.out.print("Enter the Height : ");
				height = input.nextInt();
			area = phi * radius * radius * height;
			System.out.print("Tube area is = " + area);
	}
}
