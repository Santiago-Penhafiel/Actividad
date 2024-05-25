#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

void inf (){
    printf("------------------------Inventario de objetos------------------------ \n(Este inventario tiene hasta un m%cximo de 100 productos para ingresar)\n",160);
}

int menu (){
    int opc,insp;
    printf("\n\t\t\t\tMENU \n1 Para ingresar nuevos objetos \n2 Para editar los objetos \n3 Para eliminar los objetos \n4 Para ver la lista de objetos \n5 Para salir \nOpcion : ");
    insp = scanf("%d",&opc);
    (insp!=1)? opc=validarNum(insp):(0);
    return opc;
}

int numObjAñadir (){
    int num=0,insp;
    printf("\t\t\t\tA%cADIR\n",165);
    printf("\nCuantos objetos desea ingresar : ");
        insp = scanf("%i",&num);
        (insp!=1)? num=validarNum(insp):(0);
        //printf("%i\n",num);
        while (num<=0 || num>=100)
        {
            printf("\nIngrese un numero v%clido : ",160);
            insp = scanf("%i",&num);
            (insp!=1)? num=validarNum(insp):(0);
        }
    return num;
}

float validarNum (int insp){
    float num=0;
    while(insp!=1){
        printf("\nIngrese un n%cmero : ",163);
        while (getchar() != '\n');
        insp=scanf("%f",&num);
        //printf("NUM F %i\n",num);
        }
    return num;
}

char* añadirNombre(int index, char nombres[][20]){
    printf("\nIngrese el nombre del producto %i : ",index+1);
    fflush(stdin);
    scanf("%s",&nombres[index]);
    return nombres[index];
}

float añadirDatos (int a,int index, char nombres[][20]){
    int insp;
    float valores[100][2];
       
            if (a==0)
                {
                    printf("\nIngrese la cantidad de productos de %s : ",nombres[index]);
                } else {
                    printf("\nIngrese el precio del producto %s : ",nombres[index]);
                }    
            insp = scanf("%f",&valores[index][a]);
            (insp!=1)? valores[index][a]=validarNum(insp):(0);
        
    return valores[index][a];
}

int comprobarReplicas (char nombres[][20],int index){
    int c;
    char x[10];
    if (index!=0)
    {
        for (int i = 0; i < index; i++)
        {
            if (strcmp(nombres[index],nombres[i])==0)
            {
                printf("El producto que desa agregar ya existe \nDesea ingresar un nuevo nombre (si/no) : ");
                fflush(stdin);
                scanf("%s",&x);
                if (strcmp(x,"si")==0)
                {
                    c=0;
                } else {
                    c=1;
                }
            } else {
                c=2;
            }
        }
    } else {c=2;}
    return c;
}
    
int indexEditar (char nombres[][20]){
    printf("\t\t\t\tEDITAR\n\n");
    char buscar[20] , x[10];
    inicio:
    printf("Ingrese el nombre del producto a editar : ");
    fflush(stdin);
    scanf("%s",&buscar);
    int c=-1;
    for (int i = 0; i < 100; i++)
    {
        if(strcmp(nombres[i],buscar)==0){
            c=i;
            break;}
    }
            if (c==-1)
            {
                printf("El nombre que busca no se encuentra en la base de datos \nDesea ingresar otro nombre (si/no) : ");
                fflush(stdin);
                scanf("%s",&x);
                if (strcmp(x,"si")==0)
                {
                    goto inicio;}
            }
    return c;
}

char* editarNombre (int index, char nombres[][20],float datos [][2]){
    char nuevoNombre[20];
    printf("\nNombre\tCantidad\tPrecio\n%s\t%f\t%f\n",nombres[index],datos[index][0],datos[index][1]);
    reinicio:
    printf("\nNuevo nombre : ");
    fflush(stdin);
    scanf("%s",&nuevoNombre);
    if (strcmp(nuevoNombre,nombres[index])==0)
    {
        printf("\nEl nombre ingresado no puede ser el mismo que el anterior");
        goto reinicio;
    } else {
        for (int i = 0; i < 100; i++)
        {
            if (strcmp(nombres[i],nuevoNombre)==0)
            {
                printf("\nEl producto no puede tener el mismo nombre que otro producto");
                goto reinicio;
            }
        }
    }
    strcpy(nombres[index],nuevoNombre);
    return nombres[index];
}

float editarCantidad (int index, float datos[][2]){
    printf("\nNueva cantidad : ");
    scanf("%f",&datos[index][0]);
    return datos[index][0];
}

float editarPrecio (int index, float datos[][2]){
    printf("\nNuevo precio : ");
    scanf("%f",&datos[index][1]);
    return datos[index][1];
}

int indexEliminar (char nombres[][20]){
    char buscar[20],resp[20];
    int index=-1;
    printf("\t\t\t\tELIMINAR \n");
    reinicio:
    printf ("Qu%c producto desea eliminar : ",130);
    scanf("%s",&buscar);
    for (int i = 0; i < 100; i++)
    {
       // index = strcmp(buscar,nombres[i])==0;
        //printf("DEBE SER 0  :  %i",index);
        //getch();
        if (strcmp(buscar,nombres[i])==0){
            printf("Est%c seguro que desea eliminar el art%cculo \"%s\" (si/no) : ",160,161,nombres[i]);
            scanf("%s",&resp);
            if(strcmp(resp,"si")==0){
                index=i;
                break;
            } else {
                printf("\nDesea ingresar otro producto para eliminar (si/no)");
                scanf("%s",&resp);
                if(strcmp(resp,"si")==0){
                    goto reinicio;
                } else {
                    goto end;
                }
            }
        }
    }
    if (index==-1){
        printf("\nEl producto no existe \nDesea ingresar otro producto para eliminar (si/no) : ");
        scanf("%s",&resp);
        if(strcmp(resp,"si")==0){
            goto reinicio;
        }
    }
    end:
    return index;
}

void imprimirTabla(char nombres [][20], char vacio[], float datos [][2]){
    printf("\t\t\t\tINVENTARIO");
        if (strcmp(nombres[0],vacio)==0)
        {
            printf("\n\nEl inventario est%c vac%co",160,161);
        } else {
            printf("\n\nNOMBRE\t\tCANTIDAD\t\tPRECIO");
            for (int i = 0; i < 100; i++)
            {
                if (strcmp(nombres[i],vacio)==0)
                {
                    break;
                } else {
                    printf("\n\n%s",nombres[i]);
                }
                for (int j = 0; j < 2; j++)
                {
                    printf("\t\t%f",datos[i][j]);
                }
            }
        }
}

int comprobarVacio (char arreglo[][20],char vacio[]){
    int cont,index=-1;
    for (int j = 0; j < 100; j++)
    {
        cont=0;
        /*for (int i = 0; i < 20; i++)
        {
            if ((arreglo[j][i]) != '\0'){
                printf("LLENO\n");
                cont=1;
            } else {
                printf("VACIO\n");
            }
        }
        //printf("Vuelta %i completa\n",j+1);
        if(cont==0){
            index=j;
            //printf("CONTADOR = %i",cont);
            break;
        }*/
        if (strcmp(arreglo[j],vacio)!=0)
        {
            cont=1;
        } else {
            index=j;
            break;
        }
    }
    //printf("INDEX = %i",index);
    return index;
}

char* vaciarStr (int index,char str[][20]){
    memset(str[index],0,sizeof(str[index]));
    return str[index];
}