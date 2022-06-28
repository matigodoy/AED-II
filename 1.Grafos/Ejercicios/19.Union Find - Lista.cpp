#include<iostream>
using namespace std;

const int INFINITO = 99999;

struct Arista{
    int destino;
    int origen;
    int peso;
	Arista* siguiente;
};

class Grafo{
    private:
        int v;
        Arista* aristas;
        int Find(int*,int);
        void Union(int*,int,int);
    public:
        Grafo(int);
        void agregar(int,int,int);
        void mostrar();
        bool TieneCiclos();
};

Grafo::Grafo(int v){
    this->v = v;
    this->aristas = NULL;
}

void Grafo::agregar(int origen, int destino, int peso){
    Arista* n = new Arista;
    n->origen = origen;
    n->destino = destino;
    n->peso = peso;

    n->siguiente = aristas;
    aristas = n;
}

void Grafo::mostrar(){
    Arista* n = aristas;
    while(n != NULL){
        cout<<n->origen<<" - "<<n->destino<<" ("<<n->peso<<")"<<endl;
        n = n->siguiente;
    }
    cout<<endl;
}

int Grafo::Find(int* padre, int i){
    if(padre[i] == -1)
        return i;
    return Find(padre,padre[i]);
}

void Grafo::Union(int* padre, int x, int y){
    int conjuntox = Find(padre, x);
    int conjuntoy = Find(padre, y);
    padre[conjuntox] = conjuntoy;
}

bool Grafo::TieneCiclos(){
    int* padre = new int[v];
    for(int i=0;i<v;i++){
        padre[i] = -1;
    }
    Arista* a = aristas;
    while(a != NULL){
        int x = Find(padre, a->origen);
        int y = Find(padre, a->destino);

        if (x == y)
            return true;
        Union(padre, x, y);

        a=a->siguiente;
    }
    return false;
}

int main(){
    Grafo g(5);

    g.agregar(0,1,-1);
    g.agregar(0,2,4);
    g.agregar(1,2,3);
    g.agregar(1,3,2);
    g.agregar(1,4,2);
    g.agregar(3,2,5);
    //g.agregar(3,1,1);
    g.agregar(4,3,-3);

    g.mostrar();

    if(g.TieneCiclos() == true)
        cout<<"Tiene ciclos "<<endl;
        
    else
        cout<<"No tiene ciclos "<<endl;
    
}