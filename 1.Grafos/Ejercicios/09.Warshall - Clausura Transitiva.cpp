#include<iostream>
using namespace std;

class Grafo{
    private:
        int v;
        int** a;
    public:
        Grafo(int);
        void agregar(int,int);
        void mostrar();
        void clausura();
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

void Grafo::clausura(){
    //creo una matriz nueva con los valores de a.
    int** m;
    m = new int*[v];
    for(int i = 0; i< v; i++){
        m[i]=new int[v];
        for(int j=0;j<v;j++){
            m[i][j]=a[i][j];
        }
    }

    //aplica el algoritmo.
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                m[i][j]=m[i][j] || (m[i][k] && m[k][j]);
            }
        }
    }

    //muestra la nueva matriz con el algoritmo aplicado.
    cout<<"\n\nMatriz de clausura transitiva \n"<<endl;
    for(int i = 0;i<v;i++){
        for(int j = 0; j<v; j++){
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main(){
    Grafo g1(4);

    g1.agregar(3,0);
    g1.agregar(1,3);
    g1.agregar(3,2);
    g1.agregar(1,2);
    g1.agregar(2,1);

    cout<<"Matriz de adyacencia \n"<<endl;
    g1.mostrar();

    g1.clausura();
}