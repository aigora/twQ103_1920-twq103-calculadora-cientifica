#include<stdio.h>
#include<string.h>
#include<math.h>

//Menu del trabajo
int main()
{	
	//Parte de MATRICES
		int filas, columnas, filas1,columnas1,filas2,columnas2,filas3,columnas3;
		int i,j; //contadores
		int operacion;
		int m1[filas][columnas],m2[filas][columnas],m3[filas][columnas];
		//multiplicacion
		float MatrizM1[filas1][columnas1],MatrizM2[filas2][columnas2],MatrizM3[filas3][columnas3];
		int k,L;
		float sum;
	//FIN DE PARTE DE MATRICES
	 
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
				
					
					printf("(Tenga en cuenta que tiene que ser de las mismas dimensiones para todas las operaciones excepto para la multiplicacion)\n");
					
	
 					do
 					{						
 					printf("Introduzca el tipo de operacion: suma(1), resta(2) o multiplicacion (3) \n");
 					scanf("%d", &operacion);
 					
					switch(operacion)
 					{
					
					case 1:
						printf("Introduzca numero de filas y columnas: \n");
						scanf("%d %d", &filas, &columnas);
						printf("Introduza los elementos de las matrices:\n"); 
						//Matriz 1
						for(i=0; i<filas; i++)
 						{	
 							for(j=0; j<columnas; j++)
 							{
								printf("Introduce elemento de la matriz1[%d][%d]\n", i+1, j+1);
								scanf("%d", &m1[i][j]);
							}
						}
						printf("\n");
						
						//Matriz 2
						for(i=0; i<filas; i++)
 						{	
 							for(j=0; j<columnas; j++)
 							{
								printf("Introduce elemento de la matriz1[%d][%d]\n", i+1, j+1);
								scanf("%d", &m2[i][j]);
							}
						}
						//Matriz Resultado
						for(i=0; i<filas; i++)
 						{	
 							for(j=0; j<columnas; j++)
 							{
								m3[i][j]= m1[i][j] + m2[i][j];
							}
						}
						for(i=0; i<filas; i++)
 						{	
 							for(j=0; j<columnas; j++)
 							{								
								printf(" %d",m3[i][j]);
							}
							printf("\n");
						}
						
					
						break;		
 						
					case 2:
					
						for(i=0; i<filas; i++)
 						{
 							for(j=0; j<columnas; j++)
 							{
								m3[i][j]= m2[i][j]-m1[i][j];
								printf("Matriz Resultado [%d][%d]=%f\n", i+1, j+1, m3[i][j]);
							}
						}
						break;		
					
		
					case 3:
							
						printf("Para la siguiente operacion se requiere que numero de columnas de matriz 1= numero de filas de matriz 2.\n");
						printf("Se requiere que imprima los datos otra vez:\n");
						printf("Introduzca numero de filas y columnas de la matriz 1: \n");
						scanf("%d %d", &filas1, &columnas1);
						printf("Introduzca numero de filas y columnas de la matriz 2: \n");
						scanf("%d %d", &filas2, &columnas2);
			
						if(columnas1==filas2)
						{
							columnas1=filas2;
							filas2=k;
			 
						 //MatrizM1
							for(i=0; i<filas1; i++)
 							{
 								for(j=0; j<columnas1; j++)
 								{
									printf("Introduce matriz[%d][%d]\n", i+1, j+1);
									scanf("%f", &MatrizM1[i][j]);
								}
							}
						//MatrizM2	
							for(i=0; i<filas2; i++)
 							{
 								for(j=0; j<columnas2; j++)
 								{
									printf("Introduce matriz[%d][%d]\n", i+1, j+1);
									scanf("%f", &MatrizM2[i][j]);
								}
							}
						//Multiplicacion
							for(i=0; i<filas2; i++)
 							{
 								for(j=0; j<columnas1; j++)
 								{
					 				sum=0;
 									for(L=0; L<k; L++)
 									{
 										sum+=MatrizM1[i][L]*MatrizM2[L][j];
 									}
					
								MatrizM3[i][j]= sum;
								}
 							}
			
						//Mostramos resultado
							for(i=0; i<filas1; i++)
 							{
 								for(j=0; j<columnas2; j++)
 								{
									printf("%f \t ", MatrizM3[i][j]);
								}
								printf("\n");
							}
						}	
						else
						{
							printf("ERROR: *requisito no cumplido*.");
						}	
					
					break;				
					}
 		
 					
 					}
				while(filas>100 || columnas>100);	
				
				break;
				
				
				case 4:printf("Constantes numericas\n");	
				break;
			
				case 5: printf("Tabla Periodica\n");
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
