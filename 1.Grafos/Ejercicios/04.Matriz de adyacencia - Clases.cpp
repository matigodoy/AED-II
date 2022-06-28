#include<iostream>
using namespace std;

class Grafo{
    private:
        int v;
        int** a;
        bool dirigido;
        bool ponderado;
    public:
        Grafo(int,bool,bool);
        ~Grafo();
        void AgregarArista(int,int,int);
        void Mostrar();
};

Grafo::Grafo(int v,bool dirigido,bool ponderado){
    this->v = v;
    this->dirigido = dirigido;
    this->ponderado = ponderado;
    a = new int*[v];
    for(int i = 0; i< v; i++){
        a[i]=new int[v];
        for(int j=0;j<v;j++){
            if(ponderado == true){
                a[i][j]=-1;
            }
            else{
                a[i][j]=0;
            }
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
        if(ponderado == true){
            a[origen][destino] = arista;
            if(!dirigido){ //si es un grafo no dirijido entra al if
                a[destino][origen] = arista;
            }
        }
        else{
            a[origen][destino] = 1;
            if(!dirigido){ //si es un grafo no dirijido entra al if
                a[destino][origen] = 1;
            }
        }
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

int main(){
    Grafo g1(4,true,true);
    Grafo g2(4,true,false);
    Grafo g3(4,false,true);
    Grafo g4(4,false,false);

    g1.AgregarArista(1,2,6);
    g2.AgregarArista(2,2,1);
    g3.AgregarArista(3,0,6);
    g4.AgregarArista(3,0,1);

    g1.Mostrar();
    cout<<"---------------------------"<<endl;
    g2.Mostrar();
    cout<<"---------------------------"<<endl;
    g3.Mostrar();
    cout<<"---------------------------"<<endl;
    g4.Mostrar();
}