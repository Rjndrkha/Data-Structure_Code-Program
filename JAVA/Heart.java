// create class HeartPatternExample1 that will print Heart pattern  
public class HeartPatternExample1  
{  
        // main() method start  
        public static void main(String[] args)  
        {  
                // declare and initialize variable for output size  
                final int size = 4  ;  
          
                // nested for loop to print the upper part of Heart  
            for (int m = 0; m < size; m++) {  
                    for (int n = 0; n <= 4 * size; n++) {  
                            double pos1 = Math.sqrt(Math.pow(m - size, 2) + Math.pow(n - size, 2));  
                            double pos2 = Math.sqrt(Math.pow(m - size, 2) + Math.pow(n - 3 * size, 2));  
   
                            if (pos1 < size + 0.5 || pos2 < size + 0.5) {  
                                    System.out.print('*');  
                            } else {  
                                    System.out.print(' ');  
                            }  
                        }  
                        System.out.print(System.lineSeparator());  
                }  
                // for loop to print the lower part of Heart  
                for (int m = 1; m <= 2 * size; m++)  
                {  
                    for (int n = 0; n < m; n++) {  
                        System.out.print(' ');  
                }  
                for (int n = 0; n < 4 * size + 1 - 2 * m; n++) {  
                        System.out.print("*");  
                    }  
                System.out.print(System.lineSeparator());  
            }  
    }  
}  
