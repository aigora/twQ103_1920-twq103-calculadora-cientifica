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
int main(){
			//Para la Tabla
		struct TElemento tabla[200];
		int contador,N;
		int option,option2a,option2b,option3, option3a,option3b;
		FILE *pfentrada;
		char nomBuscado[20], simBuscado[4];
		int numBuscado=0;
		int i,j;
			
	printf("Que desea hacer?\n 1.-Registrar Elementos \n 2.-Mostrar tabla\n 3.-Buscar elemento\n 4.-Apagar Calculadora (Ir al menu)\n");
	scanf("%d",&option);
	
	switch (option)
	{
	case 1 : //Registramos elementos
	{
		printf("Has elegido registrar elementos.\n");
		printf("\n Quieres salir de esta opcion? 1.-Si\t 2.-No\n");
		scanf("%d",&option2a);
	
		if(option2a==2)
		{
			do
			{	
				printf("Cuantos elementos quiere registrar?\n");
				scanf("%d",&N);
	
				pfentrada=fopen("tabla1.txt","w");	
				//pido los datos al usuario sobre los elementos
				for(i=0;i<N;i++)
				{
					printf("Introduzca los datos del elmento:\n \n");
					
					printf("Introduzca el nombre: \t");
					scanf("%s", tabla[i].nombre);
					fprintf(pfentrada,"%s\t", tabla[i].nombre);	
					fflush(stdin);
					
					printf("Introduzca el simbolo: \t");
					scanf("%s", tabla[i].simbolo);	
					fprintf(pfentrada,"\t  %s ", tabla[i].simbolo);
					fflush(stdin);
					
					printf("Introduzca el numero atomico: \t");
					scanf("%i", &tabla[i].nAtomico);
					fprintf(pfentrada,"\t  %d ", tabla[i].nAtomico);	
					fflush(stdin);
	
					printf("Introduzca el peso: \t");
					scanf("%f", &tabla[i].masa);
					fprintf(pfentrada,"\t  %.2f \n", tabla[i].masa);
					
					printf("Desea repetir la operacion? 1.-Si\t 2.-No\n");	
					fflush(stdin);
				}			
			fclose(pfentrada);
			}
			while(option2a!=2);
		}
		else
		{
			return 0;
		}
	break;
	}
	
	case 2:  //Mostrar tabla
	{
		pfentrada=fopen("tabla1.txt","r");
	
		if(pfentrada== NULL)
		{
			printf("No se ha encontrado un fichero con ese nombre.\n");
			return 0;
		}			
		contador=0;
		j=0;
		printf("Nombre \t\t Simbolo\t Numero Atomico\t Masa atomica\n");
		while(fscanf(pfentrada,"%s %s %d %f", tabla[j].nombre, tabla[j].simbolo, &tabla[j].nAtomico, &tabla[j].masa)!=EOF)
		{
			printf("%s\t\t %s\t\t %d\t\t %f\n", tabla[j].nombre,tabla[j].simbolo,tabla[j].nAtomico,tabla[j].masa);
			j++;
			contador++;
		}
		printf("Lineas: %d\n",contador);

	fclose(pfentrada);
	break;	
	}
	
	case 3: //Buscar el Elemento
	{	
		printf("Usted ha seleccionado Buscar Elemento.\n Quieres salir de esta opcion? \n 1.-Si\t 2.-No\n");
		scanf("%d",&option3);
		if(option3==2)
		{
			do
			{
				printf("Desea buscar un elemento por: 1.-Nombre 2.-Simbolo 3.-Numero Atomico ?\n");
				scanf("%d",&option3a);							
				switch (option3a)															
				{
					case 1: //Buscamos por nombre usando strcomp
					{
						//Abrimos el fichero donde esta la tabla
						pfentrada=fopen("tabla1.txt","r");
	
						if(pfentrada== NULL)
						{
							printf("No se ha encontrado un fichero con ese nombre.\n");
							return 0;
						}	
						contador = 0;
							while(fscanf(pfentrada,"%s %s %d %f", tabla[j].nombre, tabla[j].simbolo, &tabla[j].nAtomico, &tabla[j].masa)!=EOF)
							{
								j++;
								contador++;
							} // con esta funcion se determina cuantas lineas hay escritas en el archivo
						printf("Introduzca el nombre del elemento:\n ");
						scanf("%s",nomBuscado);
						for (i=0; i<contador; i++)
						{
							if (strcmp(tabla[i].nombre, nomBuscado) == 0) //si el nombre introducido coincide con alguno ya escrito, se imprimen todas sus caracteristicas
							{
								printf("Nombre \t\t Simbolo\t Numero Atomico\t Masa atomica\n");
								printf("%s\t\t %s\t\t %d\t\t %f\n", tabla[i].nombre,tabla[i].simbolo,tabla[i].nAtomico,tabla[i].masa);
								break;
							}
							else
							{
								printf("Error 404. Element Not Found. Code: PFO\n");
							}		
						}
						fclose(pfentrada);
					break;
					}
	
					case 2: 
					{
					pfentrada=fopen("tabla1.txt","r");
	
						if(pfentrada== NULL)
						{
							printf("No se ha encontrado un fichero con ese nombre.\n");
							return 0;
						}	
						contador = 0;
							while(fscanf(pfentrada,"%s %s %d %f", tabla[j].nombre, tabla[j].simbolo, &tabla[j].nAtomico, &tabla[j].masa)!=EOF)
							{
								j++;
								contador++;
							}
						printf("Introduzca el simbolo del elemento:\n ");
						scanf("%s",simBuscado);
						for (i=0; i<contador; i++)
						{
							if (strcmp(tabla[i].simbolo, simBuscado) == 0) 
							{
								printf("Nombre \t\t Simbolo\t Numero Atomico\t Masa atomica\n");
								printf("%s\t\t %s\t\t %d\t\t %f\n", tabla[i].nombre,tabla[i].simbolo,tabla[i].nAtomico,tabla[i].masa);
								break;
							}
							else
							{
								printf("Error 404. Element Not Found. Code: PFO\n");
							}		
						}
						fclose(pfentrada);
					break;
					}
	
	
					case 3: //Buscamos por numero atomico
					{
					pfentrada=fopen("tabla1.txt","r");
	
						if(pfentrada== NULL)
						{
							printf("No se ha encontrado un fichero con ese nombre.\n");
							return 0;
						}	
							contador = 0;
							while(fscanf(pfentrada,"%s %s %d %f", tabla[j].nombre, tabla[j].simbolo, &tabla[j].nAtomico, &tabla[j].masa)!=EOF)
							{
								j++;
								contador++;
							}
							printf("Lineas: %d",contador);
						printf("Introduzca el numero atomico del elemento:\n ");
						scanf("%d",&numBuscado);
						for (i=0; i<contador; i++)
						{
							if (numBuscado==tabla[i].nAtomico) 
							{	
								
								printf("Nombre \t\t Simbolo\t Numero Atomico\t Masa atomica\n");
								printf("%s\t\t %s\t\t %d\t\t %.2f\n", tabla[i].nombre,tabla[i].simbolo,tabla[i].nAtomico,tabla[i].masa);
								break;
							}
						}	
						 if(numBuscado!=tabla[i].nAtomico)
							{
							printf("No hay elementos con ese valor");
						
							}		
						
						fclose(pfentrada);
					break;
					}
	
				}
				printf("Desea repetir la operacion? 1.-Si\t 2.-No\n");
				scanf("%d",&option3b);
			}
			while(option3b!=1);
		} 
		else
		{
			printf("Que tenga un buen dia.\n Apagando Calculadora...");
		}
	
		break;	
	}
	
	case 4:
		printf("Que tenga un buen dia.\n Apagando Calculadora...");
	break;
	}	

}
