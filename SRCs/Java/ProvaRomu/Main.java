package ProvaRomu;

import java.util.Scanner;

public class Main {

    public static void populateArray(int[] nums) {
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < nums.length; i++) {
            System.out.print("Enter number for the #" + (i + 1) + " position: ");
            nums[i] = scanner.nextInt();
        }
        scanner.close();
    }

    public static void main(String[] args) {

        int[] numsa;
        int[] numsb;
        int[] numsc;

        NumProcs numProcs = new NumProcs();
        Scanner scanner = new Scanner(System.in);

        Util.cls();
        System.out.print("Enter the desired size of the array: ");

        int size = 0;
        while (size < 5) {
            size = scanner.nextInt();
            if (size < 5) {
                System.out.print("Size must be at least 5. Please enter again: ");
            }
        }

        numsa = new int[size];
        populateArray(numsa);
        Util.cls();
        int even = numProcs.checkForEven(numsa);
        int odd = numProcs.checkForOdd(numsa);

        numsb = new int[even];
        numsc = new int[odd];

        numProcs.copyOdd(numsa, numsb);
        numProcs.copyEven(numsa, numsc);

        System.out.println("Number Array:");
        numProcs.printArray(numsa);

        System.out.println("Even Array:");
        numProcs.printArray(numsb);

        System.out.println("Odd Array:");
        numProcs.printArray(numsc);

        System.out.println("Count of odd numbers: " + numProcs.checkForOdd(numsa));
        System.out.println("Count of even numbers: " + numProcs.checkForEven(numsa));

        scanner.close();
    }
}
