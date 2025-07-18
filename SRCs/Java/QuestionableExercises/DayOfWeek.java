package QuestionableExercises;
public class DayOfWeek {
    
    public static String whatDayIsIt(int Num)
    {
        if(Num < 0 || Num > 6)
        {
            throw new IllegalArgumentException("Número inválido. O número deve estar entre 0 e 6.");
        }
        if(Num == 0)
        {
            return "Domingo";
        }
        else if(Num == 1)
        {
            return "Segunda-feira";
        }
        else if(Num == 2)
        {
            return "Terça-feira";
        }
        else if(Num == 3)
        {
            return "Quarta-feira";
        }
        else if(Num == 4)
        {
            return "Quinta-feira";
        }
        else if(Num == 5)
        {
            return "Sexta-feira";
        }
        else
        {
            return "Sábado";
        }
    }
}
