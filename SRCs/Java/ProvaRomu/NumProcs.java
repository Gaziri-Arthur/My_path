package ProvaRomu;

public class NumProcs {
    

    public void copyOdd(int [] numsa, int [] numsb)
    {
        for (int i = 0, j = 0; i < numsa.length; i++) {
            if (numsa[i] % 2 == 0) {
                numsb[j] = numsa[i];
                j++;
            }
        }
    }

    public void copyEven(int [] numsa, int [] numsc)
    {
        for (int i = 0, j = 0; i < numsa.length; i++) {
            if (numsa[i] % 2 != 0) {
                numsc[j] = numsa[i];
                j++;
            }
        }
    }

    public int checkForOdd(int [] nums) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] % 2 != 0) {
                count++;
            }
        }
        return count;
    }

    public int checkForEven(int [] nums) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] % 2 == 0) {
                count++;
            }
        }
        return count;
    }

    public void printArray(int [] nums) {
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println();
    }
}


