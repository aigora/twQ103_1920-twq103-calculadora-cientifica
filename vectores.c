//trabajo 19-20 parte de vectores
#include<stdio.h>
#include<math.h>

int main(){
	int d;
	int i;
	int v1[d],v2[d],v3[d];
	float sum=0.0;
	int x,y,z;
	float sumatorio1=0, resultado1=0,sumatorio2=0, resultado2=0;
	float angulo=0;
	int n;
	


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
			case 1:
				for(i=0;i<d;i++){
				v3[i]=  v1[i] + v2[i];
				printf("%d ",v3[i]);
				}
			break;
			
			case 2:
				for(i=0;i<d;i++){
				v3[i]=  v1[i] - v2[i];
				printf("%d ",v3[i]);
				}
			break;
			
			case 3:
				if(d==3){
					x = v1[1]*v2[2] - v1[2]*v2[1];
					y = v1[0]*v2[2] - v1[2]*v2[0];
					z = v1[0]*v2[1] - v1[1]*v2[0];
					printf("%d %d %d",x,y,z);
				}else if(d == 2){
					z = v1[0]*v2[1] - v1[1]*v2[0];
					printf("%d k",z);
				}
				
			break;
			
			case 4: 
			for(i=0;i<d;i++)
				{
				sum +=  v1[i] * v2[i];
				}
				printf("Resultado = %d",sum);
			break;
			case 5:
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
			
			case 6:
				for(i=0;i<d;i++)
				{
				sum +=  v1[i] * v2[i];
				}
				for(i=0; i<d; i++){
					sumatorio1 += pow(v1[i],2);
				}
				resultado1 = sqrt(sumatorio1);
				for(i=0; i<d; i++){
					sumatorio2 += pow(v2[i],2);
				}
				resultado2 = sqrt(sumatorio2);
				angulo = acos(  fabs(sum / sqrt(sumatorio1 * sumatorio2) ) );//tener en cuenta que nos el resultado en radianes
				printf("Angulo = %f grados",angulo*(180.000000)/3.141592);
				break;
				
	
		}while(n>5 || n<0);
	
	}
	
