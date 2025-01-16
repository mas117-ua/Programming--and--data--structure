#ifndef _TABB_CALENDARIO_H_
#define _TABB_CALENDARIO_H_

#include <iostream>
#include "tvectorcalendario.h"

class TNodoABB;

class TABBCalendario {
    friend class TNodoABB;

private:
    TNodoABB *raiz;
    void InordenAux(TVectorCalendario &, int &) const;
    void PreordenAux(TVectorCalendario &, int &) const;
    void PostordenAux(TVectorCalendario &, int &) const;

public:
    TABBCalendario ();
    TABBCalendario (const TABBCalendario &);
    ~TABBCalendario ();
    TABBCalendario & operator=(const TABBCalendario &);
    bool operator==(const TABBCalendario &) const;
    bool EsVacio() const;
    bool Insertar(const TCalendario &);
    bool Borrar(const TCalendario &);
    bool Buscar(const TCalendario &) const;
    TCalendario Raiz();
    int Altura() const;
    int Nodos() const;
    int NodosHoja() const;
    TVectorCalendario Inorden() const;
    TVectorCalendario Preorden() const;
    TVectorCalendario Postorden() const;
    TVectorCalendario Niveles() const;
    friend ostream & operator<<(ostream &, TABBCalendario &);
    TABBCalendario operator+(const TABBCalendario &) const;
    TABBCalendario operator-(const TABBCalendario &) const;
};

class TNodoABB {
    friend class TABBCalendario;
private:
    TCalendario item;
    TABBCalendario iz, de;

public:
    TNodoABB ();
    TNodoABB (const TNodoABB &);
    ~TNodoABB ();
    TNodoABB & operator=(const TNodoABB &);
};

#endif
