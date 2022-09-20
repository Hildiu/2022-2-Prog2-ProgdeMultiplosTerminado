#include <iostream>
#include <iomanip>
using namespace std;

void imprimir( int *pEntero, int ne );
int * dimensionar(int n);
void   llenarDatos(int * pA,int n);
int contarMultiplos( int *pA, int n, int multiplo );
void  llenarNumeros(int *pA, int n, int *pNumeros, int multiplo);
void eliminar(int * & pA);

int main()
{ int n;
  int c5, c7;

    srand(time(nullptr));
  cout << "Numero de elementos que tendra el arreglo : ";
  cin >> n;
  int *pA = dimensionar(n);
  llenarDatos(pA, n);
  imprimir(pA,n);
  c5 = contarMultiplos(pA,n,5);
  c7 = contarMultiplos(pA,n,7);
  int *pNMun5 = dimensionar(c5);
  int *pNMun7 = dimensionar(c7);
  llenarNumeros(pA,n,pNMun5, 5);
  llenarNumeros(pA, n, pNMun7, 7);
  cout << "\n";
  cout << "Multiplos de cinco\n";
  imprimir(pNMun5,c5);
  cout << "\n";
  cout << "Multiplos de siete\n";
  imprimir(pNMun7,c7);
  eliminar(pA);
  eliminar(pNMun5);
  eliminar(pNMun7);
}

void eliminar(int * & pA)
{
    delete []pA;
    pA = nullptr;
}

void  llenarNumeros(int *pA, int n, int *pNumeros, int multiplo)
{ int ian = 0;
    for(int i=0; i<n; i++)
        if(pA[i] % multiplo ==0)
            pNumeros[ian++] = pA[i];
}

int contarMultiplos( int *pA, int n, int multiplo )
{ int c=0;
    for(int i=0; i<n; i++)
        if(pA[i] % multiplo ==0)
            c++;
    return c;
}

int * dimensionar(int n)
{
    return new int[n];
}

void   llenarDatos(int * pA,int n)
{
    for(unsigned int i=0; i<n; i++)
        pA[i] = rand() % 1000;
}

void imprimir( int *pEntero, int ne )
{  for(unsigned int i=0; i<ne; i++)
        cout << setw(6) << pEntero[i];
}