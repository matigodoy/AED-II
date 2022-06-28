#include<iostream>
#include<climits>
using namespace std;

struct paciente{
    string nombre;
    string apellido;
    int dni;
    int gravedad;
};

class MaxHeap{
    private:
        paciente* h;
        int capacidad;  //dimension del array
        int n;          //cantidad de elementos que tiene cargado el array
        int padre(int i){return (i-1)/2;} //devuelve el padre de un hijo
        int hijoI(int i){return 2*i + 1;} //devuelve el hijo izquierdo
        int hijoD(int i){return 2*i + 2;} //devuelve el hijo derecho
    public:
        MaxHeap(int);
        void InsertarPaciente(string, string, int, int);
        paciente ExtraerMaximo();
        void heapify(int);
        void Mostrar(paciente);
};

MaxHeap::MaxHeap(int capacidad){
    this->capacidad = capacidad;
    this->n = 0;
    this->h = new paciente[capacidad];
}

void MaxHeap::InsertarPaciente(string nombre, string apellido, int dni, int gravedad){
    if(n == capacidad){
        cout<<"Se ha alcanzado la capacidad maxima "<<endl;
        return;
    }

    h[n].nombre = nombre;
    h[n].apellido = apellido;
    h[n].dni = dni;
    h[n].gravedad = gravedad;
    int i = n;
    n++;

    //Asegurar la definicion del maxheap
    while(i != 0 && h[padre(i)].gravedad < h[i].gravedad){
        swap(h[padre(i)], h[i]);
        i = padre(i);
    }
}

paciente MaxHeap::ExtraerMaximo(){
    if(n == 1)
        return h[--n];
    
    paciente maximo = h[0];
    h[0].gravedad = h[--n].gravedad;

    heapify(0);

    return maximo;
}

void MaxHeap::heapify(int i){
    int hi = hijoI(i);
    int hd = hijoD(i);
    int mayor = i;
    if(h[hi].gravedad > h[i].gravedad && hi < n)
        mayor = hi;
    if(h[hd].gravedad > h[mayor].gravedad && hd < n)
        mayor = hd;
    if(mayor != i){
        swap(h[i], h[mayor]);
        heapify(mayor);
    }
}

void MaxHeap::Mostrar(paciente persona){
    cout<<"Paciente: "<<endl;
    cout<<"Nombre: "<<persona.nombre<<endl;
    cout<<"Apellido: "<<persona.apellido<<endl;
    cout<<"DNI: "<<persona.dni<<endl;
    cout<<"Gravedad: "<<persona.gravedad<<endl;
    cout<<endl;
}

int main(){
    MaxHeap h1(100);

    h1.InsertarPaciente("Federico","Marquez",433655,45);
    h1.InsertarPaciente("Pepe","Juan",5643543,98);
    h1.InsertarPaciente("Juan","De Aragon",54354,23);
    h1.InsertarPaciente("Matias","Godoy",898793,2);
    h1.InsertarPaciente("Ete","Sech",123454,89);
    h1.InsertarPaciente("El","Pepe",34567,78);

    h1.Mostrar(h1.ExtraerMaximo());

    h1.Mostrar(h1.ExtraerMaximo());

    h1.InsertarPaciente("Lucas","Moyano",6982,99);

    h1.Mostrar(h1.ExtraerMaximo());

    h1.Mostrar(h1.ExtraerMaximo());

    return 0;
}