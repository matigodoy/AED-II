#include<iostream>
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
        void G_Estrella();
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

        nodo* m = new nodo();
        m->destino = origen;
        m->siguiente = la[destino];
        la[destino] = m;
    }
}

void Grafo::mostrar(){
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

void Grafo::G_Estrella(){
    int* grado = new int [v];
    for(int i=0; i<v; i++){
        grado[i]=0;
    }
    for(int i=0; i<v; i++){
        nodo* n = la[i];
        while (n != NULL){
            grado[i]=grado[i] + 1;
            n=n->siguiente;
        }
    }

    int contador1=0;
    int contador2=0;
    for(int i=0; i<v; i++){
        if(grado[i] == 1)
            contador1++;
        else if(grado[i] == v-1)
            contador2++;
    }
    if(contador1 == v-1 && contador2 == 1){
        cout<<"\nEl grafo es una estrella"<<endl;
    }
    else{
        cout<<"\nEl grafo NO es una estrella"<<endl;
    }
}

int main(){
    Grafo g1(6);

    g1.agregar(0,1);
    g1.agregar(0,2);
    g1.agregar(0,3);
    g1.agregar(0,4);
    g1.agregar(0,5);
    //g1.agregar(1,2);

    g1.mostrar();

    g1.G_Estrella();
}