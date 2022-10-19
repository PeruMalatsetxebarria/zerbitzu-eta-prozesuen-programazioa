import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;

public class Faktoriala {
    public static void main(String args[]){


            Scanner sartu_zenbakia = new Scanner(System.in);
            //int sartu_zenbakia2 = sartu_zenbakia.nextInt();


            //ArrayList<String> zenbakiak = new ArrayList<String>();
            String [] zenbakiak = {};

            while (zenbakiak.length != 6){
                int i = zenbakiak.length;
                System.out.println("Sartu zenbaki bat");
                String zenbakia_sartu = sartu_zenbakia.next();
                zenbakiak[i] = zenbakia_sartu;
            }


            int zenbakia = Integer.parseInt(zenbakiak[0]);
            //String zenbakia = zenbakiak[0];
            int faktoriala = 1;

            for(int i=zenbakia;i!=0;i--){
                faktoriala = faktoriala * i;
            }

    }
}
