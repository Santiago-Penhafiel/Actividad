#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

int main (){
    float datos[100][2]={};
    int opc, num, index,indexFinal=-1,comp=5;
    char nombres[100][20]={}, buscar[20]={},vacio[20]={},resp[10];

    inf ();
    menu:
    opc=menu();

    switch (opc)
    {
    case 1: //añadir
        num=numObjAñadir(indexFinal);
        //printf("ITERACIONES : %i\n",num);
        for (int i = 0; i < num; i++)//for itera cuantas veces se le pida
        {
            index=comprobarVacio(nombres,vacio);//busca cadenas vacias
            repetir:
            //printf("index : %i\niteracion : %i\n",index,i);
            strcpy(nombres[index],añadirNombre(index,nombres));
            //printf("NOMBRES INDEX : %s\n",nombres[index]);
            comp=comprobarReplicas(nombres,index);//mira los duplicados
            if (comp==0)
            {
                goto repetir;
            } else if (comp==1) {
                strcpy(nombres[index],vaciarStr(index,nombres));
                continue;
                }
                //goto añadir;
            datos[index][0]=añadirDatos(0,index,nombres);
            datos[index][1]=añadirDatos(1,index,nombres);
            indexFinal=index;
            printf("\nINDEX FINAL : %i\n",indexFinal);
            //añadir:
            //printf("%s\n",nombres[index]); // imprimir nombre ingresado
        }
        
        goto menu; //reinicio
        break;
    
    case 2: //editar
        index=indexEditar(nombres);
        //printf("%i\n",index);
            if (index!=-1)//si el producto a editar existe:
            {
                strcpy(nombres[index],editarNombre(index,nombres,datos));
                datos[index][0]=editarCantidad(index,datos);
                datos[index][1]=editarCantidad(index,datos);
            }
        goto menu;

        break;
    
    case 3:// eliminar
        int inicio;
        index = indexEliminar (nombres);{
        }
        if (index!=-1)
        {
            strcpy(nombres[index],vaciarStr(index,nombres));
            for (int i = 0; i < 2; i++) {datos[index][i]=0;}
        }
    
        inicio = comprobarVacio(nombres,vacio);
        //printf("INICIO : %i\nFINAL : %i\n",inicio,indexFinal);
        for (int i = inicio; i < indexFinal; i++)
        {
            //printf("VUELTA %i\n",i+1);
            strcpy(nombres[i],reordenarNombre(i,nombres));
            printf("NOMBRE%i : %s\n",i,nombres[i]);
            for (int j = 0; j < 2; j++) {datos[i][j] = reordenarDatos(i,datos,j);}            
        }
        if (inicio!=indexFinal){
            strcpy(nombres[indexFinal] , vaciarStr(indexFinal,nombres));
        }
        for (int i = 0; i < 2; i++) {datos[indexFinal][i]=0;}
        
        indexFinal = index - 1;

        goto menu;

        break;

    case 4:
        imprimirTabla(nombres,vacio,datos);   
        goto menu;
        
        break;

    case 5:
        strcpy(resp,salir(resp));
        if (strcmp(resp,"no")==0)
        {
            goto menu;
        }

        break;

    default:
        noValido ();
        goto menu;

        break;

    }
    return 0;
}