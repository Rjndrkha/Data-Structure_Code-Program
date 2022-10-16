import java.util.Scanner;

class Unification{
	int noOfPredicates, i, j;
	int noOfArgument[];
	String predicate[], arguments[][];
	
	public Unification() {
		// TODO Auto-generated constructor stub
		noOfArgument = new int[10];
		predicate = new String[10];
		arguments = new String[10][10];
	}
	
	
	// unification function
	void unify() {
		
//		int flag=0;
		for(i=0; i<noOfPredicates-1; i++) {
			for(j=0; j<noOfArgument[i]; j++) {
				if(arguments[i+1][j] == arguments[i][j]) {
					System.out.println("\nArguments are identical\nNo need of substitution is there\n");
					break;
					
				}
//					if(flag == 0)
				else {
					System.out.print("\n\nSUBSTITUTION IS:");
					System.out.print("\n"+arguments[i+1][j] + " / " + arguments[i][j]);
//					flag++;
				}
					
			}
		}
//		if(flag == 0) {
//			System.out.println("\nArguments are identical\nNo need of substitution is there\n");
//		}
	}
	
	// Checking for Predicates and arguments
	void checkArgumentPredication(){
		int predicateFlag = 0, argumentFlag = 0;
		// checking predicates
		for(int i=0; i<noOfPredicates-1; i++) {
			if(predicate[i] == predicate[i+1]) {
				System.out.println("\n\nPredicates not same \nUnification cannot progress!");
				predicateFlag = 1;
				break;
			}
		}
		
		// Checking number of arguments
		if(predicateFlag != 1){
			for(int i=0; i<noOfArgument[i]-1; i++) {
				if(noOfArgument[i]!=noOfArgument[i+1]){
	                System.out.print("\nArguments Not Same..!");
	                argumentFlag = 1;
	                break;
                }
			}
		}
		if(argumentFlag == 0 && predicateFlag != 1)
            unify();
	}
	
	// display function
	void display() {
		System.out.print("\n--------------------------------------------------\n");
		System.out.println("\nPredicates are: ");
		for(i=0; i<noOfPredicates; i++) {
			System.out.print("\n" + predicate[i] + '(');
			for(j=0; j<noOfArgument[i]; j++) {
				System.out.print(arguments[i][j]);
				if(j != noOfArgument[i]-1 ) {
					System.out.print(",");
				}
			}
			System.out.print(")");
		}
	}
}
public class UnificationAIML {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		Unification u = new Unification();
		char ch;
		System.out.println("\t\tPROGRAM FOR UNIFICATION\n");
		do {
			System.out.print("\nEnter Number of Predicates:- ");
			u.noOfPredicates = sc.nextInt();

			for (int i = 0; i < u.noOfPredicates; i++) {
//				u.nouse = sc.next(); // to accept "enter" as a character
				System.out.print("\n--------------------------------------------------\n");
				System.out.print("\nEnter Predicate " + (i + 1) + ": ");
				u.predicate[i] = sc.next();
				System.out.print("\nEnter No.of Arguments for Predicate " + u.predicate[i] + ": ");
				u.noOfArgument[i] = sc.nextInt();
				for (int j = 0; j < u.noOfArgument[i]; j++) {
//					u.nouse = sc.next();
					System.out.print("\nEnter argument " + (j + 1) + ": ");
					u.arguments[i][j] = sc.next();
				}
			}

		            u.display();
		            u.checkArgumentPredication();
		            
		            
		            System.out.print("\n\nDo you want to continue(y/n):  ");
		            ch = sc.next().charAt(0);
		       }while(ch == 'y');
	}
}
