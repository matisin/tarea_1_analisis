
#include <stdio.h>

#include <math.h>

int main(){
	int i = 0, k = 1001;
	FILE *cubo = fopen("cubo.txt","w+");
	for(i = 0 ; i < k ; i++){

		fprintf(cubo, "%d %.2f\n", i, pow(i,3)*0.0000001);
	}
	fclose(cubo);
	return 0;
}