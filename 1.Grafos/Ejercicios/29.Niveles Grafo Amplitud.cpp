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
        void AmplitudConNiveles(int);
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

void Grafo::AmplitudConNiveles(int origen){
    bool* visitado = new bool [v];
    int* niveles = new int [v];
    for(int i=0; i<v; i++){
        visitado[i] = false;
        niveles[i] = -1;
    }
    queue <int> cola;
    int s=origen;
    niveles[origen] = 0;
    cola.push(s);
    while(!cola.empty()){
        cout<<"["<<cola.front()<<"]->";
        cola.pop();
        nodo* n = la[s];
        visitado[s]=true;
        while(n != NULL){
            if(visitado[n->destino]==false){
                cola.push(n->destino);
                visitado[n->destino] = true;
                niveles[n->destino] = niveles[s] + 1;
            }
            n=n->siguiente;
        }
        s = cola.front();
    }
    cout<<"[Fin]"<<endl;
    cout<<"\nNiveles de los nodos "<<endl;
    for(int i=0; i<v; i++){
        cout<<"Nivel del nodo "<<i<<": "<<niveles[i]<<endl;
    }
}

int main(){
    Grafo g1(7);

    g1.agregar(0,3);
    g1.agregar(0,2);
    g1.agregar(0,1);
    g1.agregar(1,4);
    g1.agregar(1,0);
    g1.agregar(2,5);
    g1.agregar(2,0);
    g1.agregar(3,0);
    g1.agregar(4,5);
    g1.agregar(4,1);
    g1.agregar(5,6);
    g1.agregar(5,4);
    g1.agregar(5,2);
    g1.agregar(6,5);

    g1.mostrar();

    cout<<"\nRecorrido Amplitud "<<endl;
    g1.AmplitudConNiveles(0);
}