import java.util.*;
class stonePaperScissor{
  static int uW=0,cW=0;
  static String toChoice(int num){
    if(num==1){
      return "stone";
    }
    else if(num==2){
      return "paper";
    }
    else{
      return "scissors";
    }
  }
  static void play(){
    Scanner sc=new Scanner(System.in);
    System.out.println("\nEnter your choice 1 for stone,2 for paper, 3 for scissors:");
    int user=sc.nextInt();
    if(user>=1 && user<=3){
      Random rnd=new Random();
      int comp=rnd.nextInt(3)+1;
      if(user==1 && comp==2 || user==2 && comp==3 || user==3 && comp==1){
        System.out.println("Computer won!");
        System.out.println("Computer choice: "+toChoice(comp));
        System.out.println("Your choice: "+toChoice(user));
        cW++;
      }
      else if(user==comp){
        System.out.println("Draw....");
        System.out.println("Computer choice: "+toChoice(comp));
        System.out.println("Your choice: "+toChoice(user));
      }
      else{
        System.out.println("You won!");
        System.out.println("Computer choice: "+toChoice(comp));
        System.out.println("Your choice: "+toChoice(user));
        uW++;
      }
    }else{
      System.out.println("Enter valid input!!");
      play();
    }
  }
  public static void main(String a[]){
    Scanner sc=new Scanner(System.in);
    System.out.println("Enter the number of terms: ");
    int t=sc.nextInt();
    for(int i=0;i<t;i++){
      play();
    }
    if(uW==cW){
      System.out.println("\nThis match was a draw.");
    }
    else if(uW>cW){
      System.out.println("You won this match!");
    }
    else{
      System.out.println("Computer won this match!");
    }
  }
}
