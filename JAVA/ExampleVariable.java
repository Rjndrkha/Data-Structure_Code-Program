public class ExampleVariable{
	public static void main(String[] args){
		String myHobby = "Bermain Bersepeda ";
		boolean insyaAllah = true;
		char jenisKelamin = 'L';
		byte myAge = 18;
		double myIpk = 4.00, tinggi = 1.78;
			System.out.println(myHobby);
			System.out.println(" Apakah Saya bisa Pandai? " + insyaAllah);
			System.out.println("Jenis Kelamin: " + jenisKelamin);
			System.out.println("Umurku saat ini: " + myAge);
			System.out.println(String.format("saya beripk %s, dengan tinggi badan %s", myIpk, tinggi));
	}
}
