/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package BigarrenEbaluaketa2022eta2023;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author malatse.peru
 */
public class Zerbitzaria {

    
    public static void main (String args[]) throws IOException {
        ServerSocket serbitzaria;
        serbitzaria = new ServerSocket(6000);//portua
        while (true) {
            Socket cliente = new Socket();
            cliente=serbitzaria.accept () ;
            //hariak sortu eta hasi
            HariaZerbitzaria h1 = new HariaZerbitzaria(cliente);
            HariaZerbitzaria h2 = new HariaZerbitzaria(cliente);
            HariaZerbitzaria h3 = new HariaZerbitzaria(cliente);
            
            h1.start();
            h2.start();
            h3.start();
        }
        
    }
}
