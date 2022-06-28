#include<iostream>
using namespace std;

class Grafo{
    private:
        int v;
        int** a;
    public:
        Grafo(int);
        ~Grafo();
        void AgregarArista(int,int,int);
        void Mostrar();
        void Dijkstra(int);
        int DistanciaMinima(int*,bool*);
};

Grafo::Grafo(int v){
    this->v = v;
    a = new int*[v];
    for(int i = 0; i< v; i++){
        a[i]=new int[v];
        for(int j=0;j<v;j++){
            a[i][j]=-1;
        }
    }
}

Grafo::~Grafo(){
    for(int i=0;i<v;i++){
        delete[] a[i];
    }
    delete[] a;
}

void Grafo::AgregarArista(int origen,int destino,int arista){
    if(origen >= 0 && origen < v && destino >=0 && destino <v){
        a[origen][destino] = arista;
    }
}

void Grafo::Mostrar(){
    for(int i = 0;i<v;i++){
        for(int j = 0; j<v; j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
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
        for(int j=0; j<v;j++){
            if(a[u][j] != -1 && !spt[j] && distancia[u] + a[u][j] < distancia[j]){
                distancia[j] = distancia[u] + a[u][j];
                padre[j] = u;
            }
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

    g.AgregarArista(0,1,2);
    g.AgregarArista(0,2,4);
    g.AgregarArista(1,2,1);
    g.AgregarArista(1,3,7);
    g.AgregarArista(2,4,3);
    g.AgregarArista(3,5,1);
    g.AgregarArista(4,3,2);
    g.AgregarArista(4,5,5);

    g.Mostrar();

    g.Dijkstra(0);

}