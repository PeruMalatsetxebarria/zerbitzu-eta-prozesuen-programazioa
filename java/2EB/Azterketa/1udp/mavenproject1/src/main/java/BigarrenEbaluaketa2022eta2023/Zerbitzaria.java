/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package BigarrenEbaluaketa2022eta2023;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

/**
 *
 * @author malatse.peru
 */
public class Zerbitzaria {

    public static void main(String[] args) throws IOException {
        byte[] bufer = new byte[1024];
        DatagramSocket socket = new DatagramSocket(12345);
        
        
        
        
        
        
        System.out .println("Esperando Datagrama' ......... ");
        DatagramPacket recibo = new DatagramPacket(bufer, bufer.length);
        socket.receive(recibo);
        int bytesRec = recibo.getLength();
        String paquete= new String(recibo.getData());
        System.out.println("Número de Bytes recibidos: "+ bytesRec);
        System.out.println("Contenido del Paquete : "+ paquete.trim());
        System.out.println("Puerto origen del mensaje: "+ recibo.getPort());
        System.out.println("IP de origen : "+
        recibo.getAddress().getHostAddress());
        System.out.println("Puerto destino del mensaje:" +
        socket.getLocalPort());
        socket.close();
    }
}
