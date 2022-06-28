#include<iostream>
#include<queue>
using namespace std;

class Grafo{
    private:
        int v;
        int** a;
    public:
        Grafo(int);
        void agregar(int,int);
        void mostrar();
        void amplitud();
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

void Grafo::amplitud(){
    bool* visitado = new bool [v];
    for(int i=0; i<v; i++){
        visitado[i]=false;
    }
    queue <int> cola;
    int s=1;
    cola.push(s);
    visitado[s]=true;
    while(!cola.empty()){
        cout<<"["<<cola.front()<<"]->";
        cola.pop();
        for(int j=0;j<v;j++){
            if(a[s][j]==1 && !visitado[j]){
                cola.push(j);
                visitado[j] = true;
            }
        }
        s = cola.front();
    }
    cout<<"[Fin]"<<endl;
}

int main(){
    Grafo g1(7);

    g1.agregar(1,2);
    g1.agregar(2,1);
    g1.agregar(2,3);
    g1.agregar(3,2);
    g1.agregar(1,4);
    g1.agregar(4,1);
    g1.agregar(2,4);
    g1.agregar(4,2);
    g1.agregar(4,3);
    g1.agregar(3,4);
    g1.agregar(3,6);
    g1.agregar(6,3);
    g1.agregar(4,5);
    g1.agregar(5,4);
    g1.agregar(6,5);
    g1.agregar(5,6);

    g1.mostrar();

    cout<<"\nRecorrido Amplitud "<<endl;
    g1.amplitud();
}