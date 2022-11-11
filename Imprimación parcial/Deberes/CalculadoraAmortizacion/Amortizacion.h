#include <windows.h>
#include <locale.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

COORD coord = { 0, 0 };
class Amortizacion {
	public: 
	void metodo_usa();
	
};
void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char *ingresarDatosEnteros(char const *msj){
	char *dato=new char[10];
	char c;
	int i=0 , p=0;
	printf("%s\n",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}
	}
	dato[i]='\0';
	return dato;
}

char *ingresarDatosFlotantes(char const *msj){
	char *dato=new char[10];
	char c;
	int i=0 , p=0;
	printf("%s\n",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}
		else if(c == '.' && p == 0){
			printf("%c",c);
			dato[i++]=c;
			p--;
		}
	}
	dato[i]='\0';
	return dato;
}


int validarFecha(int mes,int dia){
	int feriado=0;
	if(mes==1 || mes==3){
		if(dia==1){
			feriado=1;
		}
	}
	if(mes==5){
		if(dia==1 || dia==24){
			feriado=1;
		}
	}
	if(mes==8){
		if(dia==10){
			feriado=1;
		}
	}
	if(mes==10){
		if(dia==9){
			feriado=1;
		}
	}
	if(mes==12){
		if(dia==25){
			feriado=1;
		}
	}
	if(mes==2){
		if(dia==28){
			feriado=1;
		}
	}
	if(mes==4){
		if(dia==15){
			feriado=1;
		}
	}
	if(mes==11){
		if(dia==2||dia==3){
			feriado=1;
		}
	}
	return feriado;
}
void metodo_usa() {
    system("cls");

    //Titulo del metodo
    gotoxy(35, 1); printf("............................................\n");
    gotoxy(35, 2); printf(".           TABLA AMORTIZACION              .\n");
    gotoxy(35, 3); printf("............................................\n");
	char dato[10];//validacion de datos
    float a = 0; //cuota periodica de interes
    float a_ultima; //cuota del ultimo año; el Co mas los inetereses
    float tasa_usa; //tasa de interes del periodo
    float capital; //capital inicial prestado (Co)
    int tiempo; //tiempo en anio del prestamo
    int i; //contador para el bucle
    int dia, anio,fecha_correcta,mes,feriado; //Fecha
	
    //Ingresando la fecha del prestamo
    do{
    	do{
		

        	cout << "\n En que fecha desea realizar el prestamo?\n"; 
			strcpy(dato,ingresarDatosEnteros("Dia: "));
			dia=atoi(dato);
			strcpy(dato,ingresarDatosEnteros("\nMes: "));
			mes=atoi(dato);		
			strcpy(dato,ingresarDatosEnteros("\nAnio: "));
			anio=atoi(dato);
        	cout << endl;
        	fecha_correcta = 0;
        	feriado = 0;
        	if ( mes >= 1 && mes <= 12 )
    	{
        	switch ( mes )
        	{
            	case  1 : 
            	case  3 : 	
            	case  5 : 
            	case  7 : 
            	case  8 : 
            	case 10 : 
            	case 12 : if ( dia >= 1 && dia <= 31 )
                          fecha_correcta = 1;	    
                          
                       break;  
                      

            	case  4 :
            	case  6 :
            	case  9 :
            	case 11 : if ( dia >= 1 && dia <= 30 )
                         	fecha_correcta = 1;
                      		break;

            	case  2 : if ( anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0 )
                      	{
                          	if ( dia >= 1 && dia <= 29 )
                             	 fecha_correcta = 1;
                      	}
                      	else
                          	if ( dia >= 1 && dia <= 28 )
                              	fecha_correcta = 1;
        	}
    	}
		feriado=validarFecha(mes,dia);
    	/* Llegados a este punto, según el valor de fecha_correcta,
       	por pantalla se mostrará un mensaje u otro. */
   		 	if ( fecha_correcta == 1 && feriado == 0){	 	
   		 			printf( "\n   FECHA CORRECTA " );				
				}else
				{
					printf( "\n   FECHA INCORRECTA O ES FERIADOS" );			    		
			}   	
    		getch(); /* Pausa */
    	
	}while(fecha_correcta != 1);
	
}while(feriado != 0 );
    //Ingrea y lee el monto a prestar (Co)
 		strcpy(dato,ingresarDatosFlotantes("\n [#] Ingresa el monto a prestar: "));
		capital=atof(dato);   	
    //Consistenciar por si el usuario coloca numero negativo
        if (capital < 0) {
            metodo_usa();
        }

    //tiempo en anios (recordar que el metodo funciona de esta manera, cuota anual)
		strcpy(dato,ingresarDatosEnteros("\n En cuanto tiempo piensa pagarlo (en anios): "));
		tiempo=atoi(dato);
    //tasa de interes del periodo anterior
 		strcpy(dato,ingresarDatosFlotantes("\n Cual sera la tasa de interes?: "));
		tasa_usa=atof(dato);   
    //Limpiando consola para el proceso de mostrado
        system("cls");

    //Titulo del metodo
        gotoxy(35, 1); printf("............................................\n");
        gotoxy(35, 2); printf(".            TABLA AMORTIZACION              .\n");
        gotoxy(35, 3); printf("............................................\n");


    //Mostrado de datos iniciales del cliente
        gotoxy(80, 5);
        cout << dia << " de " << mes << " de " << anio << "\n\n";

        gotoxy(14, 7);
        cout << "Tabla del prestamo a pagar de S/. " << capital << " al " << tasa_usa << "% anual, durante " << tiempo << " anios.\n";

    //Mostrando tabla de cotizaciones
    	//Borde  - arriba (top)
		gotoxy(14, 8);
	    for (i = 0; i < 90; i++) {
	        cout << ".";
	    }
	    cout << "\n\n";
		
		//Menu de muestra
	    gotoxy(24, 10);
	    cout << "Anio" << "\t\t" << "Anualidad" << "\t\t" << "Interes" << "\t\t\t" << "Fecha de pago" << endl;
		
		//Borde - medio (middle)
	    gotoxy(14, 12);
	    for (i = 0; i < 90; i++) {
	        cout << ".";
	    }
	    cout << "\n\n";
		
		//Informacion sobre la amortizacionn
	    for (i = 0; i < tiempo - 1; i++) {
	        a = capital * tasa_usa/100;
	
	        gotoxy(25, 14 + i);
	        cout << i + 1 << "\t\t" << a << "\t\t\t" << a << "\t\t\t" << anio + i + 1 << endl;
	    }
	    
	    //Ultimo periodo de amortizacionn
	    a_ultima = a + capital;
	    gotoxy(25, 14 + tiempo - 1);
	    cout << i + 1 << "   \t\t" << a_ultima << "     \t\t" << a << "\t\t\t" << anio + i + 1 << endl;
		
		//Borde - abajo (bottom)
	    gotoxy(14, 14 + tiempo + 1);
	    for (i = 0; i < 90; i++) {
	        cout << ".";
	    }
	    cout << "\n\n";
}