import java.util.*;
import static java.lang.System.*;

public class DecimalToBinary {
	public static void main(String[] args) {
		Scanner input = new Scanner(in);
		out.print("Enter a number: ");
		long number = input.nextLong();
		out.println("Binary representation of " + number + ":");
		out.println("1. Using in-built method: " + Long.toBinaryString(number));
		out.println("2. Using custom method: " + toBinaryString(number));
	}
	public static String toBinaryString(long number) {
		String bin = "";
		for (long i = 63; i >= 0; i--) {
			int bit = (number & (1l << i)) != 0 ? 1 : 0;
			bin += bit;
		}
		return bin.replaceAll("^0+(?=.)", "");
	}
}