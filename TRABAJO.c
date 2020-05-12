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

int operacionesVectores();
int operacionesMatrices();
int datosTablaPeriodica();
int operacionesBasicas();

//Menu del trabajo
int main()
{	
	 
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
					operacionesBasicas();
				break;
			
				case 2: printf("Operaciones con Vectores\n");
					 operacionesVectores();
				break;
			
				case 3: printf("Operaciones con Matrices\n");
					operacionesMatrices();
				break;
			
				case 4:printf("Constantes numericas\n");	
				break;
			
/*TABLA*/		case 5: printf("Tabla Periodica\n");
					datosTablaPeriodica();
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



int operacionesVectores(){
	
	int d;//determinar la dmension del vector
	int x,y,z; // coordenadas de los vectores
	int n;// switch de operaciones
	int i;// bucles for
	int v1[d],v2[d],v3[d];//v1 y v2 son introducidos por teclado y v3 es el vector resultado
	float sum=0.0;
	float sumatorio1=0, resultado1=0,sumatorio2=0, resultado2=0;
	float angulo=0.0;

	//PRIMERO: Preguntar por la dimension del vector
	do {
		printf("Introduzca la dimension de los vectores:\n");
		scanf("%d",&d);
		
	}while(d<2 || d>3);
	//SEGUNDO: Introducir los elementos de cada vector
		//vector 1
		for(i=0; i<d; i++){
			
			printf("Introduzca el valor %d del vector 1: ",i+1);
			scanf("%d", &v1[i]);
		}
		//vector 2
		for(i=0; i<d; i++){
			printf("Introduzca el valor %d del vector 2: ",i+1);
			scanf("%d", &v2[i]);
		}

	//TERCERO: Elegir una operacion
		printf("Introduzca la operacion: \n1.Sumar\n2.Restar\n3.Producto vectorial\n4.Producto escalar\n5.Modulo\n6.Angulo\n");
		scanf("%d",&n);
		switch (n){
			case 1: //suma
				for(i=0;i<d;i++){
				v3[i]=  v1[i] + v2[i];
				printf("%d ",v3[i]);
				}
			break;
			
			case 2: //resta
				for(i=0;i<d;i++){
				v3[i]=  v1[i] - v2[i];
				printf("%d ",v3[i]);
				}
			break;
			
			case 3: //producto vectorial 
				if(d==3){
					x = v1[1]*v2[2] - v1[2]*v2[1];
					y = v1[0]*v2[2] - v1[2]*v2[0];
					z = v1[0]*v2[1] - v1[1]*v2[0];
					printf("%d %d %d",x,y,z);
				}else if(d == 2){
					z = v1[0]*v2[1] - v1[1]*v2[0];
					printf("%d k",z);// el vector resultante sale del plano en el que estan v1 y v2
				}				
			break;		
				
			case 4: //producto escalar
			for(i=0;i<d;i++)
				{
				sum +=  v1[i] * v2[i];
				}
				printf("Resultado = %d",sum);
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
				printf("Modulo v1 = %f\n",resultado1);
				printf("Modulo v2 = %f",resultado2);
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
				printf("Angulo = %f grados",angulo*(180.000000)/3.141592);
				break;
		}while(n>5 || n<0);
}

int operacionesMatrices(){
	
	int i,j;
	int filas1=0,filas2=0,filas3=0,columnas1=0,columnas2=0,columnas3=0;
	int m1[filas1][columnas1],m2[filas2][columnas2],m3[filas3][columnas3];
	int a,aux,contador;

	printf("Introduzca las filas y columans de la matriz1\n");
	scanf("%d",&filas1);
	scanf("%d",&columnas1);
	for(i=0; i<filas1; i++)
	{
		for(j=0; j<columnas1; j++)
		{
			printf("Introduce elemento de la matriz1[%d][%d]\n", i+1, j+1);
			scanf("%d", &m1[i][j]);
		}
	}
	
	printf("Introduzca las filas y columans de la matriz2\n");
	scanf("%d",&filas2);
	scanf("%d",&columnas2);
	for(i=0; i<filas2; i++)
	{
		for(j=0; j<columnas2; j++)
		{
			printf("Introduce elemento de la matriz2[%d][%d]\n", i+1, j+1);
			scanf("%d", &m2[i][j]);
		}
	}
	
	printf("Que desea hacer:\n 1-Sumar(s)\n 2-Restar(r)\n 3-Multiplicar(m)\n");
	scanf("%d", &a);
	
	switch (a){
		case 1:
			if((filas1==filas2) && (columnas1==columnas2))
			{
				for(i=0; (i<filas1)&&(i<filas2); i++)
					{
					for(j=0; (j<columnas1)&&(i<columnas2); j++)
						{
							m3[i][j] = m1[i][j] + m2[i][j];
							printf("%d ", m3[i][j]);
						}
						printf("\n");
					}
				}
			
			break;
	case 2:
			if((filas1==filas2) && (columnas1==columnas2))
			{
			for(i=0; (i<filas1)&&(i<filas2); i++)
				{
				for(j=0; (j<columnas1)&&(i<columnas2); j++)
					{
						m3[i][j] = m1[i][j] - m2[i][j];
						printf("%d", m3[i][j]);
					}
					printf("\n");
				}
			}
			break;
					
		case 3:
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
					printf("%d \t",m3[i][j]);
				}
				printf("\n");
			}	
			break;	
}
	
}



int datosTablaPeriodica(){
	

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



int operacionesBasicas(){
	
		int ope,ope1;
	int i;
	float numeros[100],x,y;
	int N;
	float sum,res,mult,div,med,desv,sum2;
	do
	{
		printf("NOTA: TENGA EN CUENTA QUE LOS DECIMALES SE ESCRIBEN CON '.' Y NO ','\n");
		printf("Introduzca el tipo de operación que quiere hacer: \n 1.-Suma 2.-Resta 3.-Multiplicacion 4.-Division 5.-Media 6.-Desviacion\n 7.-Me he equivocado, no queria encender la calculadora\n");
		scanf("%d",&ope1);
		
		switch(ope1)
		{
			case 1://Suma
				sum=0.0;
				printf("Introduzca la cantidad de numeros que desea sumar:\n");
				scanf("%d",&N);
				
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
				printf("Introduzca la cantidad de numeros que desea restar:\n");
				scanf("%d",&N);
				
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
				printf("Introduzca la cantidad de numeros que desea multiplicar:\n");
				scanf("%d",&N);
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
				printf("Introduzca la cantidad de numeros con los que desea hacer la media:\n");
				scanf("%d",&N);
				
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
				printf("Introduzca la cantidad de numeros con los que desea hacer la desviacion tipica:\n");
				scanf("%d",&N);
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
			
			case 7://Me he equivocado no queria encender la calculadora
				printf("Apagando la calculadora...\n");
			break;
			
		}
	
		printf("\n Desea realizar alguna de estas operaciones otra vez?\n 1.-Si 2.-No \n");
		scanf("%d",&ope);
	}//Final del do
	while(ope==1);
	
}






