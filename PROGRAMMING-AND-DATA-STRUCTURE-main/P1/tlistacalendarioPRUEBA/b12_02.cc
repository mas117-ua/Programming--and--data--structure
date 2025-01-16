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
	
	for(int i = 0; i < 6; i++){
		lista.Insertar(cals[i]);
	}
	cout << lista << endl;
	
	cout << "primero: " << lista.Borrar(cals[3]) << endl;
	cout << lista << endl;
	cout << "ultimo: " << lista.Borrar(cals[1]) << endl;
	cout << lista << endl;
	cout << "inserto al prin.: " << lista.Insertar(TCalendario(12, 12, 2021, "alentador")) << endl;
	cout << lista << endl;
	cout << "borro de en medio: " << lista.Borrar(TCalendario(12, 12, 2021, "avion")) << endl;
	cout << lista << endl;
	
	return 0;
}


