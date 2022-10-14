package tictac;

import java.util.logging.Level;
import java.util.logging.Logger;

public class TICTAC {
    public static void main(String[] args) {
        HariaTICTAC hTIC=new HariaTICTAC(1);
        HariaTICTAC hTAC=new HariaTICTAC(0);

        hTIC.start();
        hTAC.start();

        try{
            hTIC.join();
            hTAC.join();
        } catch (InterruptedException ex){
            Logger.getLogger(TICTAC.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
