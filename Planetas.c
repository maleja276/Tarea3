
/* Archivo datos planetas*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){

	FILE *datos;

	int i;

	int j;

	int matriz[9][6];

	int let=250;

	char lineas[let];

	char *palabras;

	const char *delimiter;

	delimiter=","; 

	datos = fopen("coordinates.csv", "r");

	i=0;
	j=0;

	while(fgets(lineas, let, datos)){

		palabras=strtok(lineas,delimiter);

		while (palabras!=NULL){
		
			matriz[i][j]=atof(palabras);
			printf("%s\n", palabras);
			palabras=strtok(NULL,delimiter);
			i+=1;
		}
		j+=1;	
	
	}
	return 0;

}

