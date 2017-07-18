
/* Archivo datos planetas*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PI 3.141519
#define G 39.476568
#define n 1000



//Posicion en terminos lineales dado un i,j

int indices(int i,int j){
	return n*j+1;
}



int main(void){
	
	//Definicion de variables

	FILE *datos;

	int i=0, j=0; 
	int fil=10, col=7;	
	float matriz_datos[fil][col];
	int let=250;
	char lineas[let];
	char *palabras;
	const char *delimiter;
	
	float masa_sol;

	delimiter=","; 

	datos = fopen("coordinates.csv", "r");

	
	while(fgets(lineas, let, datos)){
		j=0;
		palabras=strtok(lineas,delimiter);

		while (palabras!=NULL){
			if(j!=0){
				matriz_datos[i][j-1]=atof(palabras);
			}
			palabras=strtok(NULL,delimiter);
			j+=1;
			
		}
		i+=1;		
	}
	
	float m_sol = matriz_datos[0][0];

	for (i=0; i<10; i++){

		matriz_datos[i][0]= matriz_datos[i][0]/ m_sol;
		
	}

/*	for (i=0;i<10;i++){

		for(j=0;j<col;j++)
			{
			printf("%e\n", matriz_datos[i][j]);
			}
	}

/*	//Deficion Matrices

	/*float *p_x= malloc(n*fil*sizeof(float));
	float *p_y= malloc(n*fil*sizeof(float));
	float *p_z= malloc(n*fil*sizeof(float));

	float *v_x= malloc(n*fil*sizeof(float));
	float *v_y= malloc(n*fil*sizeof(float));
	float *v_z= malloc(n*fil*sizeof(float));

	float *vm_x= malloc(fil*sizeof(float));
	float *vm_y= malloc(fil*sizeof(float));
	float *vm_z= malloc(fil*sizeof(float));


	
	}*/

}



