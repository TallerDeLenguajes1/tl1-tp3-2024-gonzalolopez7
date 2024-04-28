#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct
{
    
    int productoId;
    int cantidad;
    char *tipoProducto;
    float precioUnitario;

}typedef Producto;

struct
{
    
    int clienteId;
    char *nombreCliente;
    int cantidadProductosAPedir;
    Producto *productos;

}typedef Cliente;

void cargarClientes(Cliente *clientes, int cantClientes, char *tiposProductos[]);
void cargarProductos(Producto *productos, int cantProductos, char *tiposProductos[]);
float calcularTotal(float precioUnitario, int cantidad);
void mostrarClientes(Cliente *clientes, int cantClientes);
void mostrarProductos(Producto *productos, int cantProductos, float *totalCliente);

int main() {

    int cantClientes;
    Cliente *clientes;
    char *tiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

    printf("Ingresar cantidad de clientes: ");
    scanf("%d", &cantClientes);

    clientes = (Cliente *)malloc(cantClientes * sizeof(Cliente));
    cargarClientes(clientes, cantClientes, tiposProductos);
    mostrarClientes(clientes, cantClientes);

    return 0;
}

void cargarClientes(Cliente *clientes, int cantClientes, char *tiposProductos[])
{

    char *buff = (char *)malloc(sizeof(char) * 100);
    srand(time(NULL));
    for (int i = 0; i < cantClientes; i++)
    {
        
        clientes[i].clienteId = i;
        printf("Ingresar nombre de cliente %d: ", i+1);
        fflush(stdin);
        gets(buff);
        clientes[i].nombreCliente = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(clientes[i].nombreCliente, buff);
        clientes[i].cantidadProductosAPedir = rand() % 5 + 1;
        clientes[i].productos = (Producto *)malloc(clientes[i].cantidadProductosAPedir * sizeof(Producto));
        cargarProductos(clientes[i].productos, clientes[i].cantidadProductosAPedir, tiposProductos);

    }
    free(buff);

}

void cargarProductos(Producto *productos, int cantProductos, char *tiposProductos[])
{

    for (int i = 0; i < cantProductos; i++)
    {
        
        productos[i].productoId = i;
        productos[i].cantidad = rand() % 10 + 1;
        int nroTipo = rand() % 5;
        productos[i].tipoProducto = (char *)malloc((strlen(tiposProductos[nroTipo]) + 1) * sizeof(char));
        strcpy(productos[i].tipoProducto, tiposProductos[nroTipo]);
        productos[i].precioUnitario = rand() % 91 + 10;

    }

}

float calcularTotal(float precioUnitario, int cantidad)
{

    return (precioUnitario * cantidad);
}

void mostrarClientes(Cliente *clientes, int cantClientes)
{

    float totalCliente;

    for (int i = 0; i < cantClientes; i++)
    {
        totalCliente = 0;
        printf("\nCliente ID %d", clientes[i].clienteId);
        printf("\nNombre: %s", clientes[i].nombreCliente);
        printf("\nCantidad de productos a pedir: %d\n", clientes[i].cantidadProductosAPedir);
        mostrarProductos(clientes[i].productos, clientes[i].cantidadProductosAPedir, &totalCliente);
        printf("\nTotal a pagar: %.2f\n", totalCliente);

    }

}

void mostrarProductos(Producto *productos, int cantProductos, float *totalCliente)
{

    for (int i = 0; i < cantProductos; i++)
        {
            
            *totalCliente += calcularTotal(productos[i].precioUnitario, productos[i].cantidad);
            printf("\nProducto %d\n", i+1);
            printf("ID: %d - Cantidad: %d - Tipo: %s - Precio unitario: %.2f\n", productos[i].productoId, productos[i].cantidad, productos[i].tipoProducto, productos[i].precioUnitario);

        }

}
