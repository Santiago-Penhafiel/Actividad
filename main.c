#include <stdio.h>
#include <conio.h>
#include <string.h>

int main (){
    float datos[100][2];
    int a, num,cont=0;
    char nombres[100][20];
    for (int i = 0; i < 100; i++)
    {
          nombres [i][0] = '-';  
    }
    
printf("------------Inventario de objetos------------ \n(Este inventario tiene hasta un máximo de 100 productos para ingresar)\n");
inicio:
printf("\t\tMENU \n1 Para ingresar nuevos objetos \n2 Para editar los objetos \n3 Para eliminar los objetos \n4 Para ver la lista de objetos \n5 Para salir\n");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        printf("Cuantos objetos desea ingresar : ");
        scanf("%i",&num);
        while (num<=0 || num>=100)
        {
            printf("\nIngrese un numero valido : ");
            scanf("%i",&num);
        }
        
        for (int i = 0; i < num; i++)
        {
            
            if (strcmp(nombres[cont],"-")==0){
                printf("Ingrese el nombre del producto %i\n",i+1);
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
        goto inicio;
        break;
    
    case 2:
        printf("Que numero de producto desea modificar : ");
        scanf("%i",&num);
        num--;
        printf("Nombre\tCantidad\tPrecio\n%s\t%f\t%f\n",nombres[num],datos[num][0],datos[num][1]);
        printf("Nuevo nombre : ");
        scanf("%s",&nombres[num]);
        printf("\nNueva cantidad : ");
        scanf("%f",&datos[num][0]);
        printf("\nNuevo precio");
        scanf("%f",&datos[num][1]);
        goto inicio;

        break;
    
    default:
        break;
    }

    getch();

    return 0;
}