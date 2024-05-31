#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"


void eliminar(){
    printf("\t\t\t\tELIMINAR \n");
}

void añadir(){
    printf("\t\t\t\tA%cADIR \n",165);
}

void inf (){
    printf("------------------------Inventario para joyer%ca------------------------ \n",161);
}

int menu (){
    int opc,insp;
    printf("\n\t\t\t\t\tMENU \n\n1 Para ingresar nuevos objetos \n2 Para editar los objetos \n3 Para eliminar los objetos \n4 Para ver la lista de objetos \n5 Para salir \nOpcion : ");
    insp = scanf("%i",&opc);
    (insp!=1)? opc=validarNum(insp):(0);
    return opc;
}

int añadirMaterial (){
    int insp,num;
    printf("\n1 Para oro \n2 Para plata \nMaterial a ingresar : ");
    while (getchar() != '\n');
    insp = scanf("%i",&num);
    (insp!=1)? num=validarNum(insp):(0);
    while (num<=0 || num>2)
        {
            printf("\nIngrese un numero v%clido : ",160);
           while (getchar() != '\n');
            insp = scanf("%i",&num);
            (insp!=1)? num=validarNum(insp):(0);
        }
    return num;
}

int añadirTipo (){
    int insp,num;
    printf("\t\t\t\tA%cADIR\n",165);
    printf("\n1 Para collares \n2 Para pulseras \n3 Para anillos \nTipo a ingresar : ");
    while (getchar() != '\n');
    insp = scanf("%i",&num);
    (insp!=1)? num=validarNum(insp):(0);
    while (num<=0 || num>3)
        {
            printf("\nIngrese un numero v%clido : ",160);
            while (getchar() != '\n');
            insp = scanf("%i",&num);
            (insp!=1)? num=validarNum(insp):(0);
        }
    return num;
}


int numObjAñadir (int indexFinal){
    int num=0,insp;
    printf("\n%cCuantos objetos desea ingresar? : ",168);
    while (getchar() != '\n');
    insp = scanf("%i",&num);
    (insp!=1)? num=validarNum(insp):(0);
        //printf("%i\n",num);
        while (num<=0)
        {
            printf("\nIngrese un numero v%clido : ",160,160,161);
            while (getchar() != '\n');
            insp = scanf("%i",&num);
            (insp!=1)? num=validarNum(insp):(0);
        }
        if (num>=(10-indexFinal))
        {
            printf("\nNo puede haber m%cs de 10 art%cculos por categor%ca\n",160,161,161);
            num = -1;
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

char* añadirNombre(int tipo, int material, int index, char nombres[][2][11][20]){
    printf("\nPRODUCTO %i\n\nIngrese el nombre o c%cdigo del producto %i : ",index+1,162,index+1);
    while (getchar() != '\n');
    scanf("%[^\n]",&nombres[tipo][material][index]);
    return nombres[tipo][material][index];
}

float añadirDatos (int a,int index, char nombres[][2][11][20], int tipo, int material){
    int insp,entero;
    float valores;
            if (a==0)
                {
                    printf("\nIngrese la cantidad de productos de %s : ",nombres[tipo][material][index]);
                } else {
                    printf("\nIngrese el precio del producto %s : ",nombres[tipo][material][index]);
                }    
            while (getchar() != '\n');
            insp = scanf("%f",&valores);
            (insp!=1)? valores=validarNum(insp):(0);
            entero = (int) valores;
            if (a==0)
            {
                while (valores<=0 || (valores-entero)!=0)
                {
                    while (valores<=0)
                    {
                        printf("\nLas cantidades no pueden ser negativas, ingrese nuevamente : ");
                        while (getchar() != '\n');
                        insp = scanf("%f",&valores);
                        (insp!=1)? valores=validarNum(insp):(0);

                    }
                    while ((valores-entero)!=0)
                    {
                        printf("\nLas cantidades deben ser enteras, ingrese nuevamente : ");
                        while (getchar() != '\n');
                        insp = scanf("%f",&valores);
                        (insp!=1)? valores=validarNum(insp):(0);
                        entero = (int) valores;
                    }
                }                
            } else {
                while (valores<=0)
                {
                    printf("\nIngrese un valor v%clido : ",160);
                    while (getchar() != '\n');
                    insp = scanf("%f",&valores);
                    (insp!=1)? valores=validarNum(insp):(0);
                }
            }
    return valores;
}

int comprobarReplicas (int tipo, int material, char nombres[][2][11][20],int index){
    int c=2;
    char x[2];
    if (index!=0)
    {
        for (int i = 0; i < index; i++)
        {
            if (strcmp(nombres[tipo][material][index],nombres[tipo][material][i])==0)
            {
                printf("\nEl producto que desa agregar ya existe \n\n%cDesea ingresar un nuevo nombre? (si/no) : ",168);
                reinicio:
                while (getchar() != '\n');
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
    
char* nombreAEditar (int tipo, int material,char nombres[][2][11][20],char a[]){
    char buscar[20],x[2];
    inicio:
    printf("Ingrese el nombre del producto a editar : ");
    //printf("BUSCAR : %s\n",buscar);
    while (getchar() != '\n');
    scanf("%[^\n]",&buscar);
    int c=-1;
    for (int i = 0; i < 10; i++)
    {
        if(strcmp(nombres[tipo][material][i],buscar)==0){
        c=0;
        break;}
    }
            if (c==-1)
            {
                printf("\nEl nombre que busca no se encuentra en la base de datos \n\n%cDesea buscar otro nombre? (si/no) : ",168);
                reinicio:
                while (getchar() != '\n');
                scanf("%s",&x);
                if (strcmp(x,"si")==0)
                {
                    goto inicio;
                } else if (strcmp(x,"no")!=0) {
                    printf("\nIngrese una respuesta v%clida : ",160);
                    goto reinicio;
                }
            }
    strcpy(a,buscar);
    return a;
}

void editar(){
    printf("\t\t\t\tEDITAR\n\n");
}

int obtenerTipo(){
    int tipo, insp;
    printf("\nElija el tipo de joyer%ca \n\n1 Para collares \n2 Para pulseras \n3 Para anillos \nOpcion : ",161);
    while (getchar() != '\n');
    insp = scanf("%i",&tipo);
    (insp!=1)? tipo=validarNum(insp):(0);
    while (tipo<=0 || tipo>3)
    {
        printf("\n\nIngrese una opcion valida : ");
        while (getchar() != '\n');
        insp = scanf("%i",&tipo);
        (insp!=1)? tipo=validarNum(insp):(0);
    }
    return tipo;
}

int obtenerMaterial(){
    int material, insp;
    printf("\nElija el tipo de material\n\n1 Para oro \n2 Para plata \nOpcion : ");
    while (getchar() != '\n');
    insp = scanf("%i",&material);
    (insp!=1)? material=validarNum(insp):(0);
    while (material<=0 || material>2)
    {
        printf("\n\nIngrese una opcion valida : ");
        while (getchar() != '\n');
        insp = scanf("%i",&material);
        (insp!=1)? material=validarNum(insp):(0);
    }
    return material;
}

int buscarIndex(int tipo, int material, char buscar[],char nombres[][2][11][20]){
    int index=-1;
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(buscar,nombres[tipo][material][i])==0)
        {
            index = i;
            break;
        }
    }
    return index;
}

void tablaEditar (int tipo, int material, int index, char nombres[][2][11][20], float datos[][2][10][2]){
    printf("\nNombre\t\tCantidad\t\tPrecio\n%s\t\t%.0f\t\t\t$%.2f\n",nombres[tipo][material][index],datos[tipo][material][index][0],datos[tipo][material][index][1]);
}

int opcEditar(){
    int a, insp;
    printf("\nEscoja el valor a editar \n1 Para el nombre \n2 Para la cantidad \n3 Para el precio");
    printf("\n%cQu%c valor desea editar? : ",168,130);
    insp = scanf("%i",&a);
    (insp!=1)? a=validarNum(insp):(0);
    while (a!=1 && a!=2 && a!=3)
    {
        printf("\nIngrese una opci%c v%clida : ",162,160);
        insp = scanf("%i",&a);
        (insp!=1)? a=validarNum(insp):(0);
    }
}

char* editarNombre (int tipo, int material, int index, char nombres[][2][11][20],float datos [][2][10][2]){
    char nuevoNombre[20];
    reinicio:
    printf("\nNuevo nombre : ");
    while (getchar() != '\n');
    scanf("%[^\n]",&nuevoNombre);
    if (strcmp(nuevoNombre,nombres[tipo][material][index])==0)
    {
        printf("\nEl nombre ingresado no puede ser el mismo que el anterior");
        goto reinicio;
    } else {
        for (int i = 0; i < 3; i++)
        {
            if (strcmp(nombres[tipo][material][i],nuevoNombre)==0)
            {
                printf("\nEl producto no puede tener el mismo nombre que otro producto");
                goto reinicio;
            }
        }
        
    }
    strcpy(nombres[tipo][material][index],nuevoNombre);
    return nombres[tipo][material][index];
}



float editarCantidad (){
    float num;
    int insp,entero;
    printf("\nNueva cantidad : ");
    while (getchar() != '\n');
    insp = scanf("%f",&num);
    (insp!=1)? num=validarNum(insp):(0);
    entero = (int) num;
        while (num<=0 || (num-entero)!=0){
            while (num<=0)
            {
                printf("\nLas cantidades no pueden ser negativas, ingrese nuevamente : ");
                while (getchar() != '\n');
                insp = scanf("%f",&num);
                (insp!=1)? num=validarNum(insp):(0);

            }
            while ((num-entero)!=0)
            {
                printf("\nLas cantidades deben ser enteras, ingrese nuevamente : ");
                while (getchar() != '\n');
                insp = scanf("%f",&num);
                (insp!=1)? num=validarNum(insp):(0);
                entero = (int) num;
            }
        }     
    
    return num;
}

float editarPrecio (){
    float num;
    int insp;
    printf("\nNuevo precio : ");
    while (getchar() != '\n');
    insp = scanf("%f",&num);
    (insp!=1)? num=validarNum(insp):(0);
    while (num<=0)
    {
        printf("Ingrese un precio v%clido : ",160);
        while (getchar() != '\n');
        insp = scanf("%f",&num);
        (insp!=1)? num=validarNum(insp):(0);
    }
    return num;
}


char* nombreAEliminar (int tipo, int material, char buscar [],char nombres[][2][11][20]){
    char resp[20],x[20];
    int index=-1;
    reinicio:
    printf ("\n%cQu%c producto desea eliminar? : ",168,130);
    while (getchar() != '\n');
    scanf("%[^\n]",&x);
    for (int i = 0; i < 10; i++)
    {
       
        // index = strcmp(buscar,nombres[i])==0;
        //printf("DEBE SER 0  :  %i",index);
        //getch();
        if (strcmp(x,nombres[tipo][material][i])==0){
            printf("\n%cEst%c seguro que desea eliminar el art%cculo? \"%s\" (si/no) : ",168,160,161,nombres[tipo][material][i]);
            preguntar:
            while (getchar() != '\n');
            scanf("%s",&resp);
            if(strcmp(resp,"si")==0){
                index=i;
                break;
            } else if (strcmp(resp,"no")==0){
                printf("\n%cDesea ingresar otro producto para eliminar? (si/no) : ",168);
                preguntar2:
                while (getchar() != '\n');
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
        while (getchar() != '\n');
        scanf("%s",&resp);
        if(strcmp(resp,"si")==0){
            goto reinicio;
        } else if (strcmp(resp,"no")!=0) {
            printf("\nIngrese una respuesta v%clida : ",160);
            goto pregunta3;
        }
    }
    end:
    strcpy(buscar,x);
    return buscar;
}

char* reordenarNombre (int tipo, int material, int i,char nombres[][2][11][20]){
    strcpy(nombres[tipo][material][i],nombres[tipo][material][i+1]);
    return nombres[tipo][material][i];
}

float reordenarDatos(int tipo, int material, int i,float datos[][2][10][2],int j){
    datos[tipo][material][i][j] = datos[tipo][material][i+1][j];
    return datos[tipo][material][i][j];
}

void imprimirTabla(char nombres [][2][11][20], char vacio[], float datos [][2][10][2]){
    printf("\t\t\t\t\t\tINVENTARIO\n\n");
        if (strcmp(nombres[0][0][0],vacio)==0 && strcmp(nombres[0][1][0],vacio)==0 && strcmp(nombres[1][0][0],vacio)==0 && strcmp(nombres[1][1][0],vacio)==0 && strcmp(nombres[2][0][0],vacio)==0 && strcmp(nombres[2][1][0],vacio)==0)
        {
            printf("\n\nEl inventario est%c vac%co",160,161);
        } else {
            printf("PRODUCTO\t\tMATERIAL\t\tNOMBRE\t\t\tCANTIDAD\t\tPRECIO");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    for (int k = 0; k < 10; k++)
                    {
                        if (strcmp(nombres[i][j][k],vacio)!=0)
                        {
                            if (i==0)
                            {
                                printf("\nCollar\t\t\t");
                            } else if(i==1){
                                printf("\nPulsera\t\t\t");
                            } else {
                                printf("\nAnillo\t\t\t");
                            }
                            if (j==0)
                            {
                                printf("Oro\t\t\t");
                            } else {
                                printf("Plata\t\t\t");
                            }
                            printf("%s\t\t\t",nombres[i][j][k]);
                            for (int l = 0; l < 2; l++)
                            {

                                if (l==1)
                                {
                                    printf("$");
                                    printf("%.2f\t\t\t",datos[i][j][k][l]);
                                } else {
                                    printf("%.0f\t\t\t",datos[i][j][k][l]);
                                }
                            }
                        }
                    }
                }
            }
        }
    printf("\n");
}

int comprobarVacio (int tipo, int material, char nombres[][2][11][20],char vacio[]){
    int cont,index=-1;
    for (int i = 0; i < 11; i++)
    {
        cont=0;
        if (strcmp(nombres[tipo][material][i],vacio)!=0)
        {
            cont=1;
            //printf("LLENO\n");
        } else {
            index=i;
            //printf("VACIO\n");
            break;
        }
    }
    //printf("INDEX = %i",index);
    return index;
}

char* vaciarStr (char str[][2][11][20]){
    memset(str[3][2][11],0,sizeof(str[3][2][11]));
    return str[3][2][0];
}

char* salir (char resp[10]){
        char  x[10];
        printf("%cEst%c seguro de salir? (si/no) : ",168,160);
        while (getchar() != '\n');
        scanf("%s",&x);
        while (strcmp(x,"si")!=0 && strcmp(x,"no")!=0)
        {
            printf("\nIngrese una respuesta v%clida",160);
            while (getchar() != '\n');
            scanf("%s",&x);
        }
        //printf("%s",x);
        strcpy(resp,x);
        return resp;
}

void noValido (){
    printf("\nIngrese una respuesta valida\n");
}