package Pessoal;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {

    public ArrayList<AlarmClock> alarmes = new ArrayList<AlarmClock>();

    public static void cls() {
        try {
            new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public void AddAlarm() {
        Scanner scanf = new Scanner(System.in);
        System.out.println("===Adicionar Alarme===\n");
        System.out.print("Digite o ano: ");
        int year = scanf.nextInt();
        System.out.print("Digite o mes: ");
        int month = scanf.nextInt();
        System.out.print("Digite o dia: ");
        int day = scanf.nextInt();
        System.out.print("Digite a hora: ");
        int hour = scanf.nextInt();
        System.out.print("Digite os minutos: ");
        int minute = scanf.nextInt();
        System.out.print("Digite o nome do som do alarme incluindo a extensao: ");
        String sound = scanf.nextLine();

        scanf.close();
        AlarmClock alarme = new AlarmClock(year, month, day, hour, minute, sound);
        alarmes.add(alarme);
    }
    
    public void Switch(int num) {
        
        switch (num) {
            case 1:
                AddAlarm();
                cls();
                break;
            
            case 2:
                
                break; 
            
            case 3:
                
                break;
            
            case 4:
                
                break;
            default:
                break;
        }
    }
    public static void main(String[] args) {

        cls();
        Scanner scanf = new Scanner(System.in);


        System.out.println("===Sistema de Alarmes===\n");
        System.out.println("--Digite--\n\n");
        System.out.println("1 Para adicionar Alarme");
        System.out.println("2 Para remover Alarme");
        System.out.println("3 Para alterar um alarme");
        System.out.println("4 Para sair");
        System.out.print("\n--Digite um numero: ");

        int num = scanf.nextInt();

        System.out.println(num);

        scanf.close();  
    }
}