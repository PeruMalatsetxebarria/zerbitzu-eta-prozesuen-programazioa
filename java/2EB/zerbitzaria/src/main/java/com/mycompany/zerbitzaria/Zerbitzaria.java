/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.zerbitzaria;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author malatse.peru
 */
public class Zerbitzaria {
    
    public static void main(String[] args) throws IOException {
        int puerto = 6006;
        ServerSocket servidor = new ServerSocket(puerto);
        System.out.println("Escuchando en " + servidor.getLocalPort());
        System.out.println("Esperando al cliente");
        Socket cliente1 = servidor.accept();
        
        System.out.println(servidor.getLocalPort());
        
        InputStream entrada = null;
        entrada = cliente1.getInputStream();
        DataInputStream flujoEntrada = new DataInputStream(entrada);
        System.out.println("Reciviendo del cliente \n\t" + flujoEntrada.readUTF());
        
        OutputStream salida = null;
        salida = cliente1.getOutputStream();
        DataOutputStream flujoSalida = new DataOutputStream(salida);
        
        salida.close();
        flujoSalida.close();
    }
}
