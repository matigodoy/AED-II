#include<iostream>
#include<queue>
using namespace std;

class Grafo{
    private:
        int v;
        int** a;
        void profundidad(int, bool*);
    public:
        Grafo(int);
        void agregar(int,int);
        void mostrar();
        void topologico();
};

Grafo::Grafo(int v){
    this->v = v;
    a = new int*[v];
    for(int i = 0; i< v; i++){
        a[i]=new int[v];
        for(int j=0;j<v;j++){
            a[i][j]=0;
        }
    }
}

void Grafo::agregar(int origen,int destino){
    a[origen][destino]=1;
}

void Grafo::mostrar(){
    for(int i = 0;i<v;i++){
        for(int j = 0; j<v; j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void Grafo::topologico(){
    int* grado = new int [v];
    for(int i=0; i<v; i++){
        grado[i]=0;
    }
    for(int i=0; i<v; i++){
        for(int j=0;j<v;j++){
            if(a[i][j] == 1){
                grado[j] ++;
            }
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
        int s = cola.front();
        ot[visitados]=cola.front();
        cola.pop();
        visitados ++;
        for(int j=0;j<v;j++){
            if(a[s][j] == 1){
                grado[j] = grado[j] - 1;
                if(grado[j]==0){
                    cola.push(j);
                }
            }
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
    g.agregar(1,2);
    g.agregar(1,3);
    g.agregar(1,4);
    g.agregar(2,5);
    g.agregar(4,5);
    g.agregar(4,6);
    g.agregar(5,6);
    g.agregar(5,7);
    g.agregar(6,7);

    g.mostrar();

    cout<<"\nOrden Topologico "<<endl;
    g.topologico();
}