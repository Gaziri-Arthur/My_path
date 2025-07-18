package Exercicios_06_06;

import java.util.Scanner;
public class ListMain 
{
    public ListMain() 
    {
        Morse morse = new Morse();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite um número entre 0 e 9: ");
        int num = scanner.nextInt();
        System.out.println("Digito: " + num + "\nem morse: " + morse.morse(num));
        scanner.close();
    }

    public static void main(String[] args) 
    {
        Util.cls();
        new ListMain();
    }
}