#include <stdio.h>
#include<math.h>

int ConstantesNum();
struct TConstante 
{
	char nombre[50];
	char numero[50];
};
int main()
{
	ConstantesNum();
	return 0;
}
int ConstantesNum()
{
	int i,j;
	FILE *pfentrada;
	struct TConstante tabla[200];
	int option,option2,N=0;
	
	
		printf("Has elegido constantes numericas.\n");
		printf("\n Quieres salir de esta opcion? 1.-Si\t 2.-No\n");
		scanf("%d",&option2);


		if(option2==2)
		{
			do
			{	
				printf("Que desea hacer?\n 1.-Registrar Constantes \n 2.-Mostrar tabla\n");
				scanf("%d",&option);
	
				if(option==1)
				{    		
					printf("Cuantas constantes quiere registrar?\n");
					scanf("%d",&N);
					pfentrada=fopen("tabla2.txt","a");	
					//pido los datos al usuario sobre los elementos

					for(i=0;i<N;i++)
					{
						printf("Introduzca los datos de la constante:\n \n");
						printf("Introduzca el nombre: \t");
						scanf("%s", tabla[i].nombre);
						fprintf(pfentrada,"%s\t", tabla[i].nombre);	
						fflush(stdin);
					
						printf("Introduzca el numero: \t");
						scanf("%s", tabla[i].numero);	
						fprintf(pfentrada,"\t  %s ", tabla[i].numero);
						fflush(stdin);
				}			

			fclose(pfentrada);
			}
			else if(option==2)
			{
					pfentrada=fopen("tabla2.txt","r");
	
					if(pfentrada== NULL)
					{
						printf("No se ha encontrado un fichero con ese nombre.\n");
						return 0;
					}			
					
					j=0;
					printf("Nombre \t\t numero \n");
					while(fscanf(pfentrada,"%s %s", tabla[j].nombre, tabla[j].numero)!=EOF)
					{
						printf("%s\t\t %s\n", tabla[j].nombre,tabla[j].numero);
						j++;
						
					}
					fclose(pfentrada);
			}
			
			}
			while(option2<2|| option>1);
	}
	else
	{
		printf("Apagando...");
	}
}
