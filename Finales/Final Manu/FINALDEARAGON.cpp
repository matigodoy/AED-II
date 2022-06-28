#include<iostream>
#include<sstream>

using namespace std;

struct nodo{
	int destino;
    int arista;
	nodo* siguiente;
    int nombre;
    int IT;
    string nmbr;
};

class Mapa{
    private:
        int v;
        nodo** la;
    public:
        Mapa(int);
        ~Mapa();
        void agregar(int,int,int);
        void Camino(int,int);
        int Distancia(int*,bool*);
        void Ciudad(int,int,string);
};

Mapa::Mapa(int v){
    this->v = v;
    la = new nodo*[v];
    for(int i = 0; i< v; i++){
        la[i] = NULL;
    }
}

Mapa::~Mapa(){
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

void Mapa::agregar(int origen,int destino,int arista){
    if(origen >= 0 && origen < v && destino >=0 && destino <v){
        nodo* n = new nodo();       
        n->destino = destino;
        n->arista = arista;
        n->siguiente = la[origen];
        la[origen] = n;
    }
}

void Mapa::Camino(int o, int d){
    int* distancia = new int[v];
    bool* spt = new bool[v];
    int* padre = new int[v];
    for(int i=0;i<v;i++){
        padre[i]=0;
        spt[i]=false;
        distancia[i]=999999;
    }
    distancia[o]=0;
    padre[o]=-1;
    for(int i=0;i<v-1;i++){
        int u = Distancia(distancia,spt);
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
    cout<<"\nDistancia entre "<< o <<" y "<< d <<endl;
        cout<<"[ID:"<< o <<", ID:"<< d <<"] = "<<distancia[d]<<" KM"<<endl;
    
}

void Mapa::Ciudad(int id,int IT,string nmbr){
    if(id>-1 && IT>0 ){
        nodo* p = new nodo();       
        p->IT = IT; 
        p->nmbr = nmbr;
        cout<<"ID: "<< id <<" - Importancia Turistica: "<< IT << " - Nombre: "<< nmbr <<endl;
    }
}

int Mapa::Distancia(int* distancia,bool* spt){
    int menor=999999;
    int indice=0;
    for(int i=0;i<v-1;i++){
        if(spt[i]==false && distancia[i]<=menor){
            menor=distancia[i],indice = i;
        }
    }
    return indice;
}

int main(){
    Mapa m(5);

cout<<"Ciudades:\n"<<endl;

    m.Ciudad(0,10,"Cordoba");           //ESTRUCTURA CIUDAD===> (ID,IMPORTANCIA TURISTICA,NOMBRE)
    m.Ciudad(1,9,"Carlos Paz");
    m.Ciudad(2,8,"Agua de oro");
    m.Ciudad(3,7,"Jesus Maria");

cout<<"Distancia entre ciudades (analizadas a partir de su ID)\n"<<endl;

    m.agregar(0,1,2);                   //ESTRUCTURA CAMINO==> (ID ORIGEN,ID DESTINO,TAMAÑO)
    m.agregar(1,2,4);
    m.agregar(2,3,3);

    m.Camino(0,1);                      //SE ESCRIBE (ORIGEN,DESTINO) DEL CAMINO QUE DESEAMOS
    m.Camino(2,3);
    m.Camino(0,3);  
}
