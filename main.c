#include <stdio.h>
#include <conio.h>
#include <string.h>

int comprobar (int num,char arreglo[][20]);//verificar array vacio

int main (){
    float datos[100][2];
    int opc, num,cont;
    char nombres[100][20]={};

printf("------------Inventario de objetos------------ \n(Este inventario tiene hasta un máximo de 100 productos para ingresar)\n");
inicio:
printf("\t\tMENU \n1 Para ingresar nuevos objetos \n2 Para editar los objetos \n3 Para eliminar los objetos \n4 Para ver la lista de objetos \n5 Para salir\n");
    scanf("%d",&opc);
    switch (opc)
    {
    case 1:
        cont=0;
        printf("Cuantos objetos desea ingresar : ");
        scanf("%i",&num);
        while (num<=0 || num>=100)
        {
            printf("\nIngrese un numero valido : ");
            scanf("%i",&num);
        }
        
        for (int i = 0; i < num; i++)
        {
            //printf("Vuelta\n");
            if (comprobar(cont,nombres)==0){
                printf("Ingrese el nombre del producto %i\n",cont+1);
                scanf("%s",&nombres[cont]);
                for (int j = 0; j < 2; j++)
                {
                    if (j==0)
                    {
                        printf("Ingrese la cantidad de productos de %s : ",nombres[cont]);
                    } else {
                        printf("Ingrese el precio del producto %s : ",nombres[cont]);
                    }    
                    scanf("%f",&datos[cont][j]);
                }
            } else {
                i--;
            }
            cont++;
        }
        goto inicio; //reinicio
        break;
    
    case 2:
        editar:
        printf("Que numero de producto desea modificar : ");
        scanf("%i",&num);
        num--;
        if (comprobar(num,nombres)==0)
        {
            printf("El producto que desea modificar no existe, por favor vuelva a intentar con un numero diferente\n");
            goto editar;
        } else {
            printf("Nombre\tCantidad\tPrecio\n%s\t%f\t%f\n",nombres[num],datos[num][0],datos[num][1]);
            printf("Nuevo nombre : ");
            scanf("%s",&nombres[num]);
            printf("\nNueva cantidad : ");
            scanf("%f",&datos[num][0]);
            printf("\nNuevo precio : ");
            scanf("%f",&datos[num][1]);
        }
        
        
        goto inicio;

        break;
    
    default:
        break;
    }

    getch();

    return 0;
}



int comprobar (int num,char arreglo[][20]){
    int c=0;
    for (int i = 0; i < 20; i++)
    {
        if ((arreglo[num][i]) != '\0'){
            c++;
            //printf("LLENO\n");
        } else {
        //printf("VACIO\n");
        }
    }
    return c;
}