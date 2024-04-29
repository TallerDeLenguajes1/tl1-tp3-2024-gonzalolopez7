#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 5

void cargarNombres(char ** vector, int cantNombres);
void mostrarNombres(char ** vector, int cantNombres);

int main() {

    char ** vector;
    int cantNombres;
    printf("Ingresar cantidad de nombres: ");
    scanf("%d", &cantNombres);
    vector = (char **)malloc(sizeof(char *) * cantNombres);
    cargarNombres(vector, cantNombres);
    printf("\n");
    mostrarNombres(vector, cantNombres);
    for (int i = 0; i < cantNombres; i++)
    {
        free(*vector);
        vector++;
    }
    free(vector);

    return 0;
}

void cargarNombres(char ** vector, int cantNombres)
{

    char *nombre = (char *)malloc(sizeof(char) * 50);

    for (int i = 0; i < cantNombres; i++)
    {
        
        printf("Ingresar nombre %d: ", i+1);
        fflush(stdin);
        gets(nombre);
        vector[i] = (char *)malloc((strlen(nombre)+1) * sizeof(char));
        strcpy(vector[i], nombre);

    }

    free(nombre);

}

void mostrarNombres(char ** vector, int cantNombres)
{

    for (int i = 0; i < cantNombres; i++)
    {
        
        printf("Nombre %d: ", i+1);
        puts(vector[i]);

    }

}
