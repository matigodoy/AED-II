#include<iostream>
using namespace std;

struct nodo{
	int destino;
    int arista;
	nodo* siguiente;
};

class Grafo{
    private:
        int v;
        nodo** la;
    public:
        Grafo(int);
        ~Grafo();
        void agregar(int,int,int);
        void mostrar();
};

Grafo::Grafo(int v){
    this->v = v;
    la = new nodo*[v];
    for(int i = 0; i< v; i++){
        la[i] = NULL;
    }
}

Grafo::~Grafo(){
    for(int i=0;i<v;i++){
        nodo* n = la[i];
        while(n!=NULL){
            nodo* m = n->siguiente;
            delete n;
            n = m;
        }
    }
    delete[] la;
}

void Grafo::agregar(int origen,int destino,int arista){
    if(origen >= 0 && origen < v && destino >=0 && destino <v){
        nodo* n = new nodo();
        n->destino = destino;
        n->arista = arista;
        n->siguiente = la[origen];
        la[origen] = n;
    }
}

void Grafo::mostrar(){
    for(int i=0; i<v; i++){
        cout<<"["<<i<<"]->";
        nodo* n = la[i];
        while (n != NULL){
            cout<<n->destino<<" |"<<n->arista<<"| - ";
            n=n->siguiente;
        }
        cout<<"Fin"<<endl;
    }
}

int main(){
    Grafo g(6);

    g.agregar(0,1,2);
    g.agregar(0,2,4);
    g.agregar(1,2,1);
    g.agregar(1,3,7);
    g.agregar(2,4,3);
    g.agregar(3,5,1);
    g.agregar(4,3,2);
    g.agregar(4,5,5);

    g.mostrar();
}