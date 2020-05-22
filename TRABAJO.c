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
struct TConstante 
{
	char nombre[50];
	float numero;
};

int operacionesVectores();
int operacionesMatrices();
int datosTablaPeriodica();
int operacionesBasicas();
int operacionesComplejas();
int operacionesIntegrales();
int sistemasEcuaciones();
int ConstantesNum();
	
	void PideDatos(int *Dim, float Sist[][102]);
	void EscribeDatos(int Dim, float Sist[][102]);
	void ResuelveGauss(int Dim, float Sist[][102]);
	

//Menu del trabajo
int main()
{		 
	int option=0;
	
	do
	{	
		printf("Elija una opcion: \n 0-Apagar Sistema\n 1-Operaciones Basicas\n 2-Operaciones con Vectores\n 3-Operaciones con Matrices\n 4-Constantes numericas\n 5-Tabla Periodica\n 6-Sistemas de ecuaciones\n 7-Operaciones complejas\n 8-Operaciones con integrales\n");
		scanf("%d",&option);
	if((option<0)||(option>8))
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
					operacionesBasicas();
				break;
			
				case 2: printf("Operaciones con Vectores\n");
					 operacionesVectores();
				break;
			
				case 3: printf("Operaciones con Matrices\n");
					operacionesMatrices();
				break;
			
				case 4:printf("Constantes numericas\n");
					 ConstantesNum();	
				break;
			
/*TABLA*/		case 5: printf("Tabla Periodica\n");
					datosTablaPeriodica();
				break;
					
				case 6: printf("Sistemas de ecuaciones\n");
				    sistemasEcuaciones();
				break;
				
				case 7: printf("Operaciones complejas\n");
					operacionesComplejas();
				break;
				
				case 8: printf("Operaciones con integrales");
					operacionesIntegrales();
				break;
					
			}
		}
	}
	while(option != 0);
	
	return 0;
}


int operacionesVectores(){
	
	int d;//determinar la dmension del vector
	float x,y,z; // coordenadas de los vectores
	int n;// switch de operaciones
	int i;// bucles for
	int op1=0;// primer bucle while
	float v1[d],v2[d],v3[d];//v1 y v2 son introducidos por teclado y v3 es el vector resultado
	float sum=0.0;
	float sumatorio1=0, resultado1=0,sumatorio2=0, resultado2=0;
	float angulo=0.0;
	do
	{
		
	
	//PRIMERO: Preguntar por la dimension del vector
	do {
		printf("Introduzca la dimension de los vectores:\n");
		scanf("%d",&d);
		
	}while(d<2 || d>3);
	//SEGUNDO: Introducir los elementos de cada vector
		//vector 1
		for(i=0; i<d; i++){
			
			printf("Introduzca el valor %d del vector 1: ",i+1);
			scanf("%f", &v1[i]);
		}
		//vector 2
		for(i=0; i<d; i++){
			printf("Introduzca el valor %d del vector 2: ",i+1);
			scanf("%f", &v2[i]);
		}

	//TERCERO: Elegir una operacion
		printf("Introduzca la operacion: \n1.Sumar\n2.Restar\n3.Producto vectorial\n4.Producto escalar\n5.Modulo\n6.Angulo\n");
		scanf("%d",&n);
		switch (n){
			case 1: //suma
				for(i=0;i<d;i++){
				v3[i]=  v1[i] + v2[i];
				printf("%.2f ",v3[i]);
				}
			break;
			
			case 2: //resta
				for(i=0;i<d;i++){
				v3[i]=  v1[i] - v2[i];
				printf("%.2f ",v3[i]);
				}
			break;
			
			case 3: //producto vectorial 
				if(d==3){
					x = v1[1]*v2[2] - v1[2]*v2[1];
					y = v1[0]*v2[2] - v1[2]*v2[0];
					z = v1[0]*v2[1] - v1[1]*v2[0];
					printf("%.2f %.2f %.2f",x,y,z);
				}else if(d == 2){
					z = v1[0]*v2[1] - v1[1]*v2[0];
					printf("%.2f k",z);// el vector resultante sale del plano en el que estan v1 y v2
				}				
			break;		
				
			case 4: //producto escalar
			for(i=0;i<d;i++)
				{
				sum +=  v1[i] * v2[i];
				}
				printf("Resultado = %.2f",sum);
			break;
			
			case 5: //modulo = raiz cuadrada (x^2 + y^2 + z^2) 
				for(i=0; i<d; i++){
					sumatorio1 += pow(v1[i],2);
				}
				resultado1 = sqrt(sumatorio1);
				for(i=0; i<d; i++){
					sumatorio2 += pow(v2[i],2);
				}
				resultado2 = sqrt(sumatorio2);
				printf("Modulo v1 = %.2f\n",resultado1);
				printf("Modulo v2 = %.2f",resultado2);
			break;
			
			case 6: 							//cos (A) = producto escalar / (modulo_v1 * modulo_v2)
				for(i=0;i<d;i++)				//producto escalar
				{
				sum +=  v1[i] * v2[i];
				}
				for(i=0; i<d; i++){				//modulo v1	
					sumatorio1 += pow(v1[i],2);
				}
				resultado1 = sqrt(sumatorio1);
				for(i=0; i<d; i++){				//modulo v2
					sumatorio2 += pow(v2[i],2);
				}
				resultado2 = sqrt(sumatorio2);
				//ahora se halla el arcos del angulo
				angulo = acos(sum / sqrt(sumatorio1 * sumatorio2));//tener en cuenta que nos el resultado en radianes
				printf("Angulo = %.2f grados",angulo*(180.000000)/3.141592);
				break;
		}while(n>5 || n<0);
		
		
		printf("\nQuieres salir?\n 1.Si\n 2.No\n");
	scanf("%d",&op1);
	} while (op1==2);
	printf("\nHasta pronto...\n\n");
		
}

int operacionesMatrices(){
	
	int i,j, op1=0;
	int filas1=0,filas2=0,filas3=0,columnas1=0,columnas2=0,columnas3=0;
	float m1[100][100],m2[100][100],m3[100][100],aux;
	int a,contador;
	
	do{
		
	
	do{
		printf("Introduzca las filas y columans de la matriz1\n");
		scanf("%d",&filas1);
		scanf("%d",&columnas1);
	}while(filas1<1 || columnas1<1);
	
	for(i=0; i<filas1; i++)
	{
		for(j=0; j<columnas1; j++)
		{
			printf("Introduce elemento de la matriz1[%d][%d]\n", i+1, j+1);
			scanf("%f", &m1[i][j]);
		}
	}
	do{
		printf("Introduzca las filas y columans de la matriz2\n");
		scanf("%d",&filas2);
		scanf("%d",&columnas2);
	}while(filas2<1 || columnas2<1);
	
	for(i=0; i<filas2; i++)
	{
		for(j=0; j<columnas2; j++)
		{
			printf("Introduce elemento de la matriz2[%d][%d]\n", i+1, j+1);
			scanf("%f", &m2[i][j]);
		}
	}
	
	printf("Que desea hacer:\n 1-Sumar(s)\n 2-Restar(r)\n 3-Multiplicar(m)\n");
	scanf("%d", &a);
	printf("\n\n");
	
	switch (a){
		case 1://sumar
			if((filas1==filas2) && (columnas1==columnas2))
			{
				for(i=0; (i<filas1)&&(i<filas2); i++)
					{
					for(j=0; (j<columnas1)&&(i<columnas2); j++)
						{
							m3[i][j] = m1[i][j] + m2[i][j];
							printf("%.2f ", m3[i][j]);
						}
						printf("\n");
					}
				}
			
			break;
		case 2://restar
			if((filas1==filas2) && (columnas1==columnas2))
			{
			for(i=0; (i<filas1)&&(i<filas2); i++)
				{
				for(j=0; (j<columnas1)&&(i<columnas2); j++)
					{
						m3[i][j] = m1[i][j] - m2[i][j];
						printf("%.2f ", m3[i][j]);
					}
					printf("\n");
				}
			}
			break;
					
		case 3://multiplicar
			if(columnas1==filas2)
			{
				for(i=0; i<filas1; i++)
				{
					for(j=0; j<columnas1; j++)
					{
						for(contador=0,aux=0; contador<columnas1; contador++)
						{
							aux = aux + m1[i][contador] * m2[contador][j];
							m3[i][j]= aux;
						}		
					}					
				}	
			}
			for(i=0; i<filas1; i++)
			{
				for(j=0; j<columnas2;j++)
				{
					printf("%.2f \t",m3[i][j]);
				}
				printf("\n");
			}	
			break;	
}
	printf("\nQuieres salir?\n 1.Si\n 2.No\n");
	scanf("%d",&op1);
	} while (op1==2);
	printf("\nHasta pronto...\n\n");
	
}

int datosTablaPeriodica(){
	

			//Para la Tabla
		struct TElemento tabla[200];
		int contador=0,N;
		int option=0,option2a,option2b,option3, option3a,option3b, op1=0;
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
			
				if(option2a==2){
					do
					{	
						printf("Cuantos elementos quiere registrar?\n");
						scanf("%d",&N);
			
						pfentrada=fopen("tabla1.txt","a");	
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
							scanf("%d",&option2b);
							fflush(stdin);
						}			
					fclose(pfentrada);
					}
					while(option2b!=2);
				}
				else {
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
				printf("Hasta pronto...\n\n");
			break;
			}
			
}

int operacionesBasicas(){
	
	float A,B,C,a,b,c,d;
	float x1,x2,x3;
	int opt;
	int ope,ope1;
	int i;
	float numeros[100],x,y;
	int N;
	float sum,res,mult,div,med,desv,sum2;
	do
	{
		printf("NOTA: TENGA EN CUENTA QUE LOS DECIMALES SE ESCRIBEN CON '.' Y NO ','\n");
		printf("Introduzca el tipo de operación que quiere hacer: \n 1.-Suma 2.-Resta 3.-Multiplicacion 4.-Division 5.-Media 6.-Desviacion\n 7.-Ecuacion de segundo grado\n 8.-Me he equivocado, no queria encender la calculadora\n");
		scanf("%d",&ope1);
		
		switch(ope1)
		{
			case 1://Suma
				sum=0.0;
				do{
					printf("Introduzca la cantidad de numeros que desea sumar:\n");
					scanf("%d",&N);
				}while (N<2);//el usuario debe introducir dos o mas numeros para sumar
				
				
				printf("Introduzca los numeros que desea sumar. Tras cada numero presione 'enter'. \n");
				for(i=0;i<N;i++)
				{
					scanf("%f",&numeros[i]);
					sum+=numeros[i];
				}
				printf("La suma es: %f",sum);
			break;
			
			case 2://Resta
				res=0.0;
				do{
					printf("Introduzca la cantidad de numeros que desea restar:\n");
					scanf("%d",&N);
				}while (N <2); // el usuario debe introducir dos o mas numeros para restar
				printf("Sus numeros se restaran desde el primero que inicie al ultimo.\n"); 
				printf("Si introduce primero el 10 y luego introduce los numeros 1 y luego 2, se realizara la siguiente resta: 10-1-2=7 \n");
				printf("Introduzca los numeros que desea restar teniendo en cuenta que se restara al primer numero los numeros consecutivos. Tras cada numero presione 'enter'. \n");
			
				
				for(i=0;i<N;i++)
				{
					scanf("%f",&numeros[i]);	
				}
				for(i=0;i<N;i++)
				{
					numeros[0]=-numeros[0];
					res-=numeros[i];	
				}
				
				printf("La resta es: %f",res);
			break;
		
			case 3://Multiplicacion
				do{
					printf("Introduzca la cantidad de numeros que desea multiplicar:\n");
					scanf("%d",&N);
				}while(N<2);
				
				mult=1.0;
				printf("Introduzca los numeros que desea multiplicar. Tras cada numero presione 'enter'. \n");
				for(i=0;i<N;i++)
				{
					scanf("%f",&numeros[i]);
					mult*=numeros[i];
				}
				printf("El resultado es: %f",mult);
				
			break;
			
			case 4://Division
			
				printf("Introduzca los  2 numeros que desea dividir.Primero introduzca el numero a dividir y luego el divisor. Tras cada numero presione 'enter'. \n");
				scanf("%f",&x);
				scanf("%f",&y);
				div=(x/y);
				printf("El resultado es: %f",div);
			break;
			
			case 5://Media
				med=0.0;
				sum=0.0;
				do{
					printf("Introduzca la cantidad de numeros con los que desea hacer la media:\n");
					scanf("%d",&N);
				}while(N<2);
				
				
				printf("Introduzca los numeros. Tras cada numero presione 'enter'. \n");
				for(i=0;i<N;i++)
				{
					scanf("%f",&numeros[i]);
					sum+=numeros[i];
				}
				med=sum/N;
				printf("La media es: %f", med);
			break;
			
			case 6://Desviacion
				sum=0.0;
				med=0.0;
				sum2=0.0;
				desv=0.0;
				do{
					printf("Introduzca la cantidad de numeros con los que desea hacer la desviacion tipica:\n");
					scanf("%d",&N);
				}while(N<2);
			
			//HACEMOS LA MEDIA	
				printf("Introduzca los numeros. Tras cada numero presione 'enter'. \n");
				for(i=0;i<N;i++)
				{
					scanf("%f",&numeros[i]);
					sum+=numeros[i];
				}
				med=sum/N;
			//CALCULAMOS LA DESVIACION
				for(i=0;i<N;i++)
				{
					sum2+=(pow(numeros[i]-med,2));
				}
				desv=sqrt(sum2/N);
				printf("La desviacion tipica es: %f.\n",desv);
				printf("La media es: %f.\n",med);
			break;
			case 7:
					
					printf("Introduzca datos de Ecuacion de Segundo grado\n Ax^2+Bx+C=0\n");
					fflush(stdin);
					scanf(" %f %f %f",&A,&B,&C);
		
					if(((pow(B,2))-4*A*C)<0)
					{
						printf("Sus resultados estan en el espectro de numeros imaginarios:\n"),
						x1=sqrt((pow(B,2)-4*A*C)/(-1));
						x2=sqrt((pow(B,2)-4*A*C)/(-1));
						printf("x1: -%f-%f i\n",B/(2*A),x1/(2*A));
						printf("x2: -%f+%f i\n",B/(2*A),x2/(2*A));
					}
	 				
					 else if(((pow(B,2))-4*A*C)>0)
					{
						printf("Sus resultados estan en el espectro de numeros reales:\n"),
						x1=(-B-sqrt(pow(B,2)-4*A*C))/(2*A);
						x2=(-B+sqrt(pow(B,2)-4*A*C))/(2*A);
						printf("x1: %f\n",x1);
						printf("x2: %f\n",x2);
					}	
		
			break;
			case 8://Me he equivocado no queria encender la calculadora
				printf("Apagando la calculadora...\n");
			break;
			
		}
	
		printf("\n Desea realizar alguna de estas operaciones otra vez?\n 1.-Si 2.-No \n");
		scanf("%d",&ope);
	}//Final del do
	while(ope==1);
	printf("Hasta pronto...\n\n");
	
}

int operacionesComplejas(){
	int i; //bucle for
	float a, ai, b, bi, bii; // parametros de las partes reales e imaginarias
	int op,op1; // opciones de los bucles do - while
	float sum=0, sumi=0, dif=0, difi=0, res=0, resi=0; // suma, resta y multiplicacion
	float numerador=0, numeradori=0, denominador=0; // division
	float modulo1=0, modulo2=0, argumento1=0, argumento2=0; // pasar a coordenadas polares
	float preal=0, pimaginaria=0, x=0, y=0; // pasar a coordenadas cartesianas
	do // bucle para volver a operar en esta seccion si quiere el usuario
	{
		
		do { // bucle para repetir las opciones si se equivoca el usuario
		printf("Que desea hacer:\n");
	printf("1. sumar\n 2. restar\n 3. multiplicar\n 4. dividir\n 5. Pasar a coordenadas polares \n 6. Pasar a coordenadas artesianas");
		scanf("%d",&op);
	}while(op>6 || op<0);
	
	if (op != 6){ // condicional para operar con numeros com`lejos de la forma a + ai o a - ai
		
		//primer numero complejo
		printf("Introduzca la parte real  y la parte imaginaria del primer numero complejo:\n");
		scanf("%f %f",&a, &ai);
		
		//segundo numero complejo
		printf("Introduzca la parte real  y la parte imaginaria del segundo numero complejo:\n");
		scanf("%f %f",&b, &bi);
	
		switch (op)
		{
			case 1: //suma
			sum = a + b; //suma de la parte real
			sumi= ai + bi; // suma de la parte imaginaria
			if(sumi>=0){
				printf("%.4f + %.4fi\n", sum, sumi);
			}else{
				printf("%.4f - %.4fi\n", sum, sumi);
			}	
			break;
						
			case 2://resta
			dif = a - b; //resta de la parte real
			difi= ai - bi; // resta de la parte imaginaria
			if(difi>=0){
				printf("Resultado: %.4f+%.4fi\n", dif, difi);
			}else{
				printf("Resultado: %.4f %.4fi\n", dif, difi);
			}	
			break;
			
			case 3://multiplicacion
				res = a*b -ai*bi; //parte real de las operaciones
				resi = a*bi + ai*b; //parte imaginaria de las operaciones
								
				if (resi<0){
					printf("Resultado: %.4f %.4fi\n",res, resi);
				}else{
					printf("Resultado: %.4f + %.4fi\n",res, resi);
				}							
			break;
			
			case 4: //division se opera de la siguiente forma: (a+ai) / (b+bi)
				if(bi>=0){ //se debe multiplicar la fraccion por el conjugado del denominador
					bii = -bi;
				}
				numerador = a*b - ai*bii;//parte real
				numeradori = ai*b + a*bii;//parte imaginaria
				denominador = pow(b,2) + pow(bi,2);
				
				
				if(numeradori<0){
					printf("Resultado: %.4f %.4fi",numerador/denominador, numeradori/denominador);
				}else {
					printf("Resultado: %.4f + %.4fi",numerador/denominador, numeradori/denominador);
				}
			break;
			
			
			case 5: // pasar el numero complejo a coordenadas polares
				
				modulo1= sqrt(pow(a,2) + pow(ai,2));
				argumento1 = atan(ai/a) * (180.0/3.141592);
				modulo2= sqrt(pow(b,2) + pow(bi,2));
				argumento2 = atan(bi/b) * (180.0/3.141592);
				
				printf("%.4f | %.4f%c \n", modulo1, argumento1,248);
				printf("%.4f | %.4f%c \n", modulo2, argumento2,248);	
			break;
	}
	
			} else { // pasar de coordenadas polares a cartesianas
				fflush(stdin);
				printf("Introduzca el modulo y argumento (en grados):\n");
	
				scanf("%f %f",&a, &ai);
		
				preal = a * cos(ai * (3.141592/180.0)); // se multiplica los grados por (PI/180) porque el coseno lo da en radianes
				pimaginaria = a * sin(ai * (3.141592/180.0));

				if(pimaginaria<0){
					printf("%.4f %.4fi\n", preal, pimaginaria);
				}else {
					printf("%.4f + %.4fi\n", preal, pimaginaria);
				}
			}

	printf("\nQuieres salir?\n 1.Si\n 2.No");
	scanf("%d",&op1);
	}while(op1==2);
	printf("\nHasta pronto...");
}

int operacionesIntegrales(){
	
	int opcion=0, opcion2=0, op1=0;
	double exp=0,constante=0, constante2=0, base=0;
	double i;
	double a=0, b=0, x=0, z=0; 
	double A,B,C,D,E,F;
	double incremento=1e-6,suma=0,integral=0;
	
	
	do{
		
	
	do{
		fflush(stdin);
		fflush(stdin);
		printf("Introduzca los intervalos de la integral definida a y b:\t ");
		scanf("%lf %lf",&a,&b);
		fflush(stdin);
		printf("Que tipo de funcion es?\n");
		printf("\n1-sen\n 2-cos\n 3-tan \n 4-Polinomica\n 5-Fracion\n 6-Exponencial(n^x)\n 7-Logaritmo");
		scanf("%d", &opcion);
		
	}while((opcion<0)||(opcion>7));

	switch (opcion){
		case 1:		
			fflush(stdin);
			printf("sen(a*x^n)\n");
			printf("Introduzca a\n");
			scanf("%lf",&constante);
			printf("Introduzca el grado de x (n):\n");
			scanf("%lf", &exp);
			
			for(i=a;i<=b;i+=incremento){
				
			suma += sin(constante* (pow(i,exp))/180.0*3.141592);
			}
				integral=suma*incremento;
				printf("la integral es: %lf\n",integral);
		break;
	
		case 2:
			fflush(stdin);
			printf("sen(a*x^n)\n");
			printf("Introduzca a\n");
			scanf("%lf",&constante);
			printf("Introduzca el grado de x (n):\n");
			scanf("%lf", &exp);
			
			for(i=a;i<=b;i+=incremento){
				
			suma += cos(constante* (pow(i,exp))/180.0*3.141592);
			}
				integral=suma*incremento;
				printf("la integral es: %lf\n",integral);
		break;
		
		case 3:
			fflush(stdin);
			printf("sen(a*x^n)\n");
			printf("Introduzca a\n");
			scanf("%lf",&constante);
			printf("Introduzca el grado de x (n):\n");
			scanf("%lf", &exp);
			
			for(i=a;i<=b;i+=incremento){
				
			suma += tan(constante* (pow(i,exp))/180.0*3.141592);
			}
				integral=suma*incremento;
				printf("la integral es: %lf\n",integral);
		break;  
		
		case 4: 
			fflush(stdin);
			printf("\n");
			printf("Puede llegar a hacer  integrales polinomicas de hasta grado 5:Ax+Bx^2+Cx^3+Dx^4+Ex^5+F \n");
			//Ax+B+C+D+Ex^5
			printf("Introduzca los numeros, si no tiene un elemento ponga un 0 y si es negativo escriba: '-'\n");
			scanf("%lf %lf %lf %lf %lf %lf",&A, &B, &C, &D, &E, &F);
			
			
			for(i=a;i<=b;i+=incremento){
				
				suma += (A*(pow(i,1))+B*(pow(i,2))+C*(pow(i,3))+D*(pow(i,4))+E*(pow(i,5))+F*(pow(i,0)));
			}
				integral=suma*incremento;
				printf("la integral es: %lf\n",integral);
				
		break;
		
		case 5: 
			fflush(stdin);
			printf("a/x\n");
			printf("Introduzca a\n");
			fflush(stdin);
			scanf("%lf",&constante);
			printf("Introduzca el grado de x (n):\n");
			fflush(stdin);
			scanf("%lf", &exp);
			
			for(i=a;i<=b;i+=incremento){
				
			suma += (constante / pow(i,exp));
			}
				fflush(stdin);
				integral=suma*incremento;
				printf("la integral es: %lf\n",integral);					
		break;
		
		case 6: 
			fflush(stdin);
			printf("z*c^(x^n)\n");
			printf("Introduzca z (constante)\n");
			scanf("%lf",&constante);
			printf("Introduzca c (base)\n");
			scanf("%lf",&base);
			printf("Introduzca el grado de x (n):\n");
			scanf("%lf", &exp);
			
			for(i=a;i<=b;i+=incremento){
				
			suma += constante * pow(base,pow(i,exp));
			}
				integral=suma*incremento;
				printf("la integral es: %lf\n",integral);		
		break;
		
		case 7:
			fflush(stdin);
			do{
				printf("¿1-Log\n2-Ln?\n");
				scanf("%d",&opcion2);
				
				if(opcion2 == 1){
					
					printf("z*log(c*(x^n))\n");
					printf("Introduzca z (constante 1)\n");
					scanf("%lf",&constante);
					printf("Introduzca c (constante 2)\n");
					scanf("%lf",&constante2);
					printf("Introduzca el grado de x (n):\n");
					scanf("%lf", &exp);
				
					for(i=a;i<=b;i+=incremento){
						
					suma += constante * log10(constante2 * pow(i,exp));
					}
						integral=suma*incremento;
						printf("la integral es: %lf\n",integral);
						
					} else if (opcion2==2) {
						
					printf("z*ln(c*(x^n))\n");
					printf("Introduzca z (constante 1)\n");
					scanf("%lf",&constante);
					printf("Introduzca c (constante 2)\n");
					scanf("%lf",&constante2);
					printf("Introduzca el grado de x (n):\n");
					scanf("%lf", &exp);
				
					for(i=a;i<=b;i+=incremento){
						
					suma += constante * log(constante2 * pow(i,exp));
					}
						integral=suma*incremento;
						printf("la integral es: %lf\n",integral);
					}		
				}while(opcion2<0 || opcion2>2);	
						
		break;
}
printf("\nQuieres salir?\n 1.Si\n 2.No\n");
	scanf("%d",&op1);
	} while (op1==2);
	printf("\nHasta pronto...\n\n");
}

int sistemasEcuaciones(){
	
	int C,Dimension;
    float Sistema[101][102];
    PideDatos(&Dimension,Sistema);
    printf("\n\n\nEl SISTEMA introducido es el siguiente: \n\n");
    EscribeDatos(Dimension,Sistema);
    ResuelveGauss(Dimension,Sistema);
    printf("\n\n\nLas soluciones son:\n");
    for(C=1;C<=Dimension;C++) printf("\n X%d=%f\n",C,Sistema[C][Dimension+1]);
    printf("\n\n");
   
    scanf("");
    return(0);
}

void PideDatos(int *Dim,float Sist[][102])
{
    int A,B;
    printf("\n\n ||RESUELVE SISTEMAS LINEALES DETERMINADOS POR GAUSS||");
    printf("\n\n\n Introduce el numero de incognitas:(menor que 100)");
    scanf("%d",&*Dim);
    printf("\n\n PASE A INTRODUCIR CADA COMPONENTE DEL SISTEMA (A|B):");
    printf("\n\n MATRIZ A:\n");
    for(A=1;A<=*Dim;A++) for(B=1;B<=*Dim;B++){
        printf("\n Termino A(%d,%d):",A,B); scanf("%f",&Sist[A][B]);}
    printf("\n\n\n VECTOR B:\n");
    for(A=1;A<=*Dim;A++){
        printf("\n Termino B(%d):",A);scanf("%f",&Sist[A][*Dim+1]);
    }
	}

void EscribeDatos(int Dim, float Sist[][102])
{
    int A,B;
    for(A=1;A<=Dim;A++){
        for(B=1;B<=(Dim+1);B++){
            printf("%7.2f",Sist[A][B]);
            if(B==Dim) printf("   |");}
        printf("\n");
    }
	}
    
void ResuelveGauss(int Dim, float Sist[][102])
{
	
    int NoCero,Col,C1,C2,A;
    float Pivote,V1;
   
    for(Col=1;Col<=Dim;Col++){
        NoCero=0;A=Col;
        while(NoCero==0){
           if((Sist[A][Col]>0.0000001)||((Sist[A][Col]<-0.0000001))){
                NoCero=1;}
            else A++;}
        Pivote=Sist[A][Col];
        for(C1=1;C1<=(Dim+1);C1++){
            V1=Sist[A][C1];
            Sist[A][C1]=Sist[Col][C1];
            Sist[Col][C1]=V1/Pivote;}
        for(C2=Col+1;C2<=Dim;C2++){
            V1=Sist[C2][Col];
            for(C1=Col;C1<=(Dim+1);C1++){
                Sist[C2][C1]=Sist[C2][C1]-V1*Sist[Col][C1];}
    }
	}
   
    for(Col=Dim;Col>=1;Col--) for(C1=(Col-1);C1>=1;C1--){
        Sist[C1][Dim+1]=Sist[C1][Dim+1]-Sist[C1][Col]*Sist[Col][Dim+1];
        Sist[C1][Col]=0;
    }
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
					pfentrada=fopen("tabla2.txt","w");	
					//pido los datos al usuario sobre los elementos

					for(i=0;i<N;i++)
					{
						printf("Introduzca los datos de la constante:\n \n");
						printf("Introduzca el nombre: \t");
						scanf("%s", tabla[i].nombre);
						fprintf(pfentrada,"%s\t", tabla[i].nombre);	
						fflush(stdin);
					
						printf("Introduzca el numero: \t");
						scanf("%f", tabla[i].numero);	
						fprintf(pfentrada,"\t  %f ", tabla[i].numero);
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
					while(fscanf(pfentrada,"%s %f", tabla[j].nombre, tabla[j].numero)!=EOF)
					{
						printf("%s\t\t %f\n", tabla[j].nombre,tabla[j].numero);
						j++;
						
					}
					fclose(pfentrada);
			}
			
			}
			while(option2!=2);
	}
	else
	{
		printf("Apagando...");
	}
}
	


