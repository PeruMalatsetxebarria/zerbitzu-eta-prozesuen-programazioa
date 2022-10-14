public class HiloEjemplo1 extends Thread {
    private int c; //contador de cada hilo
    private int hilo;


    //constructor
    public HiloEjemplo1(int hilo) {
        this.hilo=hilo;
        System.out.println("CREANDO HILO:" + hilo);
    }
    //método run
    public void run () {
        c=0 ;
        while (c<=99999 ) {
            //System.out.println("Hilo:" + hilo + " C = " + c) ;
            if(hilo==1){
                System.out.println("TIC") ;
            } else{
                System.out.println("TAC") ;
            }
            c++;

            try {
                sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }

        }
    }

    public static void main(String[] args) {
    HiloEjemplo1 h = null;
    for (int i = 0; i < 2; i++) {
        h = new HiloEjemplo1(i+1); //crear hilo
        h.start(); //iniciar hilo
    }
System.out.println("2 HILOS CREADOS...");
}// main
}// clase