package ExerciciosRomu;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        int[] nums;
        FunnyNumbers funnyNumbers = new FunnyNumbers();
        Scanner scanner = new Scanner(System.in);
        Util.cls();
        System.out.print("Quantos números você quer gerar? ");
        int n = 0; 
        while (n < 1) {
            n = scanner.nextInt();
            if (n < 1) {
                System.out.print("Por favor, insira um número positivo maior que 0: ");
            }
        }
        Util.cls();
        nums = new int[n];

        funnyNumbers.randomPupulate(nums);
        for (int i = 0; i < nums.length; i++) {
            System.out.printf("Posicao: %d. Numero: %d, Digitos: %d\n", i + 1, nums[i], funnyNumbers.countDigits(nums[i]));
        }

        scanner.close();
    }


}
