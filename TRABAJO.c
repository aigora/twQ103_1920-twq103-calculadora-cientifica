#include<stdio.h>
#include<string.h>
#include<math.h>

struct TElemento 
{
	char nombre[20];
	char simbolo[4];
	int nAtomico;
	float masa;
};
int feof (FILE *pfentrada);//Para la Tabla
//Menu del trabajo
int main()
{	

	//Parte de TABLA
	
	//FIN DE PARTE DE TABLA
	 
	int option=0;
	
	do
	{	
		printf("Elija una opcion: \n 0-Apagar Sistema\n 1-Operaciones Basicas\n 2-Operaciones con Vectores\n 3-Operaciones con Matrices\n 4-Constantes numericas\n 5-Tabla Periodica\n 6-Sistemas de ecuaciones\n 7-Operaciones complejas\n\n");
		scanf("%d",&option);
	if((option<0)||(option>7))
		{
			printf("Error 404 Not Found");
		}
	else
		{
			switch(option)
			{
				case 0: printf("Apagando calculadora.\n");
				break;
			
				case 1: printf("Operaciones Basicas\n");
				break;
				case 2: printf("Operaciones con Vectores\n");
				break;
				case 3: printf("Operaciones con Matrices\n");
				
				
				
				case 4:printf("Constantes numericas\n");	
				break;
			
/*TABLA*/		case 5: printf("Tabla Periodica\n");
				break;
		
				case 6: printf("Sistemas de ecuaciones\n");
				break;
				
				case 7: printf("Operaciones complejas\n");
				break;
			}
		}
	}
	while(option!=0);
	
	return 0;
}
