import java.util.Scanner;

public class GuessNumberApp {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String guess, limit = "", reload; 
        boolean check = true;

        System.out.println("==========================================");
        System.out.println("-----Guest Number App by Mufti Alie S-----");
        System.out.println("==========================================");

        while (check == true) {
            System.out.println("In this program you are challenged to guess "); 
            System.out.println("numbers from 1 to the number limit you want");
            System.out.println("(example numbers 1 to 50), good luck ^_^\n");

            do {
                try {
                    System.out.print("Enter the guess number limit = ");
                    limit = input.next();

                    if (Integer.parseInt(limit) <= 0) {
                        System.out.println("The number limit you have to be positive");
                        check = true;
                    } else {
                        check = false;
                    }
                } catch (Exception e) {
                    System.out.println("The input you entered is wrong!!");
                    check = true;
                }

            } while (check == true);

            int value =1+ (int) (Math.random() * Integer.parseInt(limit));
            System.out.println("");

            while (check == false) {
                try {
                    System.out.print("Enter guess numbers (1-" + limit + ")= ");
                    guess = input.next();

                    if (Integer.parseInt(guess) >= 1 && Integer.parseInt(guess) <= Integer.parseInt(limit)) {
                        if (Integer.parseInt(guess) == value) {
                            System.out.println("Your guess is right");
                            System.out.println("Congratulations, finished the game :D\n");
                            check = true;
                        } else if (Integer.parseInt(guess) > value) { 
                            System.out.println("Your guess is too big");
                            check = false;
                        } else if (Integer.parseInt(guess) < value) {
                            System.out.println("Your guess is too small");
                            check = false;
                        }
                    } else if (Integer.parseInt(guess) < 1 || Integer.parseInt(tebak) > Integer.parseInt(limit)) {
                        System.out.println("The input you entered is not between 0-" + limit);
                        check = false;
                    }
                } catch (Exception e) {
                    System.out.println("The input you entered is wrong!!!");
                    check = false;
                }
            }

            do {
                System.out.print("Do you want to re-guess(yes/no)? ");
                reload = input.next();
                if (reload.equalsIgnoreCase("yes")) {
                    System.out.println("");
                    check = true;
                } else if (reload.equalsIgnoreCase("no")) {
                    System.out.println("Thank you for using this app :)");
                    return;
                } else {
                    System.out.println("The input you entered is wrong !!!");
                    check = false;
                }
            } while (check == false);
        }
    }
}