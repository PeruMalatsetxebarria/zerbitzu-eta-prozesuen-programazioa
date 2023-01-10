#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


#include <signal.h>
#include <time.h>
int main() //void main() //int main(void)
{
    pid_t pid1, pid2;

    int fd1[2];
    int fd2[2];
    int fd3[2];
    int fd4[2];

    pipe(fd1);
    pipe(fd2);
    pipe(fd3);
    pipe(fd4);

    double diru_kant = 1000;
    //double dirua = 0;
    double atera_diru_guzt= 0;
    double sartu_diru_guzt = 0;
    int aukera=-1;
    
    pid1 = fork();

    if(pid1 == -1){
        printf("Ezin izan da 1. semea sortu\n\n");
        exit(-1);
    }else if(pid1 == 0){
        while(1){
            close(fd3[0]);
            close(fd3[1]);
            int kantitatea = 0;
            read(fd3[0],&kantitatea,sizeof(kantitatea));
            atera_diru_guzt += kantitatea;
            write(fd4[1],&atera_diru_guzt,sizeof(atera_diru_guzt));
        }
    }else{
        pid2 = fork();
        if(pid2 == -1){
            printf("Ezin izan da 2. semea sortu\n\n");
            exit(-1);
        }else if(pid2 == 0){
            while(1){
            close(fd3[0]);
            close(fd3[1]);
            int kantitatea = 0;
            read(fd3[0],&kantitatea,sizeof(kantitatea));
            sartu_diru_guzt -= kantitatea;
            write(fd4[1],&sartu_diru_guzt,sizeof(sartu_diru_guzt));
        }
        }else{
            while(aukera != 0){
                printf("\n\n");
                printf("Aukeratu zer egin nahi duzun\n");
                printf("1-Dirua atera\n");
                printf("2-Dirua sartu\n");
                printf("3-Kontuaren egungo egoera ikusi\n");
                printf("0-Irten\n\n");
                scanf("%d",&aukera);

                switch(aukera){
                    case 1:
                        int diru_atera = 0;
                        printf("Dirua ateratzea aukeratu duzu\n");
                        printf("Aukeratu zenbat diru atera nahi duzun:\n");
                        scanf("%d",&diru_atera);

                        if(diru_kant >= diru_atera){
                            diru_kant -= diru_atera;
                            
                            write(fd3[1],&diru_atera,sizeof(diru_atera));
                        } else {
                            printf("Ezin duzu duzun dirua baino gehiago atera\n");
                            diru_atera = 0;
                        }
                        break;
                    case 2:
                        int diru_sartu = 0;
                        printf("Dirua sartzea aukeratu duzu\n");
                        printf("Aukeratu zenbat diru sartu nahi duzun:\n");
                        scanf("%d",&diru_sartu);

                        diru_kant += diru_sartu;
                        break;
                    case 3:
                        printf("Kontuaren egungo egoera ikustea aukeratu duzu\n");
                        printf("Kontuan duzun dirua: %lf€\n",diru_kant);
                        int atera_kant = 0;
                        read(fd4[0],&atera_kant,sizeof(atera_kant));
                        printf("Ateratako diru guztia: %d",diru_atera);
                        break;
                    case 0:
                        printf("Programatik irtetzea aukeratu duzu\n");
                        //kill();
                        //kill();
                        break;
                    default:
                        printf("Aukera ez da zuzena. Saiatu berriz\n");
                        break;
                }
            }
        }
    }
}
