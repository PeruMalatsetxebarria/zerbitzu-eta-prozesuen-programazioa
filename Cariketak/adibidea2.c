#include <stdio.h>
#include <unistd.h>
void main(void)
{
	printf("Ejemplo de uso de exec():");
	printf("Los archivos en el directorio son:\n");
	execl("/bin/ls", "Is", "-1", (char *)NULL);
	printf("¡¡¡ Esto no se ejecuta !!!\n");
}
