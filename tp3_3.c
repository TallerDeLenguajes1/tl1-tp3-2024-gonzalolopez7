#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 5

void cargarNombres(char * vector[N]);
void mostrarNombres(char * vector[N]);

int main() {

    char * vector[N];
    cargarNombres(vector);
    printf("\n");
    mostrarNombres(vector);

    return 0;
}

void cargarNombres(char * vector[N])
{

    char nombre[50];

    for (int i = 0; i < N; i++)
    {
        
        printf("Ingresar nombre %d: ", i+1);
        gets(nombre);
        vector[i] = (char *)malloc((strlen(nombre)+1) * sizeof(char));
        strcpy(vector[i], nombre);

    }

}

void mostrarNombres(char * vector[N])
{

    for (int i = 0; i < N; i++)
    {
        
        printf("Nombre %d: ", i+1);
        puts(vector[i]);

    }

}
