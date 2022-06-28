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
        void agregarManual();
        void mostrar();
        void Dijkstra(int,int);
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

void Grafo::agregarManual(){
	bool terminado=false;
	int tam,id,importancia,caminos,origen,destino,distancia;
	cout<<"Ingrese la cantidad de ciudades a ingresar en el mapa: "<<endl;
	cin>>tam;
	char nombre[tam][30];
	Grafo g(tam);
	for(int i=0; i<tam; i++){
		system("cls");
		cout<<"Complete con los datos de la ciudad "<<i<<endl<<endl;
		cout<<"El ID asignado es: "<<i<<endl;
		id=i;
		cout<<"Ingrese el nombre: ";
		cin>>nombre[i];
		do{
            cout<<"Ingrese la importancia turistica (valor del 1 al 10): ";
    		cin>>importancia;
            if(importancia<1 || importancia>10)cout<<"\tSe pide valor del 1 al 10"<<endl;
        }while(importancia<1 || importancia>10);	
        
	}
	
	system("cls");
	cout<<"Ingrese la cantidad de caminos a ingresar en el mapa: "<<endl;
	cin>>caminos;
	for(int i=0; i<caminos; i++){
		system("cls");
		cout<<"Complete con los datos del camino "<<i<<endl;
		cout<<"teniendo en cuenta que el mapa tiene "<<tam<<" ciudades, y el grafo es el siguiente: "<<endl<<endl;
		g.mostrar();
		cout<<"\n\nOrigen: ";
		cin>>origen;
		cout<<"Destino: ";
		cin>>destino;
		cout<<"Distancia (en KM): ";
		cin>>distancia;	
        g.agregar(origen,destino,distancia);
	}
	g.mostrar();
	g.Dijkstra(origen,destino);
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
        cout<<"[ID: "<<i<<"] -> ";
        nodo* n = la[i];
        while (n != NULL){
            cout<<n->destino<<" | Distancia: "<<n->arista<<"km| - ";
            n=n->siguiente;
        }
        cout<<"Fin"<<endl;
    }
}

void Grafo::Dijkstra(int o, int d){
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
    cout<<"Distancias entre ID: "<<o<<" y todos"<<endl;
    for(int i=0;i<v;i++){
        cout<<"[ID: "<<o<<", ID:"<<d<<"] = "<<distancia[i]<<"\tPadre ID: "<<padre[i]<<endl;
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
	g.agregarManual();  
    
}
