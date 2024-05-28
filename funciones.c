#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

void inf (){
    printf("------------------------Inventario de objetos------------------------ \n(Este inventario tiene hasta un m%cximo de 100 productos para ingresar)\n",160);
}

int menu (){
    int opc,insp;
    printf("\n\t\t\t\tMENU \n\n1 Para ingresar nuevos objetos \n2 Para editar los objetos \n3 Para eliminar los objetos \n4 Para ver la lista de objetos \n5 Para salir \nOpcion : ");
    insp = scanf("%d",&opc);
    (insp!=1)? opc=validarNum(insp):(0);
    return opc;
}

int numObjAñadir (int indexFinal){
    int num=0,insp;
    printf("\t\t\t\tA%cADIR\n",165);
    printf("\n%cCuantos objetos desea ingresar? : ",168);
        insp = scanf("%i",&num);
        (insp!=1)? num=validarNum(insp):(0);
        //printf("%i\n",num);
        while (num<=0 || num>(99-indexFinal))
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
    int c=2;
    char x[10];
    if (index!=0)
    {
        for (int i = 0; i < index; i++)
        {
            if (strcmp(nombres[index],nombres[i])==0)
            {
                printf("\nEl producto que desa agregar ya existe \n\n%cDesea ingresar un nuevo nombre? (si/no) : ",168);
                reinicio:
                fflush(stdin);
                scanf("%s",&x);
                if (strcmp(x,"si")==0)
                {
                    c=0;
                    break;
                } else if (strcmp(x,"no")==0) {
                    c=1;
                    break;
                } else {
                    printf("\nIngrese una respuesta v%clida : ",160);
                    goto reinicio;
                }
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
                printf("\nEl nombre que busca no se encuentra en la base de datos \n\n%cDesea ingresar otro nombre? (si/no) : ",168);
                reinicio:
                fflush(stdin);
                scanf("%s",&x);
                if (strcmp(x,"si")==0)
                {
                    goto inicio;
                } else if (strcmp(x,"no")!=0) {
                    printf("\nIngrese una respuesta v%clida : ",160);
                    goto reinicio;
                }
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
    printf ("\n%cQu%c producto desea eliminar? : ",168,130);
    scanf("%s",&buscar);
    for (int i = 0; i < 100; i++)
    {
       // index = strcmp(buscar,nombres[i])==0;
        //printf("DEBE SER 0  :  %i",index);
        //getch();
        if (strcmp(buscar,nombres[i])==0){
            printf("\n%cEst%c seguro que desea eliminar el art%cculo? \"%s\" (si/no) : ",168,160,161,nombres[i]);
            preguntar:
            fflush(stdin);
            scanf("%s",&resp);
            if(strcmp(resp,"si")==0){
                index=i;
                break;
            } else if (strcmp(resp,"no")==0){
                printf("\n%cDesea ingresar otro producto para eliminar? (si/no) : ",168);
                preguntar2:
                fflush(stdin);
                scanf("%s",&resp);
                if(strcmp(resp,"si")==0){
                    goto reinicio;
                } else if (strcmp(resp,"no")==0) {
                    goto end;
                } else {
                    printf("\nIngrese una respuesta v%clida : ",160);
                    goto preguntar2;
                }
            } else {
                    printf("\nIngrese una respuesta v%clida : ",160);
                    goto preguntar;
            }
        }
    }
    if (index==-1){
        printf("\nEl producto no existe \n\n%cDesea ingresar otro producto para eliminar? (si/no) : ",168);
        pregunta3:
        fflush(stdin);
        scanf("%s",&resp);
        if(strcmp(resp,"si")==0){
            goto reinicio;
        } else if (strcmp(resp,"no")!=0) {
            printf("\nIngrese una respuesta v%clida : ",160);
            goto pregunta3;
        }
    }
    end:
    return index;
}

char* reordenarNombre (int i,char nombres[][20]){
    strcpy(nombres[i],nombres[i+1]);
    return nombres[i];
}

float reordenarDatos(int i,float datos[][2],int j){
    datos[i][j]=datos[i+1][j];
    return datos[i][j];
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
        printf("\n");
}

int comprobarVacio (char arreglo[][20],char vacio[]){
    int cont,index=-1;
    for (int j = 0; j < 100; j++)
    {
        cont=0;
        if (strcmp(arreglo[j],vacio)!=0)
        {
            cont=1;
            //printf("LLENO\n");
        } else {
            index=j;
            //printf("VACIO\n");
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

char* salir (char resp[10]){
        char  x[10];
        printf("%cEst%c seguro de salir? (si/no) : ",168,160);
        fflush(stdin);
        scanf("%s",&x);
        while (strcmp(x,"si")!=0 && strcmp(x,"no")!=0)
        {
            printf("\nIngrese una respuesta v%clida",160);
            fflush(stdin);
            scanf("%s",&x);
        }
        //printf("%s",x);
        strcpy(resp,x);
        return resp;
}

void noValido (){
    printf("\nIngrese una respuesta valida\n");
}