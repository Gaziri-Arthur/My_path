//O programa principal deve criar varios objetos portaria e armazena-los em uma colecao. 
//O programa deve ser capaz de ordenar a colecao por emissor ou numero. Pesquise sobre a interface Comparator

//Crie um programa Java contendo, entre outras, uma classe que descreve um documento denominado portaraia com o seguintes
//atributos: numero, emissor, data de emissao e membro

package Simulado;

import java.util.ArrayList;
import java.util.List;
import java.time.LocalDate;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.time.format.DateTimeFormatter;

public class Main {

    static List<Portaria> portarias = new ArrayList<>();
    static Scanner scanf = new Scanner(System.in);

    static void populate(List<Portaria> portarias) {
        portarias.add(new Portaria(1235, "MEC", LocalDate.of(2011, 12, 31), "Joao carlos"));
        portarias.add(new Portaria(7282, "IFPR", LocalDate.of(2017, 11, 17), "Romualdo Chan"));
        portarias.add(new Portaria(823, "ANVISA", LocalDate.of(2023, 4, 14), "Joaquim Pereira"));
        portarias.add(new Portaria(182, "ANBEV", LocalDate.of(2025, 6, 19), "Marcio Beer"));
        portarias.add(new Portaria(681, "ANATEL", LocalDate.of(2001, 7, 25), "Super Choque"));
        portarias.add(new Portaria(81, "CEB", LocalDate.of(2020, 3, 4), "Sargento Careca"));

    }

    static void menu() {
        System.out.println("--Digite: \n");
        System.out.println(" [1] para embaralhar a lista.");
        System.out.println(" [2] para organizar a lista por numero.");
        System.out.println(" [3] para organizar a lista por emissor.");
        System.out.println(" [4] para exibir a lista.");
        System.out.println(" [5] para encerrar o programa.");
        System.out.printf("\n--Opcao: ");

    }

    static void shuffle() {
        Collections.shuffle(portarias);
        System.out.println("Colecao embaralhada com sucesso!");
        try {
            Thread.sleep(1500);
        } catch (InterruptedException e) {
            System.out.println("A pausa foi interrompida.");
        }
    }

    static void sortByNum() {

        Collections.sort(portarias, new Comparator<Portaria>() {
            @Override
            public int compare(Portaria p1, Portaria p2) {
                return Integer.compare(p1.getNumero(), p2.getNumero());
            }
        });

        System.out.println("\nColecao organizada por Numeros com sucesso!");

        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            System.out.println("A pausa foi interrompida.");
        }
    }

    static void sortByEmi() {
        Collections.sort(portarias, new Comparator<Portaria>() {
            @Override
            public int compare(Portaria p1, Portaria p2) {
                return p1.getEmissor().compareTo(p2.getEmissor());
            }
        });
        System.out.println("\nColecao organizada por Emissores com sucesso!");

        try {
            Thread.sleep(1500);
        } catch (InterruptedException e) {
            System.out.println("A pausa foi interrompida.");
        }
    }

    static void printer()
    {
        Util.cls();

        for(Portaria p : portarias)
        {
            System.out.println("Emissor: " + p.getEmissor());
            System.out.println("Membro: " + p.getMembro());
            System.out.println("Numero: " + p.getNumero());
            System.out.println("Publicacao: " + p.getPublicacao());
            System.out.println();
        }
        scanf.nextLine();
        Util.pause(scanf);
    }

    static void suitch(int op) {
        switch (op) {
            case 1:
                shuffle();
                break;
            case 2:
                sortByNum();
                break;
            case 3:
                sortByEmi();
                break;
            case 4:
                printer();
                break;
        }

    }

    static int validate() {
        int op = 0;

        while (op < 1 || op > 5) {
            op = scanf.nextInt();
            if (op < 1 || op > 5) {
                System.out.printf("\nOperador invalido! Digite novamente: ");
            }
        }

        return op;
    }

    public static void main(String[] args) {

        populate(portarias);
        int op = -1;

        do {
            Util.cls();
            menu();
            op = validate();
            suitch(op);

        } while (op != 5);

        scanf.close();
    }
}
