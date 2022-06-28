#include <iostream>
#include <algorithm>

using namespace std;

const int INFINITO = 99999;

struct Arista{
    int origen;
    int destino;
    int peso;
};

class Grafo {
	private:
		int v;
		int a;
		int na;
		Arista* aristas;
	public:
		Grafo(int,int);
		void AgregarArista(int,int,int);
		void Mostrar();
        void Prim(int);
        int DistanciaMinima(int*,bool*);
};

Grafo::Grafo(int v, int a){
	this->v = v;
	this->a = a;
	this->na = 0;
	this->aristas = new Arista[a];
}

void Grafo::AgregarArista(int origen, int destino, int peso){
	aristas[na].origen = origen;
	aristas[na].destino = destino;
	aristas[na].peso = peso;
	na++;
}

void Grafo::Mostrar(){
	cout << "Lista de Aristas" << endl;
	cout << "Origen\tDestino\tPeso" << endl;
	for (int i = 0; i < na; i++){
		cout << aristas[i].origen << "\t";
		cout << aristas[i].destino << "\t";
		cout << aristas[i].peso << "\n";
	}
	cout<<endl;
}

void Grafo::Prim(int origen){
    bool mst[v];
    int padre[v];
    int valor[v];
    for(int i=0;i<v;i++){
        mst[i] = false;
        padre[i] = -1;
        valor[i] = INFINITO;
    }
    valor[origen] = 0;
    for(int i=0;i<v-1;i++){
        int u = DistanciaMinima(valor,mst);
        mst[u] = true;
        for(int j=0;j<na;j++){
            if(aristas[j].origen == u && mst[aristas[j].destino] == false && aristas[j].peso < valor[aristas[j].destino]){
				valor[aristas[j].destino] = aristas[j].peso;
                padre[aristas[j].destino] = u;
            }
        }
    }
	int total=0;
    cout<<"Mostrar algoritmo de Prim "<<endl;
    for(int i=0;i<v;i++){
        cout<<padre[i]<<" --- "<<i<<" = "<<valor[i]<<endl;
		total = total + valor[i];
    }
	cout<<"Total: "<<total<<endl;
}

int Grafo::DistanciaMinima(int* distancia,bool* spt){
    int menor=INFINITO;
    int indicemenor=0;
    for(int i=0;i<v-1;i++){
        if(spt[i]==false && distancia[i]<menor){
            menor=distancia[i],indicemenor = i;
        }
    }
    return indicemenor;
}

int main(){
	Grafo g(9, 15);
	
	g.AgregarArista(0,1,4);
	g.AgregarArista(0,7,8);
	g.AgregarArista(1,2,8);  
	g.AgregarArista(1,7,11);
	g.AgregarArista(2,3,7);
	g.AgregarArista(2,5,4);
	g.AgregarArista(2,8,2);
	g.AgregarArista(3,4,9);
	g.AgregarArista(3,5,14);
	g.AgregarArista(4,5,10);
	g.AgregarArista(5,6,2);
	g.AgregarArista(6,8,6);
	g.AgregarArista(6,8,6);
	g.AgregarArista(6,7,1);
	g.AgregarArista(7,8,7);

	g.Mostrar();

	g.Prim(0);
	
	return 0;
}