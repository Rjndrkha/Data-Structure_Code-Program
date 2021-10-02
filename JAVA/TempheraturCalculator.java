import java.util.Scanner;
public class TempheraturCalculator{
	public static void main(String[] args){
		Scanner input = new Scanner (System.in);
		float celcius,reamur,fahrenheit,kelvin;
			System.out.print("Enter the Temperatur (On Celcius): ");
				celcius = input.nextFloat();
				reamur = celcius * 4f / 5f ;
				fahrenheit = (celcius * 9f /5f) + 32f;
				kelvin = celcius + 273f;
			System.out.println("\tCelcius = " +(int)celcius);
			System.out.println("\tReamur = " +(int)reamur);
			System.out.println("\tFahrenheit = " +(int)fahrenheit);
			System.out.println("\tKelvin = " +(int)kelvin);
	}
}
