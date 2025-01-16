#include "tavlcalendario.h"

TNodoAVL::TNodoAVL(){
    fe = 0;
}

TNodoAVL::TNodoAVL(const TNodoAVL &nodo) : item(nodo.item), iz(nodo.iz), de(nodo.de), fe(nodo.fe) {}

TNodoAVL::~TNodoAVL() {}

TNodoAVL &TNodoAVL::operator=(const TNodoAVL &nodo) {
    if (this != &nodo) {
        item = nodo.item;
        iz = nodo.iz;
        de = nodo.de;
        fe = nodo.fe;
    }
    return *this;
}


TAVLCalendario::TAVLCalendario(){
    raiz = NULL;
}

TAVLCalendario::TAVLCalendario(const TAVLCalendario &arbolAvl) {
    if (arbolAvl.raiz != NULL) {
        raiz = new TNodoAVL();
        *raiz = *arbolAvl.raiz;
    }
}

TAVLCalendario::~TAVLCalendario() {
    if (raiz != NULL) {
        delete raiz;
        raiz = NULL;
    }
}

TAVLCalendario &TAVLCalendario::operator=(const TAVLCalendario &arbolAvl) {
    if (this != &arbolAvl) {
        if (raiz != NULL) {
            delete raiz;
            raiz = NULL;
            //se podria hacer con el destructor
        }
        if (arbolAvl.raiz != NULL) {
            raiz = new TNodoAVL();
            *raiz = *arbolAvl.raiz;
        }
    }
    return *this;
}

bool TAVLCalendario::operator==(const TAVLCalendario &arbolAvl) const {
    return Inorden() == arbolAvl.Inorden();
}

bool TAVLCalendario::operator!=(const TAVLCalendario &arbolAvl) const {
    return Inorden() != arbolAvl.Inorden();
}

bool TAVLCalendario::EsVacio() const {
    return raiz == NULL;
}

bool TAVLCalendario::Buscar(const TCalendario &tcalendario) const {
    if (raiz == NULL) {
        return false;
    } else {
        if (raiz->item == tcalendario) {
            return true;
        } else if (tcalendario > raiz->item) {
            return raiz->de.Buscar(tcalendario);
        } else {
            return raiz->iz.Buscar(tcalendario);
        }
    }
}


int TAVLCalendario::Altura() const {
    if(raiz == nullptr){
        return 0;
    } else{
        return 1 + max(raiz->iz.Altura(), raiz->de.Altura());
    }
}

int TAVLCalendario::Nodos() const {
    int nodos = 0;
    if (raiz != NULL) {
        nodos = 1 + raiz->iz.Nodos() + raiz->de.Nodos();
    }
    return nodos;    
}

int TAVLCalendario::NodosHoja() const {
    int numNodoHoja = 0;
    if(raiz != nullptr){
        if(raiz->iz.raiz == nullptr && raiz->de.raiz == nullptr){
            numNodoHoja = 1;
        }else{
            numNodoHoja = raiz->iz.NodosHoja() + raiz->de.NodosHoja();
        }
    }
    return numNodoHoja;
}

TVectorCalendario TAVLCalendario::Inorden() const {
    int pos = 1;
    TVectorCalendario vec(Nodos());
    InordenAux(vec, pos);
    return vec;
}

TVectorCalendario TAVLCalendario::Preorden() const {
    int pos = 1;
    TVectorCalendario vec(Nodos());
    PreordenAux(vec, pos);
    return vec;
}

TVectorCalendario TAVLCalendario::Postorden() const {
    int pos = 1;
    TVectorCalendario vec(Nodos());
    PostordenAux(vec, pos);
    return vec;
}

void TAVLCalendario::InordenAux(TVectorCalendario &vec, int &pos) const {
    if (raiz != NULL) {
        raiz->iz.InordenAux(vec, pos);
        vec[pos] = raiz->item;
        pos++;
        raiz->de.InordenAux(vec, pos);
    }
}

void TAVLCalendario::PreordenAux(TVectorCalendario &vec, int &pos) const {
    if (raiz != NULL) {
        vec[pos] = raiz->item;
        pos++;
        raiz->iz.PreordenAux(vec, pos);
        raiz->de.PreordenAux(vec, pos);
    }
}

void TAVLCalendario::PostordenAux(TVectorCalendario &vec, int &pos) const {
    if (raiz != NULL) {
        raiz->iz.PostordenAux(vec, pos);
        raiz->de.PostordenAux(vec, pos);
        vec[pos] = raiz->item;
        pos++;
    }
}

// Rotaciones
void TAVLCalendario::RotacionLL() {
    TNodoAVL *nodoAux = raiz->iz.raiz;
    raiz->iz.raiz = nodoAux->de.raiz;
    nodoAux->de.raiz = raiz;
    if (nodoAux->fe == -1) {
        raiz->fe = 0;
        nodoAux->fe = 0;
    } else {
        raiz->fe = -1;
        nodoAux->fe = 1;
    }
    raiz = nodoAux;
}

void TAVLCalendario::RotacionRR() {
    TNodoAVL *nodoAux = raiz->de.raiz;
    raiz->de.raiz = nodoAux->iz.raiz;
    nodoAux->iz.raiz = raiz;
    if (nodoAux->fe == 1) {
        raiz->fe = 0;
        nodoAux->fe = 0;
    } else {
        raiz->fe = 1;
        nodoAux->fe = -1;
    }
    raiz = nodoAux;
}

void TAVLCalendario::RotacionLR() {
    TNodoAVL *nodoIzquierdo = raiz->iz.raiz;
    TNodoAVL *nodoCentro = nodoIzquierdo->de.raiz;
    raiz->iz.raiz = nodoCentro->de.raiz;
    nodoIzquierdo->de.raiz = nodoCentro->iz.raiz;
    nodoCentro->iz.raiz = nodoIzquierdo;
    nodoCentro->de.raiz = raiz;
    switch (nodoCentro->fe) {
        case 1:
            nodoIzquierdo->fe = -1;
            raiz->fe = 0;
            break;
        case -1:
            nodoIzquierdo->fe = 0;
            raiz->fe = 1;
            break;
        case 0:
            nodoIzquierdo->fe = 0;
            raiz->fe = 0;
            break;
    }
    nodoCentro->fe = 0;
    raiz = nodoCentro;
}

void TAVLCalendario::RotacionRL() {
    TNodoAVL *nodoDerecho = raiz->de.raiz;
    TNodoAVL *nodoCentro = nodoDerecho->iz.raiz;
    raiz->de.raiz = nodoCentro->iz.raiz;
    nodoDerecho->iz.raiz = nodoCentro->de.raiz;
    nodoCentro->de.raiz = nodoDerecho;
    nodoCentro->iz.raiz = raiz;
    switch (nodoCentro->fe) {
        case -1:
            nodoDerecho->fe = 1;
            raiz->fe = 0;
            break;
        case 1:
            nodoDerecho->fe = 0;
            raiz->fe = -1;
            break;
        case 0:
            nodoDerecho->fe = 0;
            raiz->fe = 0;
            break;
    }
    nodoCentro->fe = 0;
    raiz = nodoCentro;
}


bool TAVLCalendario::Insertar(const TCalendario &tcalendario) {
    bool crece = false;
    return InsertarAux(tcalendario, crece);
}

bool TAVLCalendario::InsertarAux(const TCalendario &tcalendario, bool &crece) {
    bool insertado = false;
    if (raiz == NULL) {
        raiz = new TNodoAVL();
        raiz->item = tcalendario;
        crece = true;
        insertado = true;
    } else {
        bool creceSubarb = false;

        if (tcalendario < raiz->item) {
            insertado = raiz->iz.InsertarAux(tcalendario, creceSubarb);
            if (creceSubarb) {
                raiz->fe--;
                if (raiz->fe == -2) {
                    if (raiz->iz.raiz->fe == -1) {
                        RotacionLL();
                    } else {
                        RotacionLR();
                    }
                    crece = false;
                } else if (raiz->fe == -1) {
                    crece = true;
                } else if (raiz->fe == 0) {
                    crece = false;
                }
            }
        } else if (tcalendario > raiz->item) {
            insertado = raiz->de.InsertarAux(tcalendario, creceSubarb);
            if (creceSubarb) {
                raiz->fe++;
                if (raiz->fe == 2) {
                    if (raiz->de.raiz->fe == 1) {
                        RotacionRR();
                    } else {
                        RotacionRL();
                    }
                    crece = false;
                } else if (raiz->fe == 1) {
                    crece = true;
                } else if (raiz->fe == 0) {
                    crece = false;
                }
            }
        }
    }

    return insertado;
}


// Borrar
bool TAVLCalendario::Borrar(const TCalendario &tcalendario) {
    bool decrece = false;
    return BorrarAux(tcalendario, decrece);
}

bool TAVLCalendario::BorrarAux(const TCalendario &tcalendario, bool &decrece) {
    bool borrado = false;

    if (raiz == NULL) {
        return false;
    }

    if (tcalendario < raiz->item) {
        bool decreceIzq = false;
        borrado = raiz->iz.BorrarAux(tcalendario, decreceIzq);
        if (decreceIzq) {
            raiz->fe++;
            if (raiz->fe == 1) {
                decrece = false;
            } else if (raiz->fe == 2) {
                if (raiz->de.raiz->fe >= 0) {
                    RotacionRR();
                    decrece = (raiz->fe == 0);
                } else {
                    RotacionRL();
                    decrece = true;
                }
            } else if (raiz->fe == 0) {
                decrece = true;
            }
        }
    } else if (tcalendario > raiz->item) {
        bool decreceDer = false;
        borrado = raiz->de.BorrarAux(tcalendario, decreceDer);
        if (decreceDer) {
            raiz->fe--;
            if (raiz->fe == -1) {
                decrece = false;
            } else if (raiz->fe == -2) {
                if (raiz->iz.raiz->fe <= 0) {
                    RotacionLL();
                    decrece = (raiz->fe == 0);
                } else {
                    RotacionLR();
                    decrece = true;
                }
            } else if (raiz->fe == 0) {
                decrece = true;
            }
        }
    } else {
        if (raiz->iz.raiz == NULL && raiz->de.raiz == NULL) {
            delete raiz;
            raiz = NULL;
            decrece = true;
            borrado = true;
        } else if (raiz->iz.raiz == NULL) {
            TNodoAVL *nodoAux = raiz;
            raiz = raiz->de.raiz;
            nodoAux->de.raiz = NULL;
            delete nodoAux;
            decrece = true;
            borrado = true;
        } else if (raiz->de.raiz == NULL) {
            TNodoAVL *nodoAux = raiz;
            raiz = raiz->iz.raiz;
            nodoAux->iz.raiz = NULL;
            delete nodoAux;
            decrece = true;
            borrado = true;
        } else {
            TNodoAVL *nodoAux = raiz->iz.raiz;
            while (nodoAux->de.raiz != NULL) {
                nodoAux = nodoAux->de.raiz;
            }
            raiz->item = nodoAux->item;
            bool subArbDecrece = false;
            borrado = raiz->iz.BorrarAux(nodoAux->item, subArbDecrece);
            if (subArbDecrece) {
                raiz->fe++;
                if (raiz->fe == 1) {
                    decrece = false;
                } else if (raiz->fe == 2) {
                    if (raiz->de.raiz->fe >= 0) {
                        RotacionRR();
                        decrece = (raiz->fe == 0);
                    } else {
                        RotacionRL();
                        decrece = true;
                    }
                } else if (raiz->fe == 0) {
                    decrece = true;
                }
            }
        }
    }

    return borrado;
}


TCalendario TAVLCalendario::Raiz() const {
    return raiz->item;
}

ostream &operator<<(ostream &os, const TAVLCalendario &arbolAvl) {
    TVectorCalendario vectorAux = arbolAvl.Inorden();
    os << vectorAux;
    return os;
}
