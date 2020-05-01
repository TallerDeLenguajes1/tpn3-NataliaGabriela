#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100
const char *tiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
typedef struct {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
} Producto;
typedef struct {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
} Cliente;
Cliente *cargarclientes(Cliente *p,int cant_clientes);
float costototal(Producto *c);
void mostrar(Cliente *p,int c);
int main(void){
setvbuf(stdout,NULL,_IONBF,0);
srand(time(NULL));
int cant_clientes;
Cliente *p_clientes;

printf("Ingrese la cantidad de clientes del 1 al 5");
scanf("%d",&cant_clientes);
fflush(stdin);
p_clientes=(Cliente*)malloc(cant_clientes * sizeof(Cliente));
p_clientes=cargarclientes(p_clientes,cant_clientes);
mostrar(p_clientes,cant_clientes);
    scanf("%c");
    return 0;
}
Cliente *cargarclientes(Cliente *p,int cant_clientes)
{
  int i,j,cant;
  char nombre[MAX];
  const char *tipo;
  for ( i = 0; i < cant_clientes; i++)
  {
      p[i].ClienteID=i;
      puts("Ingrese el nombre del cliente");
      gets(nombre);
      p[i].NombreCliente=(char*)malloc(strlen(nombre));
      p[i].NombreCliente=strcpy( p[i].NombreCliente,nombre);
      p[i].CantidadProductosAPedir=rand()%5+1;
      p[i].Productos=(Producto *)malloc( p[i].CantidadProductosAPedir * sizeof(Producto));
      

      for ( j = 0; j <  p[i].CantidadProductosAPedir; j++)
        {
            (p[i].Productos+j)->ProductoID=j;
            (p[i].Productos+j)->Cantidad=rand()%10+1;
            tipo=*tiposProductos+ ( rand ()% 1 * 5 );
            cant=strlen(tipo);
            
            (p[i].Productos+j)->TipoProducto=(char*) malloc(cant * sizeof(const char));
            strcpy((p[i].Productos+j)->TipoProducto,tipo);
            (p[i].Productos+j)->PrecioUnitario=rand()%100+10;
            
        }
    
  }
   printf("---------------------------------------------------------------\n");
   return p;

}
float costototal(Producto *c)
{
    float total;
        total=c->Cantidad * c->PrecioUnitario;
         
return total;    
}
void mostrar(Cliente *p,int c)
{
    int h,k;
    float aux,total_pagar=0;
    for ( h = 0; h < c; h++)
    {
        printf("Cliente numero:%d \n",p[h].ClienteID);
        printf("Nombre del cliente: %s \n",p[h].NombreCliente);
        printf("Cantidad de productos a pedir:%d \n\n",p[h].CantidadProductosAPedir);
        
        for (k = 0; k < p[h].CantidadProductosAPedir ; k++)
        {
            printf("Producto numero: %d\n",(p[h].Productos+k)->ProductoID);
            printf("Cantidad del producto: %d \n", (p[h].Productos+k)->Cantidad);
            printf("Tipo de Producto: %s\n", (p[h].Productos+k)->TipoProducto);
            printf("Precio Unitario: %.2f\n",(p[h].Productos+k)->PrecioUnitario);
            aux=costototal((p[h].Productos+k));
            total_pagar=total_pagar+aux;
            printf("Costo total del producto: %.2f\n",aux);


            printf("---------------\n\n");
        }
        printf("Total a pagar del Cliente: %.2f\n",total_pagar);
        printf("---------------------------------------------------------------\n");
        total_pagar=0;
    }

}