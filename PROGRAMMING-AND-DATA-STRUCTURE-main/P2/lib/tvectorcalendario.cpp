#include "tvectorcalendario.h"

TVectorCalendario::TVectorCalendario(){
    tamano = 0;
    c = NULL;
    
}

TVectorCalendario::TVectorCalendario(int tam){
    if(tam < 0){
        tam = 0;
    }
    tamano = tam;
    c = new TCalendario[tamano];
}

ostream &operator<<(ostream &os, const TVectorCalendario &v) {
    os << "[";

    if (v.tamano > 0) {
        os << "(" << 1 << ") " << v.c[0];  

        for (int i = 1; i < v.tamano; i++) {
            os << ", ";
            os << "(" << i + 1 << ") " << v.c[i]; 
        }
    }

    os << "]";

    return os;
}



TCalendario &TVectorCalendario::operator[](int i){
    if (i < 1 || i > tamano) {
        return err;
    }
    return c[i - 1];
}

TCalendario TVectorCalendario::operator[](int i) const{
    if (i < 1 || i > tamano) {
        return TCalendario();
    }
    return c[i - 1];
}


TVectorCalendario::TVectorCalendario(const TVectorCalendario &v){
    tamano = v.tamano;
    c = new TCalendario[tamano];
    for (int i = 0; i < tamano; i++) {
        c[i] = v.c[i];
    }
}

TVectorCalendario::~TVectorCalendario(){
    delete[] c;
}

TVectorCalendario &TVectorCalendario::operator=(const TVectorCalendario &v){
    if (this != &v) {
        delete[] c;
        tamano = v.tamano;
        c = new TCalendario[tamano];
        for (int i = 0; i < tamano; i++) {
            c[i] = v.c[i];
        }
    }
    return *this;
}

bool TVectorCalendario::operator==(const TVectorCalendario &vecCal) const{
    if (tamano != vecCal.tamano) {
        return false;
    }

    for (int i = 0; i < tamano; i++) {
        if (c[i] != vecCal.c[i]) {
            return false;
        }
    }

    return true;
}

bool TVectorCalendario::operator!=(const TVectorCalendario &vecCal) const{
    return !(*this == vecCal);
}

int TVectorCalendario::Tamano() const{
    return tamano;
}

int TVectorCalendario::Ocupadas() const{
    int count = 0;
    for (int i = 0; i < tamano; i++) {
        if (c[i].EsVacio()) {
            count++;
        }
    }
    return tamano - count;
}

bool TVectorCalendario::ExisteCal(const TCalendario &cal) const{
    for (int i = 0; i < tamano; i++) {
        if (c[i] == cal) {
            return true;
        }
    }
    return false;
}

void TVectorCalendario::MostrarMensajes(int d, int m, int a) {
    TCalendario auxiliar(d, m, a, NULL);  
    bool primerElemento = true;

    cout << "[";

    int i = 0;
    while (i < tamano) {
        if (c[i] > auxiliar || c[i] == auxiliar) {
            if (!primerElemento) {
                cout << ", ";
            }
            cout << c[i];

            primerElemento = false;
        }
        i++;
    }

    cout << "]";
}


bool TVectorCalendario::Redimensionar(int t){
    if (t <= 0 || t == tamano) {
        return false;
    }

    if (t > tamano) {
        TCalendario* nuevo = new TCalendario[t];
        for (int i = 0; i < tamano; i++) {
            nuevo[i] = c[i];
        }
        for (int i = tamano; i < t; i++) {
            nuevo[i] = TCalendario();
        }
        delete[] c;
        c = nuevo;
        tamano = t;
        return true;
    }

    if (t < tamano) {
        TCalendario* nuevo = new TCalendario[t];
        for (int i = 0; i < t; i++) {
            nuevo[i] = c[i];
        }
        delete[] c;
        c = nuevo;
        tamano = t;
        return true;
    }
    return false;
}
