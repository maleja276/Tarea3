
/* Archivo datos planetas*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 3.141519
#define G 39.476568
#define n 1000

//Definir las funciones 

void aceleracion(int i, int t, float *ax, float *ay, float *az, float matriz_datos, float *p_x, float *p_y, float *p_z);
int cambio_indices(int i,int j);

//Posicion en terminos lineales dado un i,j


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

	//Deficion Matrices

	float *ax;
	float *ay;
	float *az;
	float *p_x= malloc(n*fil*sizeof(float));
	float *p_y= malloc(n*fil*sizeof(float));
	float *p_z= malloc(n*fil*sizeof(float));

	float *v_x= malloc(n*fil*sizeof(float));
	float *v_y= malloc(n*fil*sizeof(float));
	float *v_z= malloc(n*fil*sizeof(float));

	float *vm_x= malloc(fil*sizeof(float));
	float *vm_y= malloc(fil*sizeof(float));
	float *vm_z= malloc(fil*sizeof(float));
	
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

/*


	
	}*/

}

int cambio_indices(int i,int j){
	
	return n*j+1;
}


void aceleracion(int i, int t, float *ax, float *ay, float *az, float matriz_datos, float *p_x, float *p_y, float *p_z)

{
	float constante;
	float masa;
	int ii=0;

	for(ii=0;ii<10;ii++){

		if(ii!=i){

			masa=matriz_datos[ii][0];
			constante= (G * masa)/pow((pow((p_x[ii,t]-p_x[i,t]),2.0)-pow((p_y[ii,t]-p_y[i,t]),2.0)-pow((p_z[ii,t]-p_z[i,t]),2.0)),(3.0/2.0));


			}
	}
	
	ax=constante * (p_x[ii,t]-p_x[i,t]);
	ay=constante * (p_y[ii,t]-p_y[i,t]);
	az=constante * (p_z[ii,t]-p_z[i,t]);
}


