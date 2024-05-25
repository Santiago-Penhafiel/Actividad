#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"

int main (){
    float datos[100][2];
    int opc, num, index,comp=5;
    char nombres[100][20]={}, buscar[20]={},vacio[20]={};

    inf ();
    menu:
    opc=menu();

    switch (opc)
    {
    case 1: //añadir
        num=numObjAñadir();
        for (int i = 0; i < num; i++)//for itera cuantas veces se le pida
        {
            index=comprobarVacio(nombres,vacio);//busca cadenas vacias
            //printf("index : %i\n",index);
            repetir:
            strcpy(nombres[index],añadirNombre(index,nombres));
            //printf("NOMBRES INDEX : %s\n",nombres[index]);
            comp=comprobarReplicas(nombres,index);//mira los duplicados
            if (comp==0)
            {
                goto repetir;
            } else if (comp==1) {
                strcpy(nombres[index],vaciarStr(index,nombres));
                continue;
                //goto añadir;
            } 
            datos[index][0]=añadirDatos(0,index,nombres);
            datos[index][1]=añadirDatos(1,index,nombres);
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
        index = indexEliminar (nombres);
        (index!=-1)?(strcpy(nombres[index],vaciarStr(index,nombres))):(0);
        goto menu;

        break;

    case 4:
        imprimirTabla(nombres,vacio,datos);   
        goto menu;
        
        break;
    
    default:
        break;
    }
    getch();

    return 0;
}