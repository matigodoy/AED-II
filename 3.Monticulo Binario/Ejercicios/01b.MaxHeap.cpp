#include<iostream>
#include<climits>
using namespace std;

class MaxHeap{
    private:
        int* h;
        int capacidad;  //dimension del array
        int n;          //cantidad de elementos que tiene cargado el array
        int padre(int i){return (i-1)/2;} //devuelve el padre de un hijo
        int hijoI(int i){return 2*i + 1;} //devuelve el hijo izquierdo
        int hijoD(int i){return 2*i + 2;} //devuelve el hijo derecho
    public:
        MaxHeap(int);
        void InsertarClave(int);
        int ObtenerMaximo();
        int ExtraerMaximo();
        void heapify(int);
};

MaxHeap::MaxHeap(int capacidad){
    this->capacidad = capacidad;
    this->n = 0;
    this->h = new int[capacidad];
}

void MaxHeap::InsertarClave(int clave){
    if(n == capacidad){
        cout<<"Se ha alcanzado la capacidad maxima "<<endl;
        return;
    }

    //insertamos al final el array
    h[n] = clave;
    int i = n;
    n++;

    //Asegurar la definicion del maxheap
    while(i != 0 && h[padre(i)] < h[i]){
        swap(h[padre(i)], h[i]);
        i = padre(i);
    }
}

int MaxHeap::ObtenerMaximo(){
    if(this->n > 0)
        return this->h[0];
    else
        return INT_MAX;
}

int MaxHeap::ExtraerMaximo(){
    if(n <= 0)
        return INT_MAX;
    if(n == 1)
        return h[--n];
    
    int maximo = h[0];
    h[0] = h[--n];

    heapify(0);

    return maximo;
}

void MaxHeap::heapify(int i){
    int hi = hijoI(i);
    int hd = hijoD(i);
    int mayor = i;
    if(h[hi] > h[i] && hi < n)
        mayor = hi;
    if(h[hd] > h[mayor] && hd < n)
        mayor = hd;
    if(mayor != i){
        swap(h[i], h[mayor]);
        heapify(mayor);
    }
}

int main(){
    MaxHeap h1(100);

    h1.InsertarClave(51);
    h1.InsertarClave(2);
    h1.InsertarClave(9);
    h1.InsertarClave(14);
    h1.InsertarClave(1);
    h1.InsertarClave(25);

    cout<<"El mayor elemento es: "<<h1.ObtenerMaximo()<<endl;

    h1.ExtraerMaximo();

    cout<<"El mayor elemento es: "<<h1.ObtenerMaximo()<<endl;

    return 0;
}
#include <iostream>

using namespace std;
 

bool esMaxHeap(int* a,  int n)
{
    // Implementá esta función
    // Podés llamar a otras funciones si es necesario
}
 

int main()
{
    int a[] = {21, 15, 11, 7, 12, 2, 7, 3};
    int n = sizeof(a) / sizeof(int);
 
    cout << (esMaxHeap(a, n)? "Si": "No") << " es un Maxheap " << endl;
 
    return 0;
}