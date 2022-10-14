package tictac;

import java.util.logging.Level;
import java.util.logging.Logger;

public class HariaTICTAC extends Thread{

    String mezua="";

    HariaTICTAC(int i) {

        if(i==1){
            mezua="TIC";
        } else {
            mezua="TAC";
        }
        setName(mezua);
    }

    @Override
    public void run(){
        while (true)
        {
            System.out.println(mezua);
            try {
                sleep(100);
            } catch (InterruptedException ex) {
                Logger.getLogger(HariaTICTAC.class.getName()).log(Level.SEVERE, null, ex);

            }
        }
    }
}
