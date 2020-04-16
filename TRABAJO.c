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
		struct TElemento tabla[200];
		int contador,N;
		int option,option2a,option2b,option3, option3a,option3b;
		FILE *pfentrada;
		char nomBuscado[20], simBuscado[4];
		int numBuscado;
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
			
/*TABLA*/		case 5: printf("Tabla Periodica\n");
					{
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
				
										pfentrada=fopen("tabla.txt","a");	
										//pido los datos al usuario sobre los elementos
										for(i=0;i<N;i++)
										{
											printf("Introduzca los datos del elmento:\n \n");
											printf("Introduzca el nombre: \t");
											scanf("%s", tabla[i].nombre);	
											fflush(stdin);
											printf("Introduzca el simbolo: \t");
											scanf("%s", tabla[i].simbolo);	
											fflush(stdin);
											printf("Introduzca el numero atomico: \t");
											scanf("%i", &tabla[i].nAtomico);	
											fflush(stdin);
				
											printf("Introduzca el peso: \t");
											scanf("%f", &tabla[i].masa);	
											fflush(stdin);
				
										}
									//imprimo los datos en el fichero
									//Estructura ejemplo
									printf(pfentrada," Nombre\n");
									printf(pfentrada,"\t  Simbolo \n");
									printf(pfentrada,"\t  Numero Atomico \n");
									printf(pfentrada,"\t  Masa molecular \n", tabla[i].masa);
									printf(pfentrada,"\n");
									for(i=0;i<N;i++)
									{
										fprintf(pfentrada,"%s \n", tabla[i].nombre);
										fprintf(pfentrada,"\t  %s \n", tabla[i].simbolo);
										fprintf(pfentrada,"\t  %d \n", tabla[i].nAtomico);
										fprintf(pfentrada,"\t  %.2f \n", tabla[i].masa);
										fprintf(pfentrada,"\n");
									}
									fclose(pfentrada);
									printf("Desea repetir la operacion? 1.-Si\t 2.-No\n");
									scanf("%d",&option2b);
								
									}
									while(option2b!=2);
								}
								else
								{
									return 0;
								}
							break;
							}
		
		
							case 2:  //Mostrar tabla
							{
								pfentrada=fopen("tabla.txt","r");
				
								if(pfentrada== NULL)
								{
									printf("No se ha encontrado un fichero con ese nombre.\n");
									return 0;
								}			
		
								contador=0;
								j=0;
								while(fscanf(pfentrada,"%s %s %d %f", tabla[j].nombre, tabla[j].simbolo, &tabla[j].nAtomico, &tabla[j].masa)!=EOF)
								{
									j++;
									contador++;
								}
								
								fclose(pfentrada);
								for(j=0;j<contador;j++)
								{				
									printf("%s\n", tabla[j].nombre);
									printf("\t %s\n", tabla[j].simbolo);
									printf("\t %d\n", tabla[j].nAtomico);
									printf("\t%.2f\n", tabla[j].masa);
								}
					
							break;	
							}
		
							case 3: //Buscar el Elemento
							{	
								printf("Usted ha seleccionado Buscar ELmento.\n Quieres salir de esta opcion? \n 1.-Si\t 2.-No\n");
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
												pfentrada=fopen("tabla.txt","r");
			
												if(pfentrada== NULL)
												{
													printf("No se ha encontrado un fichero con ese nombre.\n");
													return 0;
												}	
							
												printf("Introduzca el nombre del elemento:\n ");
												scanf("%s",nomBuscado);
												for (i=0; i<200; i++)
												{
        											if (strcmp(tabla[i].nombre, nomBuscado) == 0) 
													{
        			    								printf("Nombre:  %s \n Simbolo:  %s\n Numero Atomico: %d\n Masa Atomica: %.2f\n", tabla[i].nombre, tabla[i].simbolo, tabla[i].nAtomico, tabla[i].masa);
													}
													else
													{
														printf("Error 404. Element Not Found. Code: PFO");
													}		
												}
												fclose(pfentrada);
            								break;
        									}//final del case 1 del switch anidado
				
											case 2: //Buscamos por Simbolo usanndo strcomp
											{
												//Abrimos el fichero donde esta la tabla
												pfentrada=fopen("tabla.txt","r");
		
												if(pfentrada== NULL)
												{
													printf("No se ha encontrado un fichero con ese nombre.\n");
													return 0;
												}	
					
												printf("Introduzca el simbolo del elemento:\n ");
												scanf("%s",simBuscado);
												
												for (i=0; i<200; i++)
												{
        											if (strcmp(tabla[i].simbolo, simBuscado) == 0) 
													{
        				    							printf("Nombre:%s \n Simbolo:%s\n Numero Atomico: %d\n Masa Atomica: %.2f\n", tabla[i].nombre, tabla[i].simbolo, tabla[i].nAtomico, tabla[i].masa);
													}
													else
													{
														printf("Error 404. Element Not Found. Code: PFO");
													}
												}
												fclose(pfentrada);	
											break;	
											}//final del case 2 del switch anidado
					
				
											case 3: //Buscamos por numero atomico
											{
											//Abrimos el fichero donde esta la tabla
												pfentrada=fopen("tabla.txt","r");
												if(pfentrada== NULL)
												{
													printf("No se ha encontrado un fichero con ese nombre.\n");
													return 0;
												}	
					
												printf("Introduzca el numero atomico del elemento:\n ");
												scanf("%d",numBuscado);
								
												for (i=0; i<200; i++)
												{
    				    							if (tabla[i].nAtomico== numBuscado) 
													{
        					    						printf("Nombre:%s \n Simbolo:%s\n Numero Atomico: %d\n Masa Atomica: %.2f\n", tabla[i].nombre, tabla[i].simbolo, tabla[i].nAtomico, tabla[i].masa);
													}
													else
													{
														printf("Error 404. Element Not Found. Code: PFO");
													}
												}
												fclose(pfentrada);
						
											break;		
											}//Final del case 3 del switch anidado
					
										}//Final del switch anidado
										printf("Desea repetir la operacion? 1.-Si\t 2.-No\n");
										scanf("%d",&option3b);
									}//Final del do
									while(option3b!=1);
								} //Final del if que engloba el do-while
								else
								{
									printf("Que tenga un buen dia.\n Apagando Calculadora...");
								}
		
								break;	
							}//Final del case 3
			
							case 4:
								printf("Que tenga un buen dia.\n Apagando Calculadora...");
							break;
						}	
					
						break;
					}
					
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
