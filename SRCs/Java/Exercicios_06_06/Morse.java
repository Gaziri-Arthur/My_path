package Exercicios_06_06;
import java.util.ArrayList;

public class Morse {
    
    private ArrayList <String> morse;

    public Morse()
    {
        morse = new ArrayList<>();

        morse.add("-----"); //0
        morse.add(".----"); //1
        morse.add("..---"); //2  
        morse.add("...--"); //3
        morse.add("....-"); //4
        morse.add("....."); //5
        morse.add("-...."); //6
        morse.add("--..."); //7
        morse.add("---.."); //8
        morse.add("----."); //9
        
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

    public String morse(int n)
    {
        if(n >= 0 || n <= 9)
        {
            return morse.get(n);
        }

        throw new IllegalArgumentException("O número deve estar entre 0 e 9.");
    }
}
