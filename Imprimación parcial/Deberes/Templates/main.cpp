#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include "Ingreso.h"

int main(int argc, char** argv) {
	
	Numero<int> entero;
	Numero<float> flotante;
	Numero<double> real;
	int valor;
	char dato[10];
	strcpy(dato,ingresarDatosEnteros("Ingrese el valor entero"));
	valor=atoi(dato);
	entero.setNum(valor);
	
	flotante.setNum(3.2f);
	real.setNum(3.14151619999);
	std::cout<<"\n Numero de tipo int: "<<entero.getNum();
	std::cout<<"\n Numero de tipo float: "<<flotante.getNum()<<"f";
	std::cout<<"\n Numero de tipo double: "<<real.getNum()<<std::endl;
	return 0;
}