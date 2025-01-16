#ifndef _TCALENDARIO_
#define _TCALENDARIO_
#include <iostream>
using namespace std;

class TCalendario{
	friend TCalendario operator+(int izq, const TCalendario &tcal);
	friend TCalendario operator-(int izq, const TCalendario &tcal);
	friend ostream &operator<<(ostream &os, const TCalendario &cal);
	private:
		char *mens;
		int dia, mes, anyo;
		int DiasMes(int mes, int anyo) const;
	public:
		
		TCalendario();
		TCalendario(int dia, int mes, int anyo, const char *mens);
		TCalendario(const TCalendario &cal);
		TCalendario &operator=(const TCalendario &tcal);
		~TCalendario();
		TCalendario operator++(int);
		TCalendario &operator++();
	
		TCalendario operator--(int);
		TCalendario &operator--();
		TCalendario operator+(int tcal) const;
		TCalendario operator-(int tcal) const;
		bool operator==(const TCalendario &tcal) const;
		bool operator!=(const TCalendario &tcal) const;
		bool operator>(const TCalendario &tcal) const;
		bool operator<(const TCalendario &tcal) const;
		
		int Dia() const;
		int Mes() const;
		int Anyo() const;
		char *mensaje() const;
		bool EsVacio() const;
		
		bool ModFecha(int, int, int);
		bool ModMensaje(char *);
};

#endif
