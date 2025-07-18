package Pindamonhamgaba;

public class Morse {

    private String[] morse = {
        "------", 
        ".----",  
        "..---",  
        "...--",  
        "....-",  
        ".....", 
        "-....",  
        "--...",  
        "---..",  
        "----."   
    };

    public void printMorse(int num) {
        num --;
        System.out.println(morse[num]);
    }

}
