#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include "Template.cpp"
//char *ingresarDatosEnteros(char *);

/*template <typename T>
class Numero{
	public: 
		void setNum(T n);
		T getNum() const;
	private:
		T num;	
};
template <typename T>
void Numero<T>::setNum(T n){
		this->num=n;
}
template <typename T>
T Numero<T>::getNum()const{
		return this->num;
}*/

//Función ingreso de datos
/*char *ingresarDatosEnteros(char const *msj){
	char *dato=new char[10];
	char c;
	int i=0;
	printf("%s\n",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}
	}
	dato[i]='\0';
	return dato;
}*/




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