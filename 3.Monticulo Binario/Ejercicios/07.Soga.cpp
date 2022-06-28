#include<iostream>
#include<climits>
using namespace std;

class MinHeap{
    private:
        int* h;
        int capacidad;  //dimension del array
        int n;          //cantidad de elementos que tiene cargado el array
        int padre(int i){return (i-1)/2;} //devuelve el padre de un hijo
        int hijoI(int i){return 2*i + 1;} //devuelve el hijo izquierdo
        int hijoD(int i){return 2*i + 2;} //devuelve el hijo derecho
    public:
        MinHeap(int);
        void InsertarClave(int);
        int ObtenerMinimo();
        int ExtraerMinimo();
        void heapify(int);
        void Soga();
};

MinHeap::MinHeap(int capacidad){
    this->capacidad = capacidad;
    this->n = 0;
    this->h = new int[capacidad];
}

void MinHeap::InsertarClave(int clave){
    if(n == capacidad){
        cout<<"Se ha alcanzado la capacidad maxima "<<endl;
        return;
    }

    //insertamos al final el array
    h[n] = clave;
    int i = n;
    n++;

    //Asegurar la definicion del minheap
    while(i != 0 && h[padre(i)] > h[i]){
        swap(h[padre(i)], h[i]);
        i = padre(i);
    }
}

int MinHeap::ObtenerMinimo(){
    if(this->n > 0)
        return this->h[0];
    else
        return INT_MIN;
}

int MinHeap::ExtraerMinimo(){
    if(n <= 0)
        return INT_MIN;
    if(n == 1)
        return h[--n];
    
    int minimo = h[0];
    h[0] = h[--n];

    heapify(0);

    return minimo;
}

void MinHeap::heapify(int i){
    int hi = hijoI(i);
    int hd = hijoD(i);
    int menor = i;
    if(h[hi] < h[i] && hi < n)
        menor = hi;
    if(h[hd] < h[menor] && hd < n)
        menor = hd;
    if(menor != i){
        swap(h[i], h[menor]);
        heapify(menor);
    }
}

void MinHeap::Soga(){
    int total = ExtraerMinimo() + ExtraerMinimo();
    int auxiliar = ExtraerMinimo() + total;
    while(n>0){
        total = total + auxiliar;
        auxiliar = auxiliar + ExtraerMinimo();
    }
    total = total + auxiliar;
    cout<<"Costo total: "<<total<<endl;
}

int main(){
    MinHeap h1(100);

    h1.InsertarClave(2);
    h1.InsertarClave(4);
    h1.InsertarClave(3);
    h1.InsertarClave(6);
    h1.InsertarClave(8);
    h1.InsertarClave(5);

    h1.Soga();

    return 0;
}