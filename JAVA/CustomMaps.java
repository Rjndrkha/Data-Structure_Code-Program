
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Set;

public class CustomMaps
{
	public static void main(String[] args)
	{
		LinkedHashMap<String,Integer> m =
				new LinkedHashMap<String, Integer>();
		
		m.put("1 - BHK" , 25000);
		m.put("2 - BHK" , 50000);
		m.put("3 - BHK" , 75000);
		m.put("1 - BHK - hall", 65000);
		m.put("2 - BHK - hall", 85000);
		m.put("3 - BHK - hall", 105000);
		
		Set<Map.Entry<String,Integer>> s = m.entrySet();
		
		for (Map.Entry<String, Integer> it: s)
		{
			System.out.println("Before change of value = " +
					it.getKey() + " " + it.getValue());
			
			double getRandom = Math.random() * 100000;
			int getRoundoff = (int) Math.round(getRandom);
				
			it.setValue(getRoundoff);
			
			System.out.println("After change of value = " +
					it.getKey() + " " + it.getValue());
		}
	}
}
