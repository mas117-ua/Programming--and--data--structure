#include <iostream>

using namespace std;

#include "tcalendario.h"
#include "tlistacalendario.h"

int
main(void)
{
  TCalendario a(10,10,2006, (char*) "mensaje 1");
  TCalendario b(11,10,2006, (char*) "mensaje 2");
  TCalendario c(12,10,2006, (char*) "mensaje 3");
  TCalendario d(13,10,2006, (char*) "mensaje 4");
  TCalendario e(14,10,2006, (char*) "mensaje 5");
  TCalendario f(15,10,2006, (char*) "mensaje 6");
  TCalendario g(16,10,2006, (char*) "mensaje 7");
  TCalendario h(17,10,2006, (char*) "mensaje 8");
  TCalendario i(18,10,2006, (char*) "mensaje 9");
  TCalendario j(19,10,2006, (char*) "mensaje 10");
  TCalendario k(20,10,2006, (char*) "mensaje 11");
  TCalendario l(21,10,2006, (char*) "mensaje 12");


  TListaCalendario lista;
  TListaPos p;

  lista.Insertar(a);
  lista.Insertar(b);
  lista.Insertar(c);
  lista.Insertar(d);
  lista.Insertar(e);
  lista.Insertar(f);
  lista.Insertar(g);
  lista.Insertar(h);
  lista.Insertar(i);
  lista.Insertar(j);

  lista.Borrar(14,10,2006);

  p=lista.Primera();  

  cout<<lista.Obtener(p)<<endl;

}
