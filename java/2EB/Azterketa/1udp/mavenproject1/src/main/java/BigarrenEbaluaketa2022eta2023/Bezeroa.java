/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

package BigarrenEbaluaketa2022eta2023;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketException;
import java.util.Scanner;

/**
 *
 * @author malatse.peru
 */
public class Bezeroa {
    public static void main(String[] args) throws SocketException, IOException {
        InetAddress destino = InetAddress.getLocalHost() ;
        int port = 12345; //portu
        
        
        
        
        /*String Host = "127.0.0.1";
        int port = 6006;
        
        Socket cliente = new Socket(Host, port);
        InetAddress destino = cliente.getInetAddress();*/
        
        
        
        
        byte[] mensaje = new byte[1024];
        
        Scanner sartu_zenbakia = new Scanner(System.in);
        String Saludo = sartu_zenbakia.next();
        mensaje = Saludo.getBytes();
        DatagramPacket envio = new DatagramPacket(mensaje, mensaje.length, destino, port) ;
        DatagramSocket socket = new DatagramSocket(34567);
        System.out.println("Enviando Datagrama de longitud: "+mensaje.length);
        System.out.println("Host destino : "+ destino.getHostName());
        System.out.println("IP Destino : " + destino.getHostAddress());
        System.out.println("Puerto local del socket: " +
        socket.getLocalPort());
        System.out.println("Puerto al que envio: " + envio.getPort());
        socket.send(envio);
        socket.close();
    }
}
