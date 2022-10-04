#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int fd[2];
    pid_t pid;
    char mezua[] = "Buenos dias padre";
    char buffer[80];
 
    pipe(fd);
    pid = fork();

    switch (pid)
    {
    case -1:
        printf("Ezin izan da semea sortu");
        exit(-1);
    case 0:
        close(fd[0]);
        write(fd[1], mezua, strlen(mezua));
        printf("\t Semeak mezua bidali.\n");
        break;
    default:
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Aitak mezua jaso. %s \n", buffer);
        break;
    }
    return 0;
}