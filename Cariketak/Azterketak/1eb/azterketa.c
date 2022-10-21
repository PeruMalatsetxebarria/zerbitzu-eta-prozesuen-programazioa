#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    pid_t pid,pid2,semea1_pid,semea2_pid,aita_pid;
 
    /*int semea1_pid;
    int semea2_pid;
    int aita_pid;*/

    int fd1 [2];
	int fd2 [2];

    int buffer;

    pipe(fd1); //1 semearentzat
	pipe(fd2); //2 semearentzat

    switch (pid)
    {
    case -1:
        printf("Ezin izan da semea sortu");
        exit(-1);
    case 0:
        semea1_pid=getpid();
        aita_pid=getppid();
        
        break;
    default:
        pid2 = fork();
        if (pid2==-1){
            printf("Ezin izan da semea sortu");
        } else if (pid2==0){
            semea2_pid=getpid();
        } else{
            int aukera;
            int diru_kant=10000;
            while (aukera!=0){
                printf("Aukeratu zer egin nahi duzun");
                printf("1-Dirua atera");
                printf("2-Dirua sartu");
                printf("3-Kontuaren egungo egoera ikusi");
                printf("0-Irten");
                scanf(aukera);
                //aukera;
                switch (aukera)
                {
                    case 1:
                    semea2_pid = wait();
                    printf("Dirua ateratzea aukeratu duzu");
                    printf("Aukeratu zenbat diru atera nahi duzun:");
                    int diru_atera;
                    if (diru_atera>diru_kant){
                        printf("Ezin duzu duzun dirua baino gehiago atera");
                    } else{
                        diru_kant=diru_kant-diru_atera;

                        buffer = diru_atera;

                        close(fd1[0]) ;
			            write(fd1[1], buffer, sizeof (buffer));
                    }
                    return aukera=1;
                    break;

                    case 2:
                    semea1_pid = wait();
                    printf("Dirua sartzea aukeratu duzu");
                    printf("Aukeratu zenbat diru sartu nahi duzun:");
                    int diru_sartu;
                    diru_kant=diru_kant+diru_sartu;

                        buffer=diru_sartu;

                        close(fd2[0]) ;
			            write(fd2[1], buffer, sizeof (buffer));

                    return aukera=2;
                    break;

                    case 3:
                    semea1_pid = wait();
                    semea2_pid = wait();
                    printf("Kontuaren egungo egoera ikustea aukeratu duzu");
                    printf("Kontuan duzun dirua: %s\n€",diru_kant);


                    close(fd1[1]);
				    read(fd1[0], buffer, sizeof(buffer) );
				    printf("\t\tOrain arte ateratako diru guztia: %s\n",buffer);


                    close(fd2[1]);
				    read(fd2[0], buffer, sizeof(buffer) );
				    printf("\t\tOrain arte sartutako diru guztia: %s\n",buffer);

                    return aukera=3;
                    break;

                    case 0:
                    printf("Programatik irtetzea aukeratu duzu");
                    kill(semea1_pid);
                    kill(semea2_pid);
                    return aukera=0;
                    break;

                    default:
                    printf("Aukera ez da zuzena. Saiatu berriz");
                    return aukera=4;
                    break;
                }
                return aukera;
            }
            printf("Programatik irtetzea aukeratu duzu");
            kill(semea1_pid);
            kill(semea2_pid);
            
        }
        break;
    }
}
