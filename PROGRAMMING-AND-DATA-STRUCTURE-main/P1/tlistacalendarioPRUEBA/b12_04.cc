#include "tcalendario.h"
#include "tlistacalendario.h"
#include <iostream>
using namespace std;

int main(){
	TListaCalendario lista;
	TCalendario cals[] = {
		TCalendario(2, 2, 2022, NULL), // 0
		TCalendario(2, 4, 2022, NULL), // 1
		TCalendario(1, 1, 2022, NULL), // 2
		TCalendario(12, 12, 2021, NULL), //3
		TCalendario(12, 12, 2021, "barco"), // 4
		TCalendario(2, 12, 2021, "avion"), // 5
		TCalendario(12, 12, 2023, NULL), // 6
		TCalendario(12, 12, 2022, "barco"), // 7
		TCalendario(12, 12, 2020, "avion") // 8
	};
	TListaCalendario lista2;
	for(int i = 0; i < 8; i++){
		lista.Insertar(cals[i]);
	}
	
	for(int i = 0; i < 8; i += 2){
		lista2.Insertar(cals[i]);
	}
	
	TListaCalendario resultado = lista - lista2;
	cout << lista << endl;
	cout << "-" << endl;
	cout << lista2 << endl;
	cout << "-----------------" << endl;
	cout << resultado << endl;
	cout << endl << endl;
	
	
	cout << lista2 << endl;
	cout << "-" << endl;
	cout << lista << endl;
	cout << "-----------------" << endl;
	cout << lista2 - lista << endl;
	cout << endl << endl;
	
	
	TListaCalendario vacia;
	cout << "probando con vacias: " << endl;
	cout << "vacia - vacia = " << vacia - vacia << endl;
	cout << "lista - vacia = " << lista - vacia << endl;
	cout << "vacia - lista = " << vacia - lista << endl;
	
	
	return 0;
}


