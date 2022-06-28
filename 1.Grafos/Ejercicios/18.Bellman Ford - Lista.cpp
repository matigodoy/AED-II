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
        int a;
        Arista* aristas;
    public:
        Grafo(int);
        void agregar(int,int,int);
        void mostrar();
        void BellmanFord(int);
};

Grafo::Grafo(int v){
    this->v = v;
    this->a = 0;
    this->aristas = NULL;
}

void Grafo::agregar(int origen, int destino, int peso){
    Arista* n = new Arista;
    n->origen = origen;
    n->destino = destino;
    n->peso = peso;

    n->siguiente = aristas;
    aristas = n;

    a++;
}

void Grafo::mostrar(){
    Arista* n = aristas;
    while(n != NULL){
        cout<<n->origen<<" - "<<n->destino<<" ("<<n->peso<<")"<<endl;
        n = n->siguiente;
    }
    cout<<endl;
}

void Grafo::BellmanFord(int origen){
    int* distancia = new int[v];
    for(int i=0;i<v;i++){
        distancia[i] = INFINITO;
    }
    distancia[origen] = 0;
    for(int i=0;i<v-1;i++){ //no se que hace este for.
        Arista* n = aristas;
        while(n != NULL){
            if(distancia[n->origen] != INFINITO && distancia[n->origen] + n->peso < distancia[n->destino]){
                distancia[n->destino] = distancia[n->origen] + n->peso;
            }
            n = n->siguiente;
        }
    }

    cout<<"Bellman - Ford "<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<"\t"<<distancia[i]<<endl;
    }
}

int main(){
    Grafo g(5);

    g.agregar(0,1,-1);
    g.agregar(0,2,4);
    g.agregar(1,2,3);
    g.agregar(1,3,2);
    g.agregar(1,4,2);
    g.agregar(3,2,5);
    g.agregar(3,1,1);
    g.agregar(4,3,-3);

    g.mostrar();

    g.BellmanFord(0);
}