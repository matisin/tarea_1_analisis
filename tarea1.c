#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void enigma(float **A,int n){
	int i,j,k;

	int c = 0;
	for(i = 0; i < n - 1 ; i++){
		for(j = i + 1; j < n-1 ; j++){
			for(k = i ; k < n ; k++){
				//printf(" %.2f - %.2f*(%.2f/%.2f)\n",A[j][k],A[i][k],A[j][i],A[i][i] );
				A[j][k] = A[j][k] - A[i][k]*(A[j][i]/A[i][i]);
				c++;
				//printf("%.2f\n", A[j][k]);
				//printf("i:%d j:%d k:%d\n", i,j,k);

			}
			
		}
		
	}


	/*
	int c = 0;
	
	for(i = 0; i < n - 1 ; i++){
		for(j = i + 1; j < n-1 ; j++){
			c++;
		
			A[j][i] = 0;		
		}
		
	}*/
	printf("\n%d\n",c);

}



int main(){
	int i,j,n;
	srand (time(NULL));
	FILE *fp;
	fp = fopen("resultados.txt", "w+");	
	printf("%d\n",sizeof(float));
	for(n = 2 ; n < 10 ; n++){
		float **A = (float **) malloc((n-1)*sizeof(float *));
		for(i = 0; i < n - 1; i++){
			A[i] = (float *)malloc(n*sizeof(float));
		}
		for(i = 0; i < n -1; i++){
			for(j = 0; j < n ; j++){
				A[i][j] = rand() % 100;
			}
		}

		fprintf(fp, "--------------------------------------------\nMatriz original\n" );
		for(i = 0; i < n - 1; i++){
			for(j = 0; j < n ; j++){
				fprintf(fp,"%.2f	", A[i][j]);
			}
			fprintf(fp,"\n");
		}
		enigma(A,n);
		fprintf(fp, "--------------------------------------------\n Matriz con enigma\n");
		for(i = 0; i < n - 1 ; i++){
			for(j = 0; j < n ; j++){
				fprintf(fp,"%.2f	", A[i][j]);
			}
			fprintf(fp,"\n");
		}
		fprintf(fp,"\n");
		for(i = 0; i < n - 1; i++){
			free(A[i]);
		}
		free(A);

	}	
	fclose(fp);
	
	
}
