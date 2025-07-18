package Exercicios_06_06;

import java.util.Scanner;

public class Util {
    public static void cls() {
        try {
            new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static void pause() {
        System.out.println("\nPressione ENTER para continuar...");
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();  // Espera até o usuário apertar ENTER
        scanner.close(); // Fecha o scanner para evitar vazamento de recursos
    }
}
