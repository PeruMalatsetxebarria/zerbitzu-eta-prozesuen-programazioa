#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> 
#include <string.h> 
//ABUELO-HIJO-NIETO
void main () {
	/*pid_t pid, Hijo__pid, pid2,Hijo2_pid;
	
	int fd1 [2];
	int fd2 [2];
	
	char saludoAbuelo[]="Saludos del Abuelo.\0";
	char saludoPadre[]= "Saludos del Padre..\0";
	char saludoHijo[]= "Saludos del Hijo...\0";
	char saludoNieto[]= "Saludos del Nieto..\0";
	
	char buffer[ 80 ]="";
	
	pipe(fd1);
	pipe(fd2);

    */
    pid_t pid1, pid2;

    int fd1[2]; //1 sememeari bidaltzeko
    int fd2[2]; //1 semeagandik jasotzeko
    int fd3[2]; //2 sememeari bidaltzeko
    int fd4[2]; //2 semeagandik jasotzeko

    pipe(fd1);
    pipe(fd2);
    pipe(fd3);
    pipe(fd4);

    srand(time(NULL));


    int bidali1;
    int semea1bidalikop = 0;
    int semea2bidalikop = 0;







    pid1 = fork (); //semea1 sortu
    pid2 = fork (); //semea1 sortu

    if(pid1==0){
        read(fd1[0], bidali1,sizeof(bidali1));
        write(fd2[1], semea1bidalikop,sizeof(semea1bidalikop));
    }
    if(pid2==0){
        read(fd3[0], bidali1,sizeof(bidali1));
        write(fd4[1], semea2bidalikop,sizeof(semea2bidalikop));
    }


    int i=0;
    while(i<100){
        int r=rand();
        r=(r % 100) + 1;

        if(r%5!=0){ //modulu % gaz?
            if(r%3!=0){
                bidali1=r;
                //2.semeari ere bidali1
                semea1bidalikop++;
                write(fd3[1], bidali1,sizeof(bidali1));
            }
            bidali1=r;
            semea2bidalikop++;
            write(fd1[1], bidali1,sizeof(bidali1));
            //bidali1 1.semeari
        } else if(r%3!=0){
            if(r%5!=0){
                bidali1=r;
                //1.semeari ere bidali1
                semea2bidalikop++;
                write(fd1[1], bidali1,sizeof(bidali1));
            }
            bidali1=r;
            semea1bidalikop++;
            write(fd3[1], bidali1,sizeof(bidali1));
            //bidali1 2.semeari
        }
    }
    close(fd1[1]);
    close(fd3[1]);

    read(fd2[0], semea1bidalikop,sizeof(semea1bidalikop));
    read(fd4[0], semea2bidalikop,sizeof(semea2bidalikop));

    close(fd2[0]);
    close(fd4[0]);

    //2 semeak hil
    kill(pid1);
    kill(pid2);
	
}