#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
using namespace std;

struct nodo{
	int nodo1;
    int nodo2;
    int longitud;
	nodo* siguiente;
};
struct recorrido{
	int dato;
	recorrido* siguiente;
};

class Grafo{
    private:
        int v;
        int** distancia; //matriz con las distancias
        string** calle; //matriz con las calles
        nodo* valores; //inicio de la lista enlazada con las direcciones
        int* padre; //vector con los padres del recorrido de Dijkstra
        int* vecDistancia; //vector con las distancias minimas del recorrido de Dijkstra
    public:
        Grafo();
        void Dijkstra(int);
        int DistanciaMinima(bool*);
        void agregarValores(int,int,int);
        void algoritmo();
        void mostrarRecorrido(recorrido*,int);
        int total();
        void eliminar(recorrido*);
};

Grafo::Grafo(){
    this->v = 15; //cantidad de nodos
    distancia = new int*[v];
    calle = new string*[v];
    valores = NULL;
    padre = new int[v];
    vecDistancia = new int[v];
    system("Archivos.exe"); //llamamos al .exe que crea los archivos
    ifstream archivo1;
    archivo1.open("grafo.txt",ios::in);
    ifstream archivo2;
    archivo2.open("calles.txt",ios::in);
    for(int i = 0; i< v; i++){
        distancia[i]=new int[v];
        calle[i]=new string[v];
        for(int j=0;j<v;j++){
            archivo1>>distancia[i][j];
            archivo2>>calle[i][j];
        }
    }
    archivo1.close();
    archivo2.close();
}

void Grafo::Dijkstra(int origen){
    bool* spt = new bool[v];
    for(int i=0;i<v;i++){
        padre[i]=0;
        spt[i]=false;
        vecDistancia[i]=999999;
    }
    vecDistancia[origen]=0;
    padre[origen]=-1;
    for(int i=0;i<v-1;i++){
        int u = DistanciaMinima(spt);
        spt[u] = true;
        for(int j=0; j<v;j++){
            if(distancia[u][j] != -1 && !spt[j] && vecDistancia[u] + distancia[u][j] < vecDistancia[j]){
                vecDistancia[j] = vecDistancia[u] + distancia[u][j];
                padre[j] = u;
            }
        }
    }
}

int Grafo::DistanciaMinima(bool* spt){
    int menor=999999;
    int indicemenor=0;
    for(int i=0;i<v-1;i++){
        if(spt[i]==false && vecDistancia[i]<=menor){
            menor=vecDistancia[i],indicemenor = i;
        }
    }
    return indicemenor;
}

int Grafo::total(){
	nodo* n = valores;
	int total = 0;
	while(n != NULL){
		total ++;
		n = n->siguiente;
	}
	return total;
}

void Grafo::algoritmo(){
    int a=0;
    int h=total()+1;
    bool visitado[v];
    for(int j=1;j<v;j++){
        visitado[j] = false;
    }

    for(int i=0;i<h;i++){
        system("cls");
        Dijkstra(a);
        visitado[a]=true;
        nodo*n = valores;
        int menor=9999999;
        int indicemenor=0;
        while(n != NULL){
            if(vecDistancia[n->nodo1] < menor && visitado[n->nodo1] == false){
                menor = vecDistancia[n->nodo1];
                indicemenor = n->nodo1;
            }
            n = n->siguiente;
        }

        cout<<"Recorrido desde "<<a<<" hasta "<<indicemenor<<endl;
        recorrido* inicio = NULL;
        int dato = indicemenor;
        do{
            recorrido* nuevo = new recorrido();
            nuevo->dato = dato;
            nuevo->siguiente = inicio;
            inicio = nuevo;
            dato = padre[dato];
        }while(dato != padre[a]);

        recorrido* recor = inicio;
        while(recor != NULL){
            cout<<"["<<recor->dato<<"] --> ";
            recor=recor->siguiente;
        }
        cout<<"Destino"<<endl<<endl;

        mostrarRecorrido(inicio, indicemenor);
        eliminar(inicio);
        a=indicemenor;
    }
}

void Grafo::eliminar(recorrido* inicio){
    recorrido* n = inicio;
    while(n != NULL){
        recorrido* aux = n;
        n = aux->siguiente;
		delete aux;
    }
}

void Grafo::mostrarRecorrido(recorrido* n, int destino){
    int rojos[v];
    int recorridoTotal = 0;
    nodo* m = valores;
    if(destino != 0){
        while(m != NULL && m->nodo1 != destino){
            m = m->siguiente;
        }
    }
    ofstream archivo;
    archivo.open("RecorridoNoGucci.txt",ios::out);
    archivo<<"digraph grafico{\n\trankdir = LR"<<endl;
    while(n->siguiente != NULL){
        if(n->siguiente->dato == destino && destino != 0){
            archivo<<"\t"<<n->dato<<" -> "<<n->siguiente->dato<<"[color=red,label=."<<calle[n->dato][n->siguiente->dato]<<" ("<<distancia[n->dato][n->siguiente->dato]<<"mts).];"<<endl;
            rojos[n->dato] = n->siguiente->dato;
            recorridoTotal = recorridoTotal + distancia[n->dato][n->siguiente->dato];
            archivo<<"\t"<<n->siguiente->dato<<" -> Destino[color=red,label=."<<calle[n->siguiente->dato][m->nodo2]<<" ("<<m->longitud<<"mts).];"<<endl;
            archivo<<"\tDestino -> "<<m->nodo2<<"[label=."<<calle[n->siguiente->dato][m->nodo2]<<".];"<<endl;
            rojos[n->siguiente->dato] = m->nodo2;
            recorridoTotal = recorridoTotal + m->longitud;
        }
        else{
            archivo<<"\t"<<n->dato<<" -> "<<n->siguiente->dato<<"[color=red,label=."<<calle[n->dato][n->siguiente->dato]<<" ("<<distancia[n->dato][n->siguiente->dato]<<"mts).];"<<endl;
            rojos[n->dato] = n->siguiente->dato;
            recorridoTotal = recorridoTotal + distancia[n->dato][n->siguiente->dato];
        }
        n = n->siguiente;
    }
    cout<<"Distancia Total a Recorrer: "<<recorridoTotal<<"mts"<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(distancia[i][j] != -1 && rojos[i] != j){
                archivo<<"\t"<<i<<" -> "<<j<<"[label=."<<calle[i][j]<<".];"<<endl;
            }
        }
    }
    archivo<<"}"<<endl;
    archivo.close();
    system("arreglador1.cmd");
    system("arreglador2.cmd");
    system("Compilador.cmd");
    system("Recorrido.png");
    system("pause");
    //https://graphviz.org/download/ (Graficador).
    //https://stackoverrun.com/es/q/288707 (Batch).
}

void Grafo::agregarValores(int nodo1, int nodo2, int longitud){
    nodo* n = new nodo();
	n->nodo1 = nodo1;
    n->nodo2 = nodo2;
    n->longitud = longitud;
	n->siguiente = valores;
	valores = n;
}

int main(){
    Grafo g;

    g.agregarValores(8,6,57);
    g.agregarValores(3,4,35);
    g.agregarValores(12,11,29);
    g.agregarValores(13,2,41);

    g.algoritmo();
}