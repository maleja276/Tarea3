
/* Archivo datos planetas*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 3.141519
#define G 39.476568
#define n 500


//Definir las funciones 

int indices(int i, int j);
void aceleracion(int i, float ax, float ay, float az, float *masa, float *p_x, float *p_y, float *p_z);
void vel_media(int i, float dt, float *v_x, float *v_y, float *v_z, float *vm_x, float *vm_y, float *vm_z, float ax, float ay, float az);
void posicion(int i, float dt, float *vm_x, float *vm_y, float *vm_z, float *p_x, float *p_y, float *p_z );
void velocidad(int i, float dt, float *vm_x, float *vm_y, float *vm_z, float *v_x, float *v_y, float *v_z, float ax, float ay, float az );



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
	int dt=0.5;

	//Deficion Matrices

	float ax;
	float ay;
	float az;
	float *masa=malloc(10*sizeof(float));

	float *p_x= malloc(n*fil*sizeof(float));
	float *p_y= malloc(n*fil*sizeof(float));
	float *p_z= malloc(n*fil*sizeof(float));

	float *v_x= malloc(n*fil*sizeof(float));
	float *v_y= malloc(n*fil*sizeof(float));
	float *v_z= malloc(n*fil*sizeof(float));

	float *vm_x= malloc(n*sizeof(float));
	float *vm_y= malloc(n*sizeof(float));
	float *vm_z= malloc(n*sizeof(float));
	
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
		masa[i]=matriz_datos[i][0];

		p_x[indices(i,0)]=matriz_datos[i][1];
		p_y[indices(i,0)]=matriz_datos[i][2];
		p_z[indices(i,0)]=matriz_datos[i][3];
		
		v_x[indices(i,0)]=matriz_datos[i][4];
		v_y[indices(i,0)]=matriz_datos[i][5];
		v_z[indices(i,0)]=matriz_datos[i][6];
	}

	
//	for (i=0;i<10;i++){

//		{
//		printf("%e\n", v_x[indices(i,0)]);
//		}
//	}

	for (i=0; i<10; i++){

		ax, ay, az = 0;
		aceleracion(i, ax, ay, az, masa, p_x, p_y, p_z);
		vel_media(i, dt, v_x, v_y, v_z, vm_x, vm_y, vm_z, ax, ay, az);
		posicion(i, dt, vm_x, vm_y, vm_z, p_x, p_y, p_z );
		velocidad(i, dt, vm_x, vm_y, vm_z, v_x, v_y, v_z, ax, ay, az );

	}

		for (i=0;i<10;i++){
			for (j=0;j<n;j++){	
				printf("%e %e %e\n", p_x[indices(i,j)],p_y[indices(i,j)],p_z[indices(i,j)] );
		}
	

	}
	

}

int indices(int i, int j){
	
	return (i*n+j);
}


void aceleracion(int i, float ax, float ay, float az, float *masa, float *p_x, float *p_y, float *p_z)

{
	
	float constante;
	float dir_x;
	float dir_y;
	float dir_z;
	int ind_j;
	int ind_i;
	int j=0;
	int t;
	double *d=malloc(3*sizeof(double));

	for(t=1;t<n;t++){ 

		for(j=0;j<10;j++){

			ind_j=(n*j+t);
			ind_i=(n*i+t);

			d[0]=p_x[ind_j]-p_x[ind_i];
			d[1]=p_y[ind_j]-p_y[ind_i];
			d[2]=p_z[ind_j]-p_z[ind_i];

			if(j!=i){

				constante += (G * masa[j])/pow((pow(d[0],2.0)+pow(d[1],2.0)+pow(d[2],2.0)),(3.0/2.0));
				

			ax+=constante * d[0];
			ay+=constante * d[1];
			az+=constante * d[2];
				}
		}
	}
	
}

void vel_media(int i, float dt, float *v_x, float *v_y, float *v_z, float *vm_x, float *vm_y, float *vm_z, float ax, float ay, float az){

	int t;
	int ind_i;

	for(t=0;t<n;t++){

		ind_i=(n*i+t);

		vm_x[t]=v_x[ind_i]+0.5*ax*dt;
		vm_y[t]=v_y[ind_i]+0.5*ay*dt;
		vm_z[t]=v_z[ind_i]+0.5*az*dt;

	}

}

void posicion(int i, float dt, float *vm_x, float *vm_y, float *vm_z, float *p_x, float *p_y, float *p_z ){

	int t;
	int ind_i;

	for(t=0;t<n;t++){

		ind_i=(n*i+t);

		p_x[ind_i+1]=p_x[ind_i]+vm_x[t]*dt;
		p_y[ind_i+1]=p_y[ind_i]+vm_y[t]*dt;
		p_z[ind_i+1]=p_z[ind_i]+vm_z[t]*dt;
	}	
}


void velocidad(int i, float dt, float *vm_x, float *vm_y, float *vm_z, float *v_x, float *v_y, float *v_z, float ax, float ay, float az ){

	int t;
	int ind_i;

	for(t=0;t<n;t++){

		ind_i=(n*i+t);

		v_x[ind_i+1]=vm_x[t]+ 0.5*ax*dt;
		v_y[ind_i+1]=vm_y[t]+ 0.5*ay*dt;
		v_z[ind_i+1]=vm_z[t]+ 0.5*az*dt;	
	}

}
