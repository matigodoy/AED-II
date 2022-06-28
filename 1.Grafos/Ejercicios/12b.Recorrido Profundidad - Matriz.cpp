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
        void profundidad();
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

void Grafo::profundidad(){
    bool* visitado = new bool [v];
    for(int i=0; i<v; i++){
        visitado[i]=false;
    }
    profundidad(0,visitado);
    cout<<"[Fin]"<<endl;
}

void Grafo::profundidad(int s,bool* visitado){
    cout<<"["<<s<<"]->";
    visitado[s]=true;
    for(int i=0;i<v;i++){
        if(a[s][i]==1 && !visitado[i])
        profundidad(i,visitado);
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