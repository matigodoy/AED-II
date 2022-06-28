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
        void profundidad(int, bool*);
    public:
        Grafo(int);
        ~Grafo();
        void agregar(int,int);
        void mostrar();
        void profundidad();
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
    cout<<"MOSTRAR "<<endl;
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

void Grafo::profundidad(){
    bool* visitado = new bool [v];
    for(int i=0; i<v; i++){
        visitado[i]=false;
    }
    profundidad(0,visitado);
    cout<<"[Fin]"<<endl;
}

void Grafo::profundidad(int a,bool* visitado){
    cout<<"["<<a<<"]->";
    visitado[a]=true;
    nodo* n = la[a];
    while(n != NULL){
        if(visitado[n->destino] == false)
            profundidad(n->destino,visitado);
        n=n->siguiente;
    }
}

int main(){
    Grafo g1(10);

    g1.agregar(0,7);
    g1.agregar(0,1);
    g1.agregar(1,6);
    g1.agregar(1,3);
    g1.agregar(1,2);
    g1.agregar(2,5);
    g1.agregar(2,4);
    g1.agregar(3,8);
    g1.agregar(4,5);
    g1.agregar(6,7);
    g1.agregar(8,9);
    g1.agregar(8,5);

    g1.mostrar();

    cout<<"\nRecorrido Profundidad "<<endl;
    g1.profundidad();
}