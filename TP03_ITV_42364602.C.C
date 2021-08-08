#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct
{
  int T_numart;
  char T_descri[81];
  int T_ustock;
  float T_uprecio;
}T_pinturas;

int LEE_CONTROL1 (int li, int ls);
int LEE_CONTROL2 (int li, int ls);
int estaDentroDelRango(int , int , int );
int busqueda_secuencial (T_pinturas [], int , int );
int MAYORCERO (void);
void ingresoVenta (T_pinturas[],int[],float[],int ,int[]);
int leerArchivo (T_pinturas[],int );
void guardarArchivo ( T_pinturas[],int);
void maximo(int [], int );

int main ()
{
T_pinturas pinturasvec[500]={0};
float C_clientefacturacion[100]={0};
int C_clientecant[100]={0};
int cant=0,cantclientes=0,i,j,k,x;

cant=leerArchivo(pinturasvec,500);

int InformaNOstock[cant];

ingresoVenta (pinturasvec,C_clientecant,C_clientefacturacion,cant,InformaNOstock);

///punto a
for (i=0; i<100;i++)
printf("CLIENTE NRO %d , FACTURACION TOTAL: %d \n",i+1,C_clientefacturacion[i]);

///punto b
for (j=0; j<100;j++)
printf("CLIENTE NRO %d , CANTIDAD DE COMPRAS; %d \n",j+1,C_clientecant[j]);
maximo(C_clientecant,100);

///punto c

printf("\nCLIENTE\t MONTO FACTURADO\t   CANT COMPRAS REALIZADAS");
    for(k=0 ; k <cant ; k++)
    {
        printf("\n%4d\t%8.2f \t%-51d", k+1,C_clientefacturacion[k],C_clientecant[k]);
    }

///punto d

for(x=0;x<cant;x++)
printf("NO STOCK ART %d",InformaNOstock[x]);


/// punto e


guardarArchivo(pinturasvec,cant);



return 0;
}
/////////////////////////////////////////////

int MAYORCERO ()
{
int bandera=0,uvendida;

    do
            {
                if(bandera ==1 )
                    printf("\nDATO INCORRECTO, ");

                bandera=1;

                printf("INGRESE CANTIDAD DE UNIDADES VENDIDAS : \n");
                scanf("%d",&uvendida);

            }
            while(uvendida<1);

return uvendida;
}
int busqueda_secuencial (T_pinturas v[], int cant, int elem)
{
    int i, pos;
    i = 0;
    pos = -1;
    while(i < cant && pos == -1)
    {
        if(v[i].T_numart == elem)
            pos = i;
        else
            i++;
    }
    return pos;
}
int estaDentroDelRango(int limiteInferior, int limiteSuperior, int valorAControlar)
{
    int aux;

    if(valorAControlar==-1 || (valorAControlar >= limiteInferior && valorAControlar <= limiteSuperior))
        aux=1;
    else
        aux=0;

    return aux;
}

int LEE_CONTROL1 (int li, int ls)
{
    int valor, b = 0;
    do
    {
        if( b == 1)
            printf("\nDATO INCORRECTO, ");

        b = 1;

        printf("INGRESE UN CODIGO DE CLIENTE(1 A 100 O -1 PARA SALIR): \n ", li, ls);
        scanf("%d",&valor);

    } while (estaDentroDelRango(li, ls, valor) == 0);

    return valor;
}

int LEE_CONTROL2 (int li,int ls)
{
int bandera=0,numarticulo;

       do
            {
                if(bandera ==1 )
                    printf("\nDATO INCORRECTO, ");

                bandera=1;

                printf("INGRESE NUMERO DE ARTICULO \n");
                scanf("%d",&numarticulo);

            }
            while(numarticulo<li && numarticulo>ls);

return numarticulo;
}
/////////////////////////////////////////////


int leerArchivo (T_pinturas vec[],int cant)
{
FILE * arch;
int i=0;

arch = fopen("pinturas.dat", "rb");
if (arch==NULL)
{
 printf("No se pudo abrir el archivo.");
 getch();
 exit (1);
}

fread(&vec[i], sizeof(T_pinturas), 1, arch);
while(i<cant && !feof(arch))
{
    i++;
    fread(&vec[i], sizeof(T_pinturas), 1, arch);
}
fclose(arch);

return i;
}

void ingresoVenta (T_pinturas vec[],int vecCant[],float vecFact[],int N,int noStock[])
{
    int numcliente,numarticulo,bandera=0,posart,unidvend,j=0,i;

    numcliente=LEE_CONTROL1(1,100); ///INGRESO NUM CLIENTE

    while (numcliente!=-1)
    {



    /// VALIDO Y BUSCO NUM ARTICULO

            numarticulo=LEE_CONTROL2(1000,9999);

            posart=busqueda_secuencial(vec,N,numarticulo);
            if(posart==-1)
            {
                while(posart>=0)
                {
                    printf("ARTICULO INEXISTENTE, VUELVA A INGRESAR \n");
                    numarticulo=LEE_CONTROL2(1000,9999);
                    posart=busqueda_secuencial(vec,N,numarticulo);
                }
            }

            unidvend=MAYORCERO();

            if (unidvend>vec[posart].T_ustock)
            {
                printf("STOCK INSUFICIENTE");
                noStock[j]=numarticulo;

                FILE * STOCKINS;

                STOCKINS = fopen("FALTASTOCK.dat" , "a+b");
                if (STOCKINS==NULL)
                {
                    printf("No se pudo crear el archivo.");
                    getch();
                    exit (1);
                }
                for(i=0 ; i < N; i++)
                {
                    fwrite(&vec[posart], sizeof(T_pinturas), 1, STOCKINS);
                }
                fclose(STOCKINS);

            }

            vec[posart].T_ustock-=unidvend; ///RESTO UNIDADES VENDIDAS AL STOCK
            vecCant[numcliente-1]++;   //// SUMO CANT VENTA POR CLIENTE
            vecFact[numcliente-1]+=vec[posart].T_uprecio*unidvend;   ///SUMO FACTURACION POR CLIENTE
            j++; ///SUMADOR CANTIDAD DE VENTA
                printf("\n----------------\n");

            numcliente=LEE_CONTROL1(1,100); ///INGRESO NUM CLIENTE

    }



}

void maximo(int vecCantCompras[], int cant)///punto c, maximo UNICO
{
    float max;
    int i,b=0, pos;

    for(i=0 ; i < cant; i++)
    {
        if(b==0 || vecCantCompras[i]>max)
        {
            b=1;
            max=vecCantCompras[i];
            pos=i;///me guardo la posicion para luego mostrar todos los datos
        }
    }

    printf("EL CLIENTE CON MAYOR COMPRAS FUE EL NRO %d CON %d COMPRAS", pos+1,max);

}

void guardarArchivo ( T_pinturas prod[],int cant)
{
    FILE * pf;
    int i;

// ahora lo grabo a un archivo
pf = fopen("pinturas.dat" , "wb");
if (pf==NULL)
{
    printf("No se pudo crear el archivo.");
    getch();
    exit (1);
}
for(i=0 ; i < cant; i++)
{
    fwrite(&prod[i], sizeof(T_pinturas), 1, pf);
}
fclose(pf);

}
