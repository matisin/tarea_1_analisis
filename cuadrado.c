
#include <stdio.h>

#include <math.h>

int main(){
	int i = 0, k = 1001;
	FILE *cuadrado = fopen("cuadrado.txt","w+");
	for(i = 0 ; i < k ; i++){

		fprintf(cuadrado, "%d %.2f\n", i, pow(i,2)*0.000001);
	}
	fclose(cuadrado);
	return 0;
}