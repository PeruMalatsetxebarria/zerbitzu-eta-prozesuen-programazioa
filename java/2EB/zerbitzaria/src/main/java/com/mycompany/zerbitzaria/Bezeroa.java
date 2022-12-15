/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package com.mycompany.zerbitzaria;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;

/**
 *
 * @author malatse.peru
 */
public class Bezeroa {

    public static void main(String[] args) throws IOException {
        String Host = "127.0.0.1";
        int Puerto = 6006;
        
        Socket cliente = new Socket(Host, Puerto);
        InetAddress i = cliente.getInetAddress();
        System.out.println("Puerto local: " + cliente.getLocalPort());
        System.out.println("Puerto remoto: " + cliente.getPort());
        System.out.println("Host remoto: " + i.getHostName().toString());
        System.out.println("IP host remoto: " + i.getHostAddress().toString());
        
        System.out.println("Programa cliente iniciado");
        OutputStream salida = null;
        salida = cliente.getOutputStream();
        DataOutputStream flujoSalida = new DataOutputStream(salida);
        flujoSalida.writeUTF(" Saludos al servidor desde el cliente");
        
        InputStream entrada = null;
        entrada = cliente.getInputStream();
        DataInputStream flujoEntrada = new DataInputStream(entrada);
        System.out.println("Reciviendo del servidor: \n\t" + flujoEntrada.readUTF());
        
        entrada.close();
        flujoEntrada.close();
    }
}
