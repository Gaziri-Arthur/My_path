package Simulado;

import java.util.Comparator;

public class NumberComparator implements Comparator<Portaria> {

    @Override
    public int compare(Portaria o1, Portaria o2) {
        
        int o1Num = o1.getNumero().intValue();
        int o2Num = o2.getNumero().intValue();

        if(o1Num < o2Num) return 1;
        else if(o1Num > o2Num) return -1;

        return 0;

        //throw new UnsupportedOperationException("Unimplemented method 'compare'");
    }
    
}
