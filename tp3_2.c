#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 5
#define M 12

void cargarMatriz(int matriz[N][M]);
void mostrarMatriz(int matriz[N][M]);
float calcularPromedio(int matriz[N][M]);
void calcularMinMax(int matriz[N][M], int *min, int *max);

int main() {

    int matriz[N][M], max = 0, min = 0;

    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    printf("promedio: %.2f\n", calcularPromedio(matriz));
    calcularMinMax(matriz, &min, &max);
    printf("valor minimo: %d - valor maximo: %d", min, max);

    return 0;
}

void cargarMatriz(int matriz[N][M])
{

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        { 
            matriz[i][j] = (rand() % 40001) + 10000;
        }
    }

}

void mostrarMatriz(int matriz[N][M])
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

float calcularPromedio(int matriz[N][M])
{
    float promedio = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        { 
            promedio += matriz[i][j];
        }
    }

    promedio = promedio / (N * M);

    return promedio;
}

void calcularMinMax(int matriz[N][M], int *min, int *max)
{
    int auxMin = matriz[0][0], auxMax = matriz[0][0];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matriz[i][j] < auxMin)
            {
                auxMin = matriz[i][j];
            }
            if (matriz[i][j] > auxMax)
            {
                auxMax = matriz[i][j];
            }
        }
    }

    *min = auxMin;
    *max = auxMax;
}
