#include<iostream>
using namespace std;

struct nodo{
	int destino;
	nodo* siguiente;
};

class Grafo{
    private:
        int v;
        nodo** la;
    public:
        Grafo(int);
        ~Grafo();
        void agregar(int,int);
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

void Grafo::agregar(int origen,int destino){
    if(origen >= 0 && origen < v && destino >=0 && destino <v){
        nodo* n = new nodo();
        n->destino = destino;
        n->siguiente = la[origen];
        la[origen] = n;
    }
}

void Grafo::mostrar(){
    for(int i=0; i<v; i++){
        cout<<"["<<i<<"]->";
        nodo* n = la[i];
        while (n != NULL){
            cout<<n->destino<<"-";
            n=n->siguiente;
        }
        cout<<"Fin"<<endl;
    }
}

int main(){
    Grafo g1(5);

    g1.agregar(0,1);
    g1.agregar(0,3);
    g1.agregar(1,0);
    g1.agregar(1,2);
    g1.agregar(1,4);
    g1.agregar(2,1);
    g1.agregar(2,3);
    g1.agregar(3,0);
    g1.agregar(3,2);
    g1.agregar(3,4);
    g1.agregar(4,1);
    g1.agregar(4,3);

    g1.mostrar();
}