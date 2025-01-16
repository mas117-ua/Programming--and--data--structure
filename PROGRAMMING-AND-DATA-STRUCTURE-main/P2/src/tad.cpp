#include "tcalendario.h"
#include "tabbcalendario.h"
#include "tvectorcalendario.h"
#include <iostream>
using namespace std;
/*
	2000
          \
          2003
          /  \
       2002  2004
        /
      2001
*/
int main(){
	TABBCalendario ab;

	cout << ab.Nodos() << endl;

	ab.Insertar(TCalendario(2, 3, 2000, NULL));
	ab.Insertar(TCalendario(2, 3, 2003, NULL));
	ab.Insertar(TCalendario(2, 3, 2002, NULL));
	ab.Insertar(TCalendario(2, 3, 2004, NULL));
	ab.Insertar(TCalendario(2, 3, 2001, NULL));


	cout << ab.Nodos() << endl;
	cout << ab.Inorden() << endl;
	cout << ab.Preorden() << endl;
	cout << ab.Postorden() << endl;
	cout << "Niveles: " << ab.Niveles() << endl;

	cout << "Borrando 2004: " << ab.Borrar(TCalendario(2, 3, 2004, NULL)) << endl;
/*
	2000
          \
          2003
          /
       2002  
        /
      2001
*/
	cout << ab.Nodos() << endl;
	cout << ab.Inorden() << endl;
	cout << ab.Preorden() << endl;
	cout << ab.Postorden() << endl;
	cout << "Niveles: " << ab.Niveles() << endl;


	cout << "Borrando 2003: " <<  ab.Borrar(TCalendario(2, 3, 2003, NULL)) << endl;
/*
	2000
          \
       	  2002  
           /
         2001
*/
	cout << ab.Nodos() << endl;
	cout << ab.Inorden() << endl;
	cout << ab.Preorden() << endl;
	cout << ab.Postorden() << endl;
	cout << "Niveles: " << ab.Niveles() << endl;

	cout << "Borrando 2000: " <<  ab.Borrar(TCalendario(2, 3, 2000, NULL)) << endl;
	cout << ab.Nodos() << endl;
	cout << ab.Inorden() << endl;
	cout << ab.Preorden() << endl;
	cout << ab.Postorden() << endl;
	cout << "Niveles: " << ab.Niveles() << endl;

/*
       	  2002  
           /
         2001
*/
	cout << "insertando" << endl;
	ab.Insertar(TCalendario(2, 3, 2010, NULL));
	ab.Insertar(TCalendario(2, 3, 2009, NULL));
/*
       	  2002  
           /  \
         2001  2010
	      /
            2009
*/
	cout << ab.Nodos() << endl;
	cout << ab.Inorden() << endl;
	cout << ab.Preorden() << endl;
	cout << ab.Postorden() << endl;
	cout << "Niveles: " << ab.Niveles() << endl;
	
	cout << "Borrando 2000: " <<  ab.Borrar(TCalendario(2, 3, 2002, NULL)) << endl;
/*
       	  2001  
             \
            2010
	      /
            2009
*/
	cout << ab.Nodos() << endl;
	cout << ab.Inorden() << endl;
	cout << ab.Preorden() << endl;
	cout << ab.Postorden() << endl;
	cout << "Niveles: " << ab.Niveles() << endl;

	return 0;
}
