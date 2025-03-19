import java.util.Scanner;

public class Main {

    public static void cls() {
        try {
            new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
    public static void main(String[] args) {

        cls();
        Scanner scanf = new Scanner(System.in);

        System.out.printf("Type in your name: ");
        String name = scanf.nextLine();
        System.out.println("Hello, " + name + "!");
        System.out.println("Your name has " + name.length() + " letters.");
        scanf.close();  
    }
}
