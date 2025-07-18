package QuestionableExercises;
public class FulanoECicrano {

    public static int delayCrescimento()
    {
        int anos = 0;
        int alturaFulano = 170, alturaCicrano = 150;
        for (; alturaFulano > alturaCicrano; anos++)
        {
            alturaFulano += 2;
            alturaCicrano += 4;
        }
        return anos;
    }

    public static int delayCrescimento2()
    {
        int anos = 0;
        double alturaFulano = 1.70, alturaCicrano = 1.50;
        for (; alturaFulano > alturaCicrano; anos++)
        {
            alturaFulano += 0.2;
            alturaCicrano += 0.4;
        }
        return anos;
    }
}
