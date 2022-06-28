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
        void Dijkstra(int);
        int DistanciaMinima(int*,bool*);
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

void Grafo::Dijkstra(int origen){
    int* distancia = new int[v];
    bool* spt = new bool[v];
    int* padre = new int[v];
    for(int i=0;i<v;i++){
        padre[i]=0;
        spt[i]=false;
        distancia[i]=999999;
    }
    distancia[origen]=0;
    padre[origen]=-1;
    for(int i=0;i<v-1;i++){
        int u = DistanciaMinima(distancia,spt);
        spt[u] = true;
        nodo* n = la[u];
        while(n != NULL){
            if(!spt[n->destino] && distancia[u] + n->arista < distancia[n->destino]){
                distancia[n->destino] = distancia[u] + n->arista;
                padre[n->destino] = u;
            }
            n = n->siguiente;
        }
    }
    cout<<"Distancias entre "<<origen<<" y todos"<<endl;
    for(int i=0;i<v;i++){
        cout<<"["<<origen<<","<<i<<"] = "<<distancia[i]<<"\tPadre: "<<padre[i]<<endl;
    }
}

int Grafo::DistanciaMinima(int* distancia,bool* spt){
    int menor=999999;
    int indicemenor=0;
    for(int i=0;i<v-1;i++){
        if(spt[i]==false && distancia[i]<=menor){
            menor=distancia[i],indicemenor = i;
        }
    }
    return indicemenor;
}

int main(){
    Grafo g(6);
    g.mostrar();

    /*g.agregar(0,1,2);
    g.agregar(0,2,4);
    g.agregar(1,2,1);
    g.agregar(1,3,7);
    g.agregar(2,4,3);
    g.agregar(3,5,1);
    g.agregar(4,3,2);
    g.agregar(4,5,5);

    g.Dijkstra(0);*/
}
