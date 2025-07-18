package Simulado;

import java.util.Scanner;

public class Util {
    public static void cls() {
        try {
            new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static void pause(Scanner scanf) {
        System.out.println("\nPressione ENTER para continuar...");
        scanf.nextLine();
    }
}
