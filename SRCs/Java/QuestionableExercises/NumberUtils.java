package QuestionableExercises;
import java.util.Scanner;

public class NumberUtils {
    
    static Scanner scanf = new Scanner(System.in);


    public static void naoSeiNomearEssaFuncao(int n, int m)
    {
        int count = 0;
        for (int i = 1; i < 500; i++) {
            if(i % n == 0 && i % m != 0) {
                count++;
                System.out.println(n + "é divisível por " + i + " e " + m + " não é divisível por " + i);	
            } 
        }
        System.out.println("Total de números encontrados: " + count);
    }
    public static int menu() {
        
        int opt;
        Util.cls();
        System.out.println("Select an option:\n");

        System.out.println("1. Multiply");
        System.out.println("2. Divide");
        System.out.println("3. Check disivibility(s)");
        System.out.println("4. Exit\n");

        System.out.printf("--Option: ");
        do 
        {
            opt = scanf.nextInt();
            if(opt < 1 || opt > 4)
            {
                System.out.printf("\nInvalid option. Please select a valid option:");
            }
        } while (opt < 1 || opt > 4);
        
        return opt;
    }

    private static void exeSumAndSub(boolean isSum) {
        Util.cls();
        int Num, Multiplier, Divisor;
        System.out.println("Enter a number:");
        Num = scanf.nextInt();
        if (isSum) {
            System.out.println("Enter a multiplier:");
            Multiplier = scanf.nextInt();
            System.out.println("Result: " + sucsSum(Num, Multiplier));
        } else {
            System.out.println("Enter a divisor:");
            Divisor = scanf.nextInt();
            System.out.println("Result: " + sucsSubtract(Num, Divisor));
        }
        Util.pause();
    }
    
    private static void exeIsDiv()
    {
        Util.cls();
        int Num;
        System.out.printf("Enter the divisor (2-9):");
        do
        {
            Num = scanf.nextInt();
            if(Num < 2 || Num > 9)
            {
                System.out.printf("\nInvalid option. Please select a valid option:");
            }
        } while (Num < 2 || Num > 9);
        System.out.printf("\nEnter a number to be devided: ");
        int Num2 = scanf.nextInt();
        if(Num == 2)
        {
            System.out.println("Result: " + isDivby2(Num2));
        }
        else if(Num == 3)
        {
            System.out.println("Result: " + isDivby3(Num2));
        }
        else if(Num == 4)
        {
            System.out.println("Result: " + isDivby4(Num2));
        }
        else if(Num == 5)
        {
            System.out.println("Result: " + isDivby5(Num2));
        }
        else if(Num == 6)
        {
            System.out.println("Result: " + isDivby6(Num2));
        }
        else if(Num == 7)
        {
            System.out.println("Result: " + isDivby7(Num2));
        }
        else if(Num == 8)
        {
            System.out.println("Result: " + isDivby8(Num2));
        }
        else if(Num == 9)
        {
            System.out.println("Result: " + isDivby9(Num2));
        }
        Util.pause();

    }

    public static void Run() {
            switch (menu()) {
                case 1:
                    exeSumAndSub(true);
                    break;
                case 2:
                    exeSumAndSub(false);
                    break;
                case 3:
                    exeIsDiv();
                    break;
                default:
                    return;
            }
    }

    public static int sucsSum(int Num, int Multiplier)
    {
        int Constante = Num;
        for(int i = 1; i < Multiplier; i++)
        {
            Num += Constante;
        }

        return Num;
    }

    public static int sucsSubtract(int Num, int Divisor)
    {
        int Constante = Num;
        while(Constante/Divisor != Num)
        {
            Num--;
        }
        return Num;
    }

    public static int sumAllDigits(int Num)
    {
        
        int Sum = 0;
        Num = Math.abs(Num);
        while (Num > 0) {
            Sum += Num % 10;
            Num /= 10;
        }
        return Sum;
    }

    public static boolean isDivby2(int Num)
    {
        return Num % 2 == 0;
    }

    public static boolean isDivby3(int Num)
    {
        return sumAllDigits(Num) % 3 == 0;   
    }

    public static boolean isDivby4(int Num)
    {
        return ((Num % 100) % 4 == 0);
    }

    public static boolean isDivby5(int Num)
    {
        return Num % 5 == 0;
    }

    public static boolean isDivby6(int Num)
    {
        return Num % 6 == 0;
    }

    public static boolean isDivby7(int Num)
    {
        return Num % 7 == 0;
    }

    public static boolean isDivby8(int Num)
    {
        return Num % 8 == 0;
    }

    public static boolean isDivby9(int Num)
    {
        return sumAllDigits(Num) % 9 == 0;
    }

}
