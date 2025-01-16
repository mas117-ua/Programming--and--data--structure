#ifndef _TLISTACALENDARIO_H_
#define _TLISTACALENDARIO_H_
#include "tcalendario.h"
#include <iostream>
using namespace std;
class TNodoCalendario;
class TListaPos;

class TListaCalendario{
	friend ostream &operator<<(ostream &os, const TListaCalendario &lista);
	private:
		TNodoCalendario *primero;
		void Liberar();
	public:
		TListaCalendario();
		TListaCalendario(const TListaCalendario &listaCal);

		~TListaCalendario();
		TListaCalendario &operator=(const TListaCalendario &listaCal);
		bool operator==(const TListaCalendario &listaCal) const;
		bool operator!=(const TListaCalendario &listaCal) const;
		TListaCalendario operator+(const TListaCalendario &listaCal) const;
		TListaCalendario operator-(const TListaCalendario &listaCal) const;
		bool Insertar(const TCalendario &cal);

		
		bool Borrar(const TCalendario &cal);
		bool Borrar(const TListaPos &p);
		bool Borrar(int d, int m, int a);
		 
		
		TCalendario Obtener(const TListaPos &lp) const;
		bool Buscar(const TCalendario &c) const;
		int Longitud() const;


		
		bool EsVacia() const;
		TListaPos Ultima() const;
		TListaPos Primera() const;
		TListaCalendario ExtraerRango(int n1, int n2);
		TListaCalendario SumarSubl(int I_L1, int F_L1, const TListaCalendario &L2, int I_L2, int F_L2) const;
};

class TNodoCalendario{
	friend class TListaPos;
	friend ostream &operator<<(ostream &os, const TListaCalendario &lista);
	friend class TListaCalendario;
	private:
		TCalendario c;
		TNodoCalendario *siguiente;
	public:
		TNodoCalendario();
		TNodoCalendario(const TNodoCalendario &n);
		~TNodoCalendario();
		TNodoCalendario &operator=(const TNodoCalendario &listaCal);
};

class TListaPos{
	friend class TListaCalendario;
	private:
		TNodoCalendario *pos;
	public:
		TListaPos();
		TListaPos(const TListaPos &p);
		~TListaPos();
		TListaPos &operator=(const TListaPos &listaCal);
		bool operator==(const TListaPos &listaCal) const;
		bool operator!= (const TListaPos &listaCal) const;
		TListaPos Siguiente() const;
		bool  EsVacia() const;
};

#endif
