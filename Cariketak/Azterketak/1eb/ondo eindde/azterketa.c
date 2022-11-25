#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) //void main() //int main(void)
{
    pid_t pid1,pid2,semea1_pid,semea2_pid,aita_pid;
 
    /*int semea1_pid;
    int semea2_pid;
    int aita_pid;*/

    int fd1 [2];
	int fd2 [2];
    int fd3 [2];
	int fd4 [2];

    int buffer;

    pipe(fd1); //1 semearentzat
	pipe(fd2); //2 semearentzat

    aita_pid=getpid();
    
    pid1 = fork();
    if (pid1==-1){
        printf("Ezin izan da 1. semea sortu\n\n");
    } else if (pid1==0){
        semea1_pid=getpid();
    }
    
    pid2 = fork();
    if (pid2==-1){
        printf("Ezin izan da 2. semea sortu\n\n");
    } else if (pid2==0){
        semea2_pid=getpid();
    }



    //seme denak sartzen dira, bakarrik aita sartu behar da
    if (aita_pid==getpid()){

        int aukera=4;
        int diru_kant=10000;
    
        while (aukera!=0){
            printf("\n");
            printf("Aukeratu zer egin nahi duzun\n");
            printf("1-Dirua atera\n");
            printf("2-Dirua sartu\n");
            printf("3-Kontuaren egungo egoera ikusi\n");
            printf("0-Irten\n");
            scanf("%i",&aukera);
            //aukera;
            switch (aukera)
            {
                case 1:
                    semea2_pid = wait();
                    printf("Dirua ateratzea aukeratu duzu\n");
                    printf("Aukeratu zenbat diru atera nahi duzun:\n");
                    int diru_atera;
                    scanf("%i",&diru_atera);



                    printf(diru_atera);
                    printf(diru_kant);



                    if (&diru_atera>&diru_kant){ //EZTABIL
                        printf("Ezin duzu duzun dirua baino gehiago atera\n");
                    } else{
                        printf("diru atarada2222222222222");
                        &diru_kant=&diru_kant-diru_atera;

                        buffer = diru_atera;



                        close(fd1[0]) ;
                        write(fd1[1], buffer, sizeof (buffer)); //write(fd1[1], buffer, sizeof (buffer));
                        
                        
                        
                        
                        printf("diru atarada2222222222222");
                    }
                    return aukera=1;
                    //break;

                case 2:
                    semea1_pid = wait();
                    printf("Dirua sartzea aukeratu duzu\n");
                    printf("Aukeratu zenbat diru sartu nahi duzun:\n");
                    int diru_sartu;
                    scanf("%i",&diru_sartu);
                    diru_kant=diru_kant+diru_sartu;

                        buffer=diru_sartu;


                        printf("diru sartusda111111111");

                        close(fd2[0]) ;
                        write(fd2[1], buffer, sizeof (buffer));




                        printf("diru sartuda22222222222");

                    return aukera=2;
                    //break;

                case 3:
                    //semea1_pid = wait();
                    //semea2_pid = wait();
                    printf("Kontuaren egungo egoera ikustea aukeratu duzu\n");
                    printf("Kontuan duzun dirua: "&diru_kant"€\n"); //printf("Kontuan duzun dirua: %s€\n",&diru_kant);


                    close(fd1[1]);
                    read(fd1[0], buffer, sizeof(buffer) );
                    printf("\t\tOrain arte ateratako diru guztia: %s\n",buffer);


                    close(fd2[1]);
                    read(fd2[0], buffer, sizeof(buffer) );
                    printf("\t\tOrain arte sartutako diru guztia: %s\n",buffer);

                    return aukera=3;
                    //break;

                case 0:
                    printf("Programatik irtetzea aukeratu duzu\n");
                    kill(semea1_pid);
                    kill(semea2_pid);
                    return aukera=0;
                    //break;

                default:
                    printf("Aukera ez da zuzena. Saiatu berriz\n");
                    return aukera=4;
                    //break;
            }
            return aukera;
        }
    }
    /*printf("Programatik irtetzea aukeratu duzu\n");
    kill(semea1_pid); //SIGKILL
    kill(semea2_pid);
    //waitpid(semea1_pid??)*/
        
        
}
