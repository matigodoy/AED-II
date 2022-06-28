#include<iostream>
#include<queue>
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
        void topologico();
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

void Grafo::topologico(){
    int* grado = new int [v];
    for(int i=0; i<v; i++){
        grado[i]=0;
    }
    for(int i=0; i<v; i++){
        nodo* n = la[i];
        while (n != NULL){
            grado[n->destino]=grado[n->destino] + 1;
            n=n->siguiente;
        }
    }
    queue <int> cola;
    for(int i=0; i<v; i++){
        if(grado[i] == 0){
            cola.push(i);
        }
    }

    int visitados = 0;
    int* ot = new int [v];
    while(!cola.empty()){
        nodo* m = la[cola.front()];
        ot[visitados]=cola.front();
        cola.pop();
        visitados ++;
        while(m != NULL){
            grado[m->destino] = grado[m->destino] - 1;
            if(grado[m->destino]==0){
                cola.push(m->destino);
            }
            m = m->siguiente;
        }
    }

    if(visitados == v){
        for(int i=0; i<v; i++){
            cout<<"["<<ot[i]<<"]->";
        }
        cout<<"[Fin]"<<endl;
    }
    else{
        cout<<"No es posible el orden Topologico "<<endl;
    }
}

int main(){
    Grafo g(8);

    g.agregar(0,2);
    g.agregar(1,4);
    g.agregar(1,3);
    g.agregar(1,2);
    g.agregar(2,5);
    g.agregar(4,6);
    g.agregar(4,5);
    g.agregar(5,7);
    g.agregar(5,6);
    g.agregar(6,7);

    g.mostrar();

    cout<<"\nOrden Topologico "<<endl;
    g.topologico();
}