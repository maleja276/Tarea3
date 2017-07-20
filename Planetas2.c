#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define PI 3.141519
#define G 39.476568

int indices(int i, int j, int n){
	
	return (i*n+j);
}

void aceleracion(int n, int i, int t, float *a_x, float *a_y, float *a_z, float *masa, float *p_x, float *p_y, float *p_z)

{
	
	float constante;
	float dir_x;
	float dir_y;
	float dir_z;
	int ind_j;
	int ind_i;
	int j;
	double *d=malloc(3*sizeof(double));
	float a=*a_x;
	float b=*a_y;
	float c=*a_z;
	

 

	for(j=0;j<10;j++){

		ind_j=(n*j+t);
		ind_i=(n*i+t);

		d[0]=p_x[ind_j]-p_x[ind_i];
		d[1]=p_y[ind_j]-p_y[ind_i];
		d[2]=p_z[ind_j]-p_z[ind_i];

		if(j!=i){

			constante += (G * masa[j])/pow((pow(d[0],2.0)+pow(d[1],2.0)+pow(d[2],2.0)),(3.0/2.0));
			
		a=(constante * d[0]);
		b=(constante * d[1]);
		c=(constante * d[2]);
		
		*a_x=a;
		*a_y=b;
		*a_z=c;
			}
	}

	
}

int main(void){

	FILE *datos;
	int i=0, j=0; 
	int n=10;
	int fil=10, col=7;	
	float matriz_datos[fil][col];
	int let=250;
	char lineas[let];
	char *palabras;
	const char *delimiter;
	int t;

	float *masa=malloc(sizeof(float));
	float ax;
	float ay;
	float az;

	float *p_x= malloc(n*fil*sizeof(float));
	float *p_y= malloc(n*fil*sizeof(float));
	float *p_z= malloc(n*fil*sizeof(float));

	float *v_x= malloc(n*fil*sizeof(float));
	float *v_y= malloc(n*fil*sizeof(float));
	float *v_z= malloc(n*fil*sizeof(float));

	
	
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
		masa[i]=matriz_datos[i][0];

		p_x[indices(i,0,n)]=matriz_datos[i][1];
		p_y[indices(i,0,n)]=matriz_datos[i][2];
		p_z[indices(i,0,n)]=matriz_datos[i][3];
		
		v_x[indices(i,0,n)]=matriz_datos[i][4];
		v_y[indices(i,0,n)]=matriz_datos[i][5];
		v_z[indices(i,0,n)]=matriz_datos[i][6];
	}
	
	t=0;
			for (i=0;i<10;i++){	
				aceleracion(n, i, t, &ax, &ay, &az, masa, p_x, p_y, p_z);
			printf("%e\n", ax);
	}
	

		

return 0;	
}
