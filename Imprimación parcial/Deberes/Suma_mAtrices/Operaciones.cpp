/***********************************************************************
 * Universidad de las Fuerzas Armadas Espe
 * Module:  Suma Matrices método recursivo
 * Author:  Mateo Llumigusin, Sebastian Monga
 * Fecha de creacion: 11/11/2022 11:00 am
 * Fecha de modificaci?n:  11/11/2022
 * Materia: Estructura de Datos Nrc: 8000
 ***********************************************************************/
#include "operaciones.h"
#include <conio.h>
#include <cstdio>
#include <iostream>
void Operaciones::sumaRecursivaMatrices( int **mat1, int **mat2, int **matR, int f, int c){
	if ((f>=0) && (c>=0)){
		*(*(matR+f)+c)=*(*(mat1+f)+c) + *(*(mat2 +f)+c);
		sumaRecursivaMatrices( mat1,mat2,matR,f-1,c);
		sumaRecursivaMatrices( mat1,mat2,matR,f,c-1);
	}
}

void Operaciones::imprimirMatriz(int **mat){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%d",*(*(mat+i)+j));
			printf("%*s",j+5,"");
		}
		std::cout<<"\n";
	}	
}