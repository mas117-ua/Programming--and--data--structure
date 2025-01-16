#ifndef _TVECTORCALENDARIO_H_
#define _TVECTORCALENDARIO_H_
#include "tcalendario.h"
#include <iostream>
using namespace std;

class TVectorCalendario{
	friend ostream &operator<<(ostream &os, const TVectorCalendario &v);
	private:
		TCalendario *c;
		int tamano;
		TCalendario err;
	public:
		TVectorCalendario();
		TVectorCalendario(int tam);
		TVectorCalendario(const TVectorCalendario &v);
		~TVectorCalendario();
		TVectorCalendario &operator=(const TVectorCalendario &vecCal);
		
		bool operator==(const TVectorCalendario &vecCal) const;
		bool operator!=(const TVectorCalendario &vecCal) const;
		
		TCalendario &operator[](int i);
		TCalendario operator[](int i) const;
		
		int Tamano() const;
		int Ocupadas() const;
		bool ExisteCal(const TCalendario &cal) const;
		
		void MostrarMensajes(int d, int m, int a);
		bool Redimensionar(int t);
};

#endif
