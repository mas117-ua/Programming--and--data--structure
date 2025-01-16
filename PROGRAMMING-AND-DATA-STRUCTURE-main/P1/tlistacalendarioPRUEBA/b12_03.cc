#include "tcalendario.h"
#include "tlistacalendario.h"
#include <iostream>
using namespace std;

int main(){
	TListaCalendario lista;
	cout << "Intento borrar de la lista vacia: " << lista.Borrar(1, 1, 3000) << endl;
	
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

	for(int i = 0; i < 8; i++){
		lista.Insertar(cals[i]);
	}
	
	cout << lista << endl;
	
	cout << "Borrando anteriores a 2, 12, 2021: " << lista.Borrar(2, 12, 2021) << endl;
	cout << lista << endl;
	
	cout << "Borrando anteriores a 12, 12, 2021: " << lista.Borrar(12, 12, 2021) << endl;
	cout << lista << endl;

	cout << "Borrando anteriores a 2, 2, 2022: " << lista.Borrar(2, 2, 2022) << endl;
	cout << lista << endl;
		
	cout << "Borrando anteriores a 2, 2, 2023: " << lista.Borrar(2, 2, 2023) << endl;
	cout << lista << endl;
	
	return 0;
}


