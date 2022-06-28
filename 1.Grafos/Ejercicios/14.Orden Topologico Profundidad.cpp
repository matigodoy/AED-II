#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct nodo{
	int destino;
	nodo* siguiente;
};

class Grafo{
    private:
        int v;
        nodo** la;
        void topologicoProfundidad(int, bool*, stack<int>&);
    public:
        Grafo(int);
        ~Grafo();
        void agregar(int,int);
        void mostrar();
        void topologicoProfundidad();
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

void Grafo::topologicoProfundidad(){
    stack<int> pila;
    bool* visitado = new bool[v];
    for(int i=0; i<v; i++){
        visitado[i]=false;
    }

    for(int i=0; i<v; i++){
        if(visitado[i] == false){
            topologicoProfundidad(i,visitado,pila);
        }
    }

    while(!pila.empty()){
        cout<<"["<<pila.top()<<"]-";
        pila.pop();
    }
    cout<<"[Fin]"<<endl;
}

void Grafo::topologicoProfundidad(int u, bool* visitado, stack<int>& pila){
    visitado[u] = true;
    nodo* n = la[u];
    while (n != NULL){
        if(!visitado[n->destino]){
            topologicoProfundidad(n->destino, visitado, pila);
        }
        n=n->siguiente;
    }
    pila.push(u);
}

int main(){
    Grafo g(8);
    g.agregar(0,2);
    g.agregar(1,2);
    g.agregar(1,3);
    g.agregar(2,4);
    g.agregar(3,6);
    g.agregar(4,5);
    g.agregar(4,6);
    g.agregar(6,7);

    g.mostrar();

    cout<<"\nOrden Topologico "<<endl;
    g.topologicoProfundidad();
}