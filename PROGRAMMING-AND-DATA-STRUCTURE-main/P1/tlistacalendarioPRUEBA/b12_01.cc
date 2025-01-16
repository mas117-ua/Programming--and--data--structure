#include "tcalendario.h"
#include "tlistacalendario.h"
#include <iostream>
using namespace std;

int main(){
	TCalendario cals[] = {
		TCalendario(2, 2, 2022, NULL),
		TCalendario(2, 4, 2022, NULL),
		TCalendario(1, 1, 2022, NULL),
		TCalendario(12, 12, 2021, NULL),
		TCalendario(12, 12, 2021, "barco"),
		TCalendario(12, 12, 2021, "avion")};
	TListaCalendario lista;
	
	// 111111 (los 6 bools de insertar)
	for(int i = 0; i < 6; i++){
		cout << lista.Insertar(cals[i]);
	}
	cout << endl << lista << endl;
	
	TListaCalendario * copia = new TListaCalendario(lista);
	cout << *copia << endl;
	delete copia;
	copia = NULL;
	cout << "lista original despues de liberar la copia:  " << lista << endl;
	
	TListaCalendario lista2;
	
	for(int i = 0; i < 3; i++){
		lista2.Insertar(cals[i]);
	}
	cout << lista2 << endl;
	lista2 = lista;
	cout << lista2 << endl;
		
	TListaCalendario vacia;
	lista2 = vacia;
	cout << "despues de asignarle vacio: " << lista2 << endl;
	
	return 0;
}


