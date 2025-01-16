#include "tcalendario.h"
#include <cstring>

ostream &operator<<(ostream &os, const TCalendario &cal){
	if(cal.dia < 10){
		os << "0";
	}
	os << cal.dia << "/";
	if(cal.mes < 10){
		os << "0";	
	}
	os << cal.mes << "/" << cal.anyo << " ";
	os << '"'; 	
	if(cal.mens != NULL){
		os << cal.mens;
	}
	os << '"';
	return os;
}




TCalendario::TCalendario() {
    dia = 1;
    mes = 1;
    anyo = 1900;
    mens = NULL;
}

TCalendario::TCalendario(int dia, int mes, int anyo, const char *mens) {
    if (mes >= 1 && mes <= 12 && dia >= 1 && anyo >= 1900) {
        if (mes == 2) {
            if ((anyo % 4 == 0 && anyo % 100 != 0) || anyo % 400 == 0) { 
                if (dia > 29) {
                    dia = 1;
                    mes = 1;
                    anyo = 1900;
                    mens = NULL;
                }
            } else { 
                if (dia > 28) {
                    dia = 1;
                    mes = 1;
                    anyo = 1900;
                    mens = NULL;
                }
            }
        } else { 
            int diasMaximos;
            switch (mes) {
                case 4:
                case 6:
                case 9:
                case 11:
                    diasMaximos = 30;
                    break;
                default:
                    diasMaximos = 31;
                    break;
            }
            if (dia > diasMaximos) {
                dia = 1;
                mes = 1;
                anyo = 1900;
                mens = NULL;
            }
        }
        this->dia = dia;
        this->mes = mes;
        this->anyo = anyo;
        if (mens == NULL) {
            this->mens = NULL;
        } else {
            this->mens = new char[strlen(mens) + 1];
            strcpy(this->mens, mens);
        }
    } else { 
        this->dia = 1;
        this->mes = 1;
        this->anyo = 1900;
        this->mens = NULL;
    }
}



TCalendario::TCalendario(const TCalendario &cal){
	dia = cal.dia; 
	mes = cal.mes;
	anyo = cal.anyo;
	if(cal.mens == NULL){
		mens = NULL;
	}
	else{
		mens = new char [strlen(cal.mens) + 1];
		strcpy(mens, cal.mens);
	}


}

TCalendario &TCalendario::operator=(const TCalendario &tcal){
	if(this != &tcal){
		if(mens != NULL){
			delete [] mens;
			mens = NULL;
		}
		dia = tcal.dia;
		mes = tcal.mes;
		anyo = tcal.anyo;
		if(tcal.mens){
			mens = new char [strlen(tcal.mens) + 1];
			strcpy(mens, tcal.mens);
		}
		
	}
	return *this;
}

TCalendario::~TCalendario(){
	dia = 1;
	mes = 1;
	anyo = 1900;
	if(mens != NULL){
		delete [] mens;
		mens = NULL;
	}	
}

TCalendario TCalendario::operator++(int) {
    TCalendario copia(*this); 
    ++(*this); 
    return copia; 
}

TCalendario &TCalendario::operator++() {
    if (dia < DiasMes(mes, anyo)) {
        dia++;
    } else {
        dia = 1;
        if (mes < 12) {
            mes++;
        } else {
            mes = 1;
            anyo++;
        }
    }
    return *this;
}

TCalendario TCalendario::operator--(int) {
    TCalendario copia(*this); 
    --(*this); 
    return copia; 
}

TCalendario &TCalendario::operator--() {
    if (dia > 1) {
        dia--;
    } else {
        if (mes > 1) {
            mes--;
            dia = DiasMes(mes, anyo);
        } else {
            mes = 12;
            anyo--;
            dia = DiasMes(mes, anyo);
        }
    }
    if (anyo < 1900 || (anyo == 1900 && mes < 1) || (anyo == 1900 && mes == 1 && dia < 1)) {
        dia = 1;
        mes = 1;
        anyo = 1900;
        delete[] mens;
        mens = NULL;
    }
    return *this;
}

TCalendario TCalendario::operator+(int tcal) const {
    TCalendario copia(*this);
    while (tcal > 0) {
        copia++;
        tcal--;
    }
    return copia;
}

TCalendario TCalendario::operator-(int tcal) const {
    TCalendario copia(*this);
    while (tcal > 0) {
        copia--;
        tcal--;
    }
    return copia;
}


TCalendario operator+(int izq, const TCalendario &tcal) {
    TCalendario result(tcal); 
    if (izq > 0) {
        int daysToAdd = izq;
        while (daysToAdd > 0) {
            int remainingDaysInMonth = result.DiasMes(result.Mes(), result.Anyo()) - result.Dia() + 1;
            if (daysToAdd <= remainingDaysInMonth) {
                result.dia += daysToAdd;
                daysToAdd = 0;
            } else {
                result.dia = 1;
                result.mes++;
                if (result.mes > 12) {
                    result.mes = 1;
                    result.anyo++;
                }
                daysToAdd -= remainingDaysInMonth;
            }
        }
    }
    return result;
}

TCalendario operator-(int izq, const TCalendario &tcal) {
    TCalendario result(tcal);
    if (izq > 0) {
        int daysToSubtract = izq;
        while (daysToSubtract > 0) {
            if (result.Dia() > daysToSubtract) {
                result.dia -= daysToSubtract;
                daysToSubtract = 0;
            } else {
                daysToSubtract -= result.Dia();
                result.mes--;
                if (result.Mes() < 1) {
                    result.mes = 12;
                    result.anyo--;
                }
                result.dia = result.DiasMes(result.Mes(), result.Anyo());
            }
        }
    }
    if (result.Anyo() < 1900 || (result.Anyo() == 1900 && result.Mes() < 1) || (result.Anyo() == 1900 && result.Mes() == 1 && result.Dia() < 1)) {
        result.dia = 1;
        result.mes = 1;
        result.anyo = 1900;
        delete[] result.mens;
        result.mens = NULL;
    }
    return result;
}

bool TCalendario::operator==(const TCalendario &tcal) const {
        if (dia == tcal.dia && mes == tcal.mes && anyo == tcal.anyo) {
            if (mens == NULL && tcal.mens == NULL) {
                return true;
            } else if (mens != NULL && tcal.mens != NULL && strcmp(mens, tcal.mens) == 0) {
                return true;
            }
        }
        return false;
    }

bool TCalendario::operator!=(const TCalendario &tcal) const {
    return !(*this == tcal);
}


bool TCalendario::operator>(const TCalendario &tcal) const{
	return *this != tcal && !(*this < tcal);
}

bool TCalendario::operator<(const TCalendario &tcal) const {
    if (anyo < tcal.anyo) {
        return true;
    } else if (anyo > tcal.anyo) {
        return false;
    }

    if (mes < tcal.mes) {
        return true;
    } else if (mes > tcal.mes) {
        return false;
    }

    if (dia < tcal.dia) {
        return true;
    } else if (dia > tcal.dia) {
        return false;
    }

    if (mens != NULL && tcal.mens != NULL) {
        return strcmp(mens, tcal.mens) < 0;
    }

    return tcal.mens != NULL;
}


int TCalendario::Dia() const {
    return dia;
}

int TCalendario::Mes() const {
    return mes;
}

int TCalendario::Anyo() const {
    return anyo;
}

char *TCalendario::mensaje() const {
    
    return mens;
}

bool TCalendario::EsVacio() const{
	return dia == 1 && mes == 1 && anyo == 1900 && mens == NULL;	
}

bool TCalendario::ModFecha(int d, int m, int a) {
    if (a < 1900) {
        return false; 
    }

    if (m < 1 || m > 12) {
        return false; 
    }

    if (m == 2) { 
        if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) {
            if (d < 1 || d > 29) {
                return false; 
            }
        } else {
            if (d < 1 || d > 28) {
                return false; 
            }
        }
    } else if (m == 4 || m == 6 || m == 9 || m == 11) { 
        if (d < 1 || d > 30) {
            return false; 
        }
    } else { 
        if (d < 1 || d > 31) {
            return false; 
        }
    }

    dia = d;
    mes = m;
    anyo = a;
    return true; 
}


bool TCalendario::ModMensaje(char *mens) {
    delete [] this->mens;
    if (mens) {
        this->mens = new char[strlen(mens) + 1];
        strcpy(this->mens, mens);
        return true; 
    } else {
        this->mens = nullptr;
        return false; 
    }
}

int TCalendario::DiasMes(int mes, int anyo) const {
    if (mes == 2) {
        if ((anyo % 4 == 0 && anyo % 100 != 0) || anyo % 400 == 0) {
            return 29;
        } else {
            return 28;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    } else {
        return 31;
    }
}
