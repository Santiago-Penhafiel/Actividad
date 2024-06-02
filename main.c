#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (){
    float datos[3][2][10][2]={};
    int opc, num, index,indexFinal=-1,comp=5,tipo,material;
    char nombres[3][2][11][20]={},buscar[20]={},vacio[20]={},resp[20]={};

    inf ();
    menu:
    opc=menu();

    switch (opc)
    {
    case 1: //añadir
        añadir();
        tipo = obtenerTipo() - 1;
        material = obtenerMaterial() - 1;
        indexFinal = comprobarVacio(tipo,material,nombres,vacio) - 1;
        //printf("INDEX FINAL 1 : %i\n",indexFinal);
        num = numObjAñadir(indexFinal);
        if (num!=-1)
        {
            //printf("ITERACIONES : %i\n",num);
        for (int i = 0; i < num; i++)//for itera cuantas veces se le pida
            {
                index=comprobarVacio(tipo,material,nombres,vacio);//busca cadenas vacias
                repetir:
                //printf("index : %i\niteracion : %i\n",index,i);
                strcpy(nombres[tipo][material][index],añadirNombre(tipo,material,index,nombres));
                //printf("NOMBRES INDEX : %s\n",nombres[tipo][material][index]);
                comp=comprobarReplicas(tipo,material,nombres,index);//mira los duplicados
                if (comp==0)
                {
                    goto repetir;
                } else if (comp==1) {
                    strcpy(nombres[tipo][material][index],vacio);
                    continue;
                    }
                    //goto añadir;
                datos[tipo][material][index][0]=añadirDatos(0,index,nombres,tipo,material);
                datos[tipo][material][index][1]=añadirDatos(1,index,nombres,tipo,material);
                indexFinal = comprobarVacio(tipo,material,nombres,vacio) - 1;
                //printf("Index final : %i\n",indexFinal);
                //printf("\nINDEX FINAL : %i\n",indexFinal);
                //añadir:
                //printf("%s\n",nombres[index]); // imprimir nombre ingresado
            }
        }
        
        goto menu; //reinicio
        break;
    
    case 2: //editar
        index=-1;
        editar();
        tipo = obtenerTipo() - 1;
        material = obtenerMaterial() - 1;
        //printf("TIPO : %i MATERIAL : %i\n",tipo,material);
        strcpy(buscar,nombreAEditar(tipo,material,nombres,buscar));
        //printf("BUSCAR : %s\n",buscar);
        index = buscarIndex(tipo,material,buscar,nombres);
        //index=indexEditar(nombres);
        //printf("%i\n",index);
            if (index!=-1)//si el producto a editar existe:
            {
                tablaEditar(tipo,material,index,nombres,datos);
                opc = opcEditar();
                if (opc==1)
                {
                    strcpy(nombres[tipo][material][index],editarNombre(tipo,material,index,nombres,datos));

                } else if(opc==2){
                    datos[tipo][material][index][0]=editarCantidad();
                } else {
                    datos[tipo][material][index][1]=editarPrecio();
                }
            }
        goto menu;

        break;
    
    case 3:// eliminar
        index=-1;
        eliminar();
        int inicio;
        tipo = obtenerTipo() - 1;
        material = obtenerMaterial() - 1;
        strcpy(buscar,nombreAEliminar(tipo,material,buscar,nombres,vacio));
        //printf("BUSCAR : %s\n",buscar);
        index = buscarIndex(tipo,material,buscar,nombres);
        indexFinal = comprobarVacio(tipo,material,nombres,vacio) - 1;
        //printf("INDEX : %i\nINDEX FINAL : %i\n",index,indexFinal);
        
        if (index<=indexFinal)
            {
                strcpy(nombres[tipo][material][index],vacio);
                for (int i = 0; i < 2; i++) {datos[tipo][material][index][i]=0;}
            }
       inicio = comprobarVacio(tipo,material,nombres,vacio) ;
        //printf("INICIO : %i\nFINAL : %i\n",inicio,indexFinal);
        if (inicio<indexFinal){
            
            for (int i = inicio; i < indexFinal; i++)
            {
                //printf("VUELTA %i\n",i+1);
                strcpy(nombres[tipo][material][i],reordenarNombre(tipo,material,i,nombres));
                //printf("NOMBRE%i : %s\n",i,nombres[i]);
                for (int j = 0; j < 2; j++) {datos[tipo][material][i][j] = reordenarDatos(tipo,material,i,datos,j);}
            }
            strcpy(nombres[tipo][material][indexFinal] , vaciarStr(nombres));
            for (int i = 0; i < 2; i++) {datos[tipo][material][indexFinal][i]=0;}
        }

        goto menu;

        break;

    case 4:
        imprimirTabla(nombres,vacio,datos);   
        goto menu;
        
        break;

    case 5:
        case5:
        strcpy(resp,salir(resp));
        if (strcmp(resp,"no")==0)
        {
            goto menu;
        } else if (strcmp(resp,"si")!=0){
            printf("\nIngrese una respuesta v%clida : ",160);
            goto case5;
        }

        break;

    default:
        noValido ();
        goto menu;

        break;

    }
    return 0;
}