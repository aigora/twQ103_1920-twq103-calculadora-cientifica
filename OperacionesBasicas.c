#include<stdio.h>
#include<math.h>
//Operaciones basicas
int main()
{
	int ope,ope1;
	int i;
	float numeros[100],x,y;
	int N;
	float sum,res,mult,div,med,desv,sum2;
	do
	{
		printf("NOTA: TENGA EN CUENTA QUE LOS DECIMALES SE ESCRIBEN CON '.' Y NO ','\n");
		printf("Introduzca el tipo de operaci�n que quiere hacer: \n 1.-Suma 2.-Resta 3.-Multiplicacion 4.-Division 5.-Media 6.-Desviacion\n 7.-Me he equivocado, no queria encender la calculadora\n");
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
return 0;
}
