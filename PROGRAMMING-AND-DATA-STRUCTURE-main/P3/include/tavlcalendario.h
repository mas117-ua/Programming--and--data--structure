#ifndef _TAVLCALENDARIO_
#define _TAVLCALENDARIO_
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include <iostream>
using namespace std;

class TNodoAVL;

class TAVLCalendario{
    friend ostream &operator<<(ostream &os, const TAVLCalendario &avl);
    private:
        TNodoAVL *raiz;
        void InordenAux(TVectorCalendario &, int &) const;
        void PreordenAux(TVectorCalendario &, int &) const;
        void PostordenAux(TVectorCalendario &, int &) const;

        void RotacionLL();

        void RotacionRR();

        void RotacionLR();

        void RotacionRL();
                bool BorrarAux(const TCalendario &cal, bool &decrece);

                TCalendario TCalMax() const;

            public:
                TAVLCalendario();
                TAVLCalendario(const TAVLCalendario &);
                ~TAVLCalendario();
                TAVLCalendario &operator=(const TAVLCalendario &);
                bool operator==(const TAVLCalendario &) const;
                bool operator!=(const TAVLCalendario &) const;
                bool EsVacio() const;
                bool Insertar(const TCalendario &);
                bool InsertarAux(const TCalendario &cal, bool &crece);
                bool Buscar(const TCalendario &) const;
                int Altura() const;
                int Nodos() const;
                int NodosHoja() const;
                TVectorCalendario Inorden() const;
                TVectorCalendario Preorden() const;
                TVectorCalendario Postorden() const;
                bool Borrar(const TCalendario &);
                TCalendario Raiz() const;
                friend ostream &operator<<(ostream &os, const TAVLCalendario &); 
};

class TNodoAVL{
    friend class TAVLCalendario;
    private:
        TCalendario item;
        TAVLCalendario iz, de;
        int fe;
    public:
        TNodoAVL();
        TNodoAVL(const TNodoAVL &nodo);
        ~TNodoAVL();

        TNodoAVL &operator=(const TNodoAVL &);
};

#endif