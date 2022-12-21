/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package BigarrenEbaluaketa2022eta2023;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author malatse.peru
 */
public class HariaZerbitzaria extends Thread {
    BufferedReader sarrera;
    PrintWriter irteera;
    Socket socket = null;
    public HariaZerbitzaria(Socket s) throws IOException {
    socket =s;
    irteera = new PrintWriter(socket.getOutputStream(), true);
    sarrera = new BufferedReader(new InputStreamReader(socket.getInputStream())) ;
    }
    public void run() {
        String kt="";
        while (!kt.trim().equals ("*")) {
        System.out.println("COMUNICO CON: "+ socket.toString ()) ;
            try {
                kt = sarrera.readLine();
            } catch (IOException ex) {
                Logger.getLogger(HariaZerbitzaria.class.getName()).log(Level.SEVERE, null, ex);
            }
        irteera.println(kt.trim().toUpperCase());
    }
    System.out.println("FIN CON: "+ socket.toString());
    irteera.close();
        try {
            sarrera.close();
        } catch (IOException ex) {
            Logger.getLogger(HariaZerbitzaria.class.getName()).log(Level.SEVERE, null, ex);
        }
        try {
            socket.close();
        } catch (IOException ex) {
            Logger.getLogger(HariaZerbitzaria.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}