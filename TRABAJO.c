#include<stdio.h>
#include<string.h>
#include<math.h>

//Menu del trabajo
int main()
{
	char ;
	int option=0;
	
	do
	{	
		printf("Elija una opcion: 0-Apagar Sistema\n,1-Operaciones Basicas\n,2-Operaciones con Vectores\n,3-Constantes numericas\n,4-Tabla Periodica\n,5-Sistemas de ecuaciones\n,6-Operaciones complejas\n\n");
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
				case 3: printf("Constantes numericas\n");
				break;
				case 4: printf("Tabla Periodica\n");
				break;
				case 5: printf("Sistemas de ecuaciones\n");
				break;
				case 6: printf("Operaciones complejas\n");
				break;
			}
		}
	}
	while(option!=0);
	
	return 0;
}
