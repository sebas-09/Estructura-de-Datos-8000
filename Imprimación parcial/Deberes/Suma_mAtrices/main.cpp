/***********************************************************************
 * Universidad de las Fuerzas Armadas Espe
 * Module:  Suma Matrices método recursivo
 * Author:  Mateo Llumigusin, Sebastian Monga
 * Fecha de creacion: 11/11/2022 11:00 am
 * Fecha de modificaci�n:  11/11/2022
 * Materia: Estructura de Datos Nrc: 8000
 ***********************************************************************/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 3
#include "Operaciones.cpp"
using namespace std;


int main(int argc, char** argv) {
	int ** mat1 = nullptr;
	int ** mat2 = nullptr;
	int ** matR = nullptr;
	Operaciones o;
	mat1=(int **)malloc (3*sizeof(int*));
	mat2=(int **)malloc (3*sizeof(int*));
	matR=(int **)malloc (3*sizeof(int*));
	for(int j=0;j<3;j++){
		*(mat1+j)=(int*)malloc(3*sizeof(int*));
		*(mat2+j)=(int*)malloc(3*sizeof(int*));
		*(matR+j)=(int*)malloc(3*sizeof(int*));
	}
	srand (time(NULL));
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			*(*(mat1+i)+j)=(int)((rand()/32768.1)*1000);
			*(*(mat2+i)+j)=(int)((rand()/32768.1)*1000);
			*(*(matR+i)+j)=0;
		}
	}
	cout<<"\n La matriz 1 es :\n";
	o.imprimirMatriz(mat1);
	cout<<"\n";
	o.imprimirMatriz(mat2);
	cout<<"\n";
	cout<<"\n La matriz R es :\n";
	o.sumaRecursivaMatrices( mat1,mat2,matR, 2, 2);
	o.imprimirMatriz(matR);
	return 0;
}