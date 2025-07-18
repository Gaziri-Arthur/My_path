package ExerciciosRomu;
import java.util.Random;

public class FunnyNumbers 
{

    Random random = new Random();
    public void randomPupulate(int[] nums) 
    {
        for (int i = 0; i < nums.length; i++) 
        {
            nums[i] = random.nextInt(Integer.MAX_VALUE);
        }
    }

    public int countDigits(int num) 
    {
        int count = 0;
        while (num > 0) 
        {
            num /= 10;
            count++;
        }
        return count;
    }
}
