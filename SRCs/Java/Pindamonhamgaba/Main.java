package Pindamonhamgaba;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite um número de 0 a 9: ");

        int num = -1;
        while (num < 0 || num > 9) {
            num = scanner.nextInt();
            if (num < 0 || num > 9) {
                System.out.println("Número inválido. O número deve estar entre 0 e 9.");
            } else {
                Morse morse = new Morse();
                morse.printMorse(num);
            }
        }

        scanner.close();
    }
}
