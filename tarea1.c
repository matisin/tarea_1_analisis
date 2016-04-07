#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void enigma_mejorado(float **A,int n){
	int i,j;
	
	for(i = 0; i < n - 1 ; i++){
		for(j = i + 1; j < n-1 ; j++){
			A[j][i] = 0;		
		}		
	}	
}


void enigma(float **A,int n){
	int i,j,k;

	for(i = 0; i < n - 1 ; i++){
		for(j = i + 1; j < n-1 ; j++){
			for(k = i ; k < n ; k++){				
				A[j][k] = A[j][k] - A[i][k]*(A[j][i]/A[i][i]);			
			}			
		}		
	}
}



int main(){

	int i,j,n,N;

	clock_t begin, end;
	double time_spent;//para medir el tiempo

	printf("Ingrese el n máximo:");
	scanf("%d",&N);

	srand (time(NULL));//semilla para el random
	FILE *resultados;
	resultados = fopen("resultados.txt", "w+");//archivo de salida de resutlados

	for(n = 2 ; n < N + 1; n++){//entrada n desde 2 a 500
		//se define una matriz de (n-1*n) 
		float **A = (float **) malloc((n-1)*sizeof(float *));
		for(i = 0; i < n - 1; i++){
			A[i] = (float *)malloc(n*sizeof(float));
		}
		for(i = 0; i < n -1; i++){
			for(j = 0; j < n ; j++){
				A[i][j] = rand() % 100;//cada elemento de la matriz es un numero al azar de 0 al 100, revisar rand
			}
		}		
		begin = clock();//tiempo antes de el algoritmo
		enigma(A,n);
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;//tiempo despues del algoritmo
		fprintf(resultados,"%d	%lf\n",n,time_spent);
		for(i = 0; i < n - 1; i++){
			free(A[i]);
		}
		free(A);
	}

	for(n = 2 ; n < N +1; n++){//entrada n desde 2 a 500
		//se define una matriz de (n-1*n) 
		float **A = (float **) malloc((n-1)*sizeof(float *));
		for(i = 0; i < n - 1; i++){
			A[i] = (float *)malloc(n*sizeof(float));
		}
		for(i = 0; i < n -1; i++){
			for(j = 0; j < n ; j++){
				A[i][j] = rand() % 100;//cada elemento de la matriz es un numero al azar de 0 al 100, revisar rand
			}
		}		
		begin = clock();//tiempo antes de el algoritmo
		enigma_mejorado(A,n);
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;//tiempo despues del algoritmo
		fprintf(resultados,"%d	%lf\n",n,time_spent);
		for(i = 0; i < n - 1; i++){
			free(A[i]);
		}
		free(A);
	}	
	
	fclose(resultados);
	
	
}
