#include "tlistacalendario.h"

TListaCalendario TListaCalendario::operator+(const TListaCalendario &listaCal) const {
    TListaCalendario copia(*this); 
    TNodoCalendario *nodo = listaCal.primero;
    while (nodo != NULL) {
        copia.Insertar(nodo->c);
        nodo = nodo->siguiente;
    }

    return copia;
}

TListaCalendario TListaCalendario::operator-(const TListaCalendario &listaCal) const {
    TListaCalendario copia; 

    TNodoCalendario *nodo = primero;
    while (nodo != NULL) {
        
        if (!listaCal.Buscar(nodo->c)) {
            copia.Insertar(nodo->c); 
        }
        nodo = nodo->siguiente;
    }

    return copia;
}

bool TListaCalendario::Borrar(const TListaPos &p) {
    if (!p.EsVacia()) {
        TNodoCalendario *nodo = p.pos;
        TNodoCalendario *anterior = NULL;

        while (nodo != NULL && nodo != primero) {
            anterior = nodo;
            nodo = nodo->siguiente;
        }
        if (nodo != NULL) {
            if (anterior == NULL) {
                primero = nodo->siguiente;
            } else {
                anterior->siguiente = nodo->siguiente;
            }
            delete nodo;
            return true;
        }
    }

    return false;
}

bool TListaCalendario::Borrar(int d, int m, int a) {
    if (primero == NULL) 
        return false;

    bool borrado = false;
    TNodoCalendario *actual = primero;
    TNodoCalendario *anterior = NULL;

    while (actual != NULL) {
        if (actual->c.Dia() == d && actual->c.Mes() == m && actual->c.Anyo() == a) {
            if (anterior == NULL) 
                primero = actual->siguiente;
            else
                anterior->siguiente = actual->siguiente;

            delete actual;
            actual = NULL; 
            borrado = true;
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    return borrado;
}

TListaCalendario::TListaCalendario(const TListaCalendario &listaCal) {
    primero = NULL;
    TNodoCalendario *nodo = listaCal.primero;
    while (nodo != NULL) {
        TCalendario cal = nodo->c;
        Insertar(cal);
        nodo = nodo->siguiente;
    }
    

}

bool TListaCalendario::Borrar(const TCalendario &cal) {
    TNodoCalendario *nodo = primero;
    TNodoCalendario *anterior = NULL;

    while (nodo != NULL && !(nodo->c == cal)) {
        anterior = nodo;
        nodo = nodo->siguiente;
    }

    if (nodo != NULL) {
        if (anterior == NULL) {
            primero = nodo->siguiente;
        } else {
            anterior->siguiente = nodo->siguiente;
        }
        delete nodo;
        return true;
    }

    return false;
}

TListaCalendario &TListaCalendario::operator=(const TListaCalendario &listaCal) {

    if (this != &listaCal) {
        TNodoCalendario *ptl, *ptb;
        ptl = primero;
        while (ptl) {
            ptb = ptl;
            ptl = ptl->siguiente;
            delete ptb;
        }
        primero = NULL;

        TNodoCalendario *nodo = listaCal.primero;
        while (nodo != NULL) {
            TCalendario cal = nodo->c;
            Insertar(cal);
            nodo = nodo->siguiente;
        }
    }
    return *this;
}
TListaCalendario::~TListaCalendario() {
    TNodoCalendario *ptl = primero;
    TNodoCalendario *ptb;

    if (ptl) {
        do {
            ptb = ptl;
            ptl = ptl->siguiente;
            delete ptb;
        } while (ptl);
    }

    primero = NULL;
}



TListaPos TListaCalendario::Ultima() const {
    TListaPos ultimaPos;

    TNodoCalendario *actual = primero;
    TNodoCalendario *anterior = NULL;
    while (actual != NULL) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (anterior != NULL) {
        ultimaPos.pos = anterior;
    }

    return ultimaPos;
}


TListaPos::TListaPos(const TListaPos &listaCal) {
    pos = listaCal.pos;
}

TListaPos::TListaPos() {
    pos=NULL;
}

TListaPos::~TListaPos() {
    pos = NULL;
}

bool TListaPos::EsVacia() const {
    return (pos == NULL);
}


bool TListaCalendario::EsVacia() const {
    return (primero == NULL);
}

TListaPos &TListaPos::operator=(const TListaPos &listaCal) {
    if (this != &listaCal) {
        pos = listaCal.pos;
    }
    return *this;
}

bool TListaPos::operator==(const TListaPos &listaCal) const {
    return (pos == listaCal.pos);
}

bool TListaPos::operator!=(const TListaPos &listaCal) const {
    return !(*this == listaCal);
}

TListaPos TListaCalendario::Primera() const {
    TListaPos primeraPos;

    if (primero != NULL) {
        primeraPos.pos = primero;
    }

    return primeraPos;
}

TListaPos TListaPos::Siguiente() const {
    TListaPos siguientePos;
    if (pos != NULL && pos->siguiente != NULL) {
        siguientePos.pos = this->pos->siguiente;
    }
    return siguientePos;
}



TCalendario TListaCalendario::Obtener(const TListaPos &p) const {
    if (p.EsVacia()) {
        return TCalendario(); 
    } else {
        return p.pos->c; 
    }
}

bool TListaCalendario::Buscar(const TCalendario &c) const {
    TNodoCalendario *actual = primero;

    while (actual != NULL) {
        if (actual->c == c) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}


int TListaCalendario::Longitud() const {
    int longitud = 0;
    TNodoCalendario *actual = primero;
    while (actual != NULL) {
        longitud++;
        actual = actual->siguiente;
    }

    return longitud;
}


TListaCalendario::TListaCalendario() {
    primero = NULL;
}

bool TListaCalendario::Insertar(const TCalendario &cal) {
    TNodoCalendario *nuevoNodo = new TNodoCalendario();
    nuevoNodo->c = cal;
    nuevoNodo->siguiente = NULL;
    if (primero == NULL) {
        primero = nuevoNodo;
        return true;
    }
    if (cal < primero->c) {
        nuevoNodo->siguiente = primero;
        primero = nuevoNodo;
        return true;
    }
    TNodoCalendario *actual = primero;
    while (actual->siguiente != NULL && actual->siguiente->c < cal) {
        actual = actual->siguiente;
    }
    if (actual->siguiente != NULL && actual->siguiente->c == cal) {
        delete nuevoNodo; 
        return false;
    }
    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;

    return true;
}


bool TListaCalendario::operator==(const TListaCalendario &listaCal) const {
    TNodoCalendario *nodo1 = primero;
    TNodoCalendario *nodo2 = listaCal.primero;

    while (nodo1 != NULL && nodo2 != NULL) {
        if (nodo1->c != nodo2->c) {
            return false;
        }
        nodo1 = nodo1->siguiente;
        nodo2 = nodo2->siguiente;
    }
    return (nodo1 == NULL && nodo2 == NULL);
}

bool TListaCalendario::operator!=(const TListaCalendario &listaCal) const {
    return !(*this == listaCal);

}



ostream &operator<<(ostream &os, const TListaCalendario &lista) {
    TNodoCalendario *actual = lista.primero;

    os << "<";

    while (actual != NULL) {
        os << actual->c;

        if (actual->siguiente != NULL) {
            os << " ";
        }

        actual = actual->siguiente;
    }

    os << ">";

    return os;
}






TNodoCalendario::~TNodoCalendario() {
    siguiente = NULL;
}

TNodoCalendario::TNodoCalendario() {
    siguiente = NULL;
}

TNodoCalendario::TNodoCalendario(const TNodoCalendario &n) {

    c = n.c;
    siguiente = n.siguiente;
}

TNodoCalendario &TNodoCalendario::operator=(const TNodoCalendario &listaCal) {
    if (this != &listaCal) {
        c = listaCal.c;
        siguiente = listaCal.siguiente;
    }
    return *this;
}
TListaCalendario TListaCalendario::ExtraerRango(int n1, int n2) {
    TListaCalendario lista;
    int posicion = 1; 
    TNodoCalendario *ptl = primero;
    TNodoCalendario *pta = NULL;
    
    do {
        if (posicion >= n1 && posicion <= n2) {
            lista.Insertar(ptl->c);
            if (ptl == primero) {
                primero = primero->siguiente;
                delete ptl;
                ptl = primero;
            } else {
                pta->siguiente = ptl->siguiente;
                delete ptl;
                ptl = pta->siguiente;
            }
        } else {
            pta = ptl;
            ptl = ptl->siguiente;
        }
        posicion++;
    } while (ptl);

    return lista;
}



TListaCalendario TListaCalendario::SumarSubl(int I_L1, int F_L1, const TListaCalendario &L2, int I_L2, int F_L2) const {
    TListaCalendario resultado;
    TNodoCalendario *ptl = this->primero;
    int pos = 1;
    do {
        if (pos >= I_L1 && pos <= F_L1) {
            resultado.Insertar(ptl->c);
        }
        pos++;
        ptl = ptl->siguiente;
    } while (ptl);

    pos = 1;
    ptl = L2.primero;
    do {
        if (pos >= I_L2 && pos <= F_L2) {
            resultado.Insertar(ptl->c);
        }
        pos++;
        ptl = ptl->siguiente;
    } while (ptl);

    return resultado;
}

