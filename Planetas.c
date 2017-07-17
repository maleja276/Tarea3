
/* Archivo datos planetas*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int n = 1000;

int posicion(int i,int j){
	return n*j+1;
}

int main(void){

	FILE *datos;

	int i=0, j=0; 
	int fil=10, col=6;	
	int matriz_datos[fil][col];
	int let=250;
	char lineas[let];
	char *palabras;
	const char *delimiter;

	delimiter=","; 

	datos = fopen("coordinates.csv", "r");

	
	while(fgets(lineas, let, datos)){

		palabras=strtok(lineas,delimiter);

		while (palabras!=NULL){

			matriz_datos[i][j]=atof(palabras);
			//printf("%s\n", palabras);
			palabras=strtok(NULL,delimiter);
//			i+=1;
		}
//		j+=1;
//	printf("%d",matriz_datos[0][0]);

		
	}	

	float *p_x= malloc(n*fil*sizeof(float));
	float *p_y= malloc(n*fil*sizeof(float));
	float *p_z= malloc(n*fil*sizeof(float));

	float *v_x= malloc(n*fil*sizeof(float));
	float *v_y= malloc(n*fil*sizeof(float));
	float *v_z= malloc(n*fil*sizeof(float));

	float *vm_x= malloc(fil*sizeof(float));
	float *vm_y= malloc(fil*sizeof(float));
	float *vm_z= malloc(fil*sizeof(float));

}



