#include "tabbcalendario.h"
#include <queue>


TNodoABB::TNodoABB(){
}
TNodoABB::TNodoABB(const TNodoABB &nodo):item(nodo.item), iz(nodo.iz), de(nodo.de){
    
}
TNodoABB::~TNodoABB(){   
}
TNodoABB &TNodoABB::operator=(const TNodoABB &nodo){//mirar si poner const
    if(this != &nodo){
        item = nodo.item;
        iz = nodo.iz;
        de = nodo.de;
    }
    return *this;
}


void TABBCalendario::InordenAux(TVectorCalendario &v, int &pos) const{
    if(raiz != nullptr){
        raiz->iz.InordenAux(v, pos);
        v[pos] = raiz->item;
        pos++;
        raiz->de.InordenAux(v, pos);
    }
}
void TABBCalendario::PreordenAux(TVectorCalendario &v, int &pos) const{
    if(raiz != nullptr){
        v[pos] = raiz->item;
        pos++;
        raiz->iz.PreordenAux(v, pos);
        raiz->de.PreordenAux(v, pos);
    }
}
void TABBCalendario::PostordenAux(TVectorCalendario &v, int &pos) const{
    if(raiz != nullptr){
        raiz->iz.PostordenAux(v, pos);
        raiz->de.PostordenAux(v, pos);
        v[pos] = raiz->item;
        pos++;
    }
}





TABBCalendario::TABBCalendario():raiz(nullptr){
}   
TABBCalendario::TABBCalendario(const TABBCalendario &arbol){
    if(arbol.raiz != nullptr){
        raiz = new TNodoABB(*(arbol.raiz));
    }else{
        raiz = nullptr;
    }
}   

TABBCalendario::~TABBCalendario(){
    if(raiz != nullptr){
        delete raiz;
        raiz = nullptr;
    }
}
TABBCalendario &TABBCalendario::operator=(const TABBCalendario &arbol){
    if(this != &arbol){
        if(raiz != nullptr){
            delete raiz;
            raiz = nullptr;
        }
        if(arbol.raiz != nullptr){
            raiz = new TNodoABB(*(arbol.raiz)); //modificacion

        }else{
            raiz = nullptr;
        }
    }
    return *this;
}
bool TABBCalendario::operator==(const TABBCalendario &arbol) const{
    return this->Inorden() == arbol.Inorden();
}
bool TABBCalendario::EsVacio() const{
    return raiz == nullptr;
}

bool TABBCalendario::Insertar(const TCalendario &calendario){
    bool inserted = false;
    if(raiz == nullptr){    
        raiz = new TNodoABB();
        raiz->item = calendario;
        inserted = true;
    }else{
        if(calendario < raiz->item){
            inserted = raiz->iz.Insertar(calendario);
        }else if(calendario > raiz->item){
            inserted = raiz->de.Insertar(calendario);
        }
    }
    return inserted;
}

//repasar
bool TABBCalendario::Borrar(const TCalendario &tc){
    bool borrado = false;
    if(raiz != nullptr){
        if(tc == raiz->item){
            if(raiz->iz.raiz == nullptr && raiz->de.raiz == nullptr){
                delete raiz;
                raiz = nullptr;
            }else if(raiz->iz.raiz == nullptr){
                TNodoABB *aux = raiz;
                raiz = raiz->de.raiz;
                aux->de.raiz = nullptr;
                delete aux;
            }else if(raiz->de.raiz == nullptr){
                TNodoABB *aux = raiz;
                raiz = raiz->iz.raiz;
                aux->iz.raiz = nullptr;
                delete aux;
            }else{
                TNodoABB *aux = raiz->iz.raiz;
                while(aux->de.raiz != nullptr){
                    aux = aux->de.raiz;
                }
                raiz->item = aux->item;
                raiz->iz.Borrar(aux->item);
            }
            borrado = true;
        }else if(tc < raiz->item){
            borrado = raiz->iz.Borrar(tc);
        }else{
            borrado = raiz->de.Borrar(tc);
        }
    }
    return borrado;
}

bool TABBCalendario::Buscar(const TCalendario &cal) const{
    bool encontrado = false;
    if(raiz != nullptr){
        if(cal == raiz->item){
            encontrado = true;
        }else if(cal < raiz->item){
            encontrado = raiz->iz.Buscar(cal);
        }else{
            encontrado = raiz->de.Buscar(cal);
        }
    }
    return encontrado;
}

TCalendario TABBCalendario::Raiz(){
        return raiz->item;
    

}
int TABBCalendario::Altura() const{
    int altura = 0;
    if(raiz != nullptr){
        altura = 1 + max(raiz->iz.Altura(), raiz->de.Altura());
    }
    return altura;
}

int TABBCalendario::Nodos() const{
    int nodos = 0;
    if(raiz != nullptr){
        nodos = 1 + raiz->iz.Nodos() + raiz->de.Nodos();
    }
    return nodos;
}
int TABBCalendario::NodosHoja() const{
    int nodos = 0;
    if(raiz != nullptr){
        if(raiz->iz.raiz == nullptr && raiz->de.raiz == nullptr){
            nodos = 1;
        }else{
            nodos = raiz->iz.NodosHoja() + raiz->de.NodosHoja();
        }
    }
    return nodos;
}





TVectorCalendario TABBCalendario::Inorden() const{
    int i = 1;
    int tam = Nodos();
    TVectorCalendario vectorcal(tam);
    InordenAux(vectorcal, i);
    return vectorcal;
}

TVectorCalendario TABBCalendario::Preorden() const{
    int i = 1;
    int tam = Nodos();
    TVectorCalendario vectorcal(tam);
    PreordenAux(vectorcal, i);
    return vectorcal;
}

TVectorCalendario TABBCalendario::Postorden() const{
    int i = 1;
    int tam = Nodos();
    TVectorCalendario vectorcal(tam);
    PostordenAux(vectorcal, i);
    return vectorcal;
}



TVectorCalendario TABBCalendario::Niveles() const {
    queue<TNodoABB *> cola;
    TNodoABB *nodo;
    int tam = Nodos();
    TVectorCalendario vectorcal(tam);
    
    int i = 1;

    if (raiz != nullptr) {
        cola.push(raiz);
        do {
            nodo = cola.front();
            cola.pop();
            vectorcal[i] = nodo->item;
            i++;
            if (nodo->iz.raiz != nullptr) {
                cola.push(nodo->iz.raiz);
            }
            if (nodo->de.raiz != nullptr) {
                cola.push(nodo->de.raiz);
            }
        } while (!cola.empty());
    }

    return vectorcal;
}



//modificado
ostream & operator<<(ostream &os, TABBCalendario &arbol){
    return os << arbol.Niveles();
}



TABBCalendario TABBCalendario::operator+(const TABBCalendario &arbol) const{
    TABBCalendario aux(*this);
    TVectorCalendario v = arbol.Inorden();
    for(int i = 1; i <= v.Tamano(); i++){
        aux.Insertar(v[i]);
    }
    return aux;
}

TABBCalendario TABBCalendario::operator-(const TABBCalendario &tabb) const {

    TVectorCalendario auxVec = Inorden();
    TABBCalendario aux;
    for (int i = 1; i <= auxVec.Tamano(); i++) {
        if (!tabb.Buscar(auxVec[i])) {
            aux.Insertar(auxVec[i]);
        }
    }
    return aux;
}


