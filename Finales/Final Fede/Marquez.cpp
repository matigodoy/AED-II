#include<iostream>
using namespace std;

struct Ciudad{
    int id;
    string nombre;
    int importancia;
};

struct Camino{
    int origen;
    int destino;
    int distancia;
};

class Mapa{
	private:
		int v;
		int a;
		int cam;
        int ciu;
		Camino* caminos;
        Ciudad* ciudades;
    public:
        Mapa(int,int);
        void agregarCiudad(int,string,int);
        void agregarCamino(int,int,int);
        void mostrarCiudades();
        void mostrarCaminos();
        void Distancia(int,int);
        int DistanciaMinima(int*,bool*);
};

Mapa::Mapa(int v, int a){
	this->v = v; //cantidad maxima de ciudades
	this->a = a; //cantidad maxima de caminos
	this->ciu = 0; //cantidad de ciudades
    this->cam = 0; //cantiadd de caminos
	this->ciudades = new Ciudad[v]; //vector de ciudades
    this->caminos = new Camino[a]; //vector de caminos
}

void Mapa::agregarCiudad(int id, string nombre, int importancia){
    this->ciudades[ciu].id = id;
    this->ciudades[ciu].nombre = nombre;
    this->ciudades[ciu].importancia = importancia;
    ciu++;
}

void Mapa::agregarCamino(int origen, int destino, int distancia){
    this->caminos[cam].origen = origen; //id de la ciudad.
    this->caminos[cam].destino = destino;
    this->caminos[cam].distancia = distancia;
    cam++;
}

void Mapa::mostrarCaminos(){
    cout<<"\nMostrar Caminos cargados: "<<endl;
    for(int i=0;i<cam;i++){
        cout<<"Origen: "<<caminos[i].origen<<endl;
        cout<<"Destino: "<<caminos[i].destino<<endl;
        cout<<"Distancia: "<<caminos[i].distancia<<endl<<endl;
    }
}

void Mapa::mostrarCiudades(){
    cout<<"\nMostrar Ciudades cargadas: "<<endl;
    for(int i=0;i<ciu;i++){
        cout<<"ID: "<<ciudades[i].id<<endl;
        cout<<"Nombre: "<<ciudades[i].nombre<<endl;
        cout<<"Importancia Turistica: "<<ciudades[i].importancia<<endl<<endl;
    }
}

void Mapa::Distancia(int origen,int destino){
    int* distancia = new int[ciu];
    bool* spt = new bool[ciu];
    int* padre = new int[ciu];
    for(int i=0;i<ciu;i++){
        padre[i]=0;
        spt[i]=false;
        distancia[i]=999999;
    }
    distancia[origen]=0;
    padre[origen]=-1;
    for(int i=0;i<ciu-1;i++){
        int u = DistanciaMinima(distancia,spt);
        spt[u] = true;
        for(int j=0;j<cam;j++){
            if(!spt[caminos[j].destino] && distancia[u] + caminos[j].distancia < distancia[caminos[j].destino]){
                distancia[caminos[j].destino] = distancia[u] + caminos[j].distancia;
                padre[caminos[j].destino] = u;
            }
        }
    }
    cout<<"Distancia entre ["<<ciudades[origen].nombre<<" y "<<ciudades[destino].nombre<<"] = "<<distancia[destino]<<endl;
}

int Mapa::DistanciaMinima(int* distancia,bool* spt){
    int menor=999999;
    int indicemenor=0;
    for(int i=0;i<ciu-1;i++){
        if(spt[i]==false && distancia[i]<=menor){
            menor=distancia[i],indicemenor = i;
        }
    }
    return indicemenor;
}

int main(){
    Mapa m(50,50); //cant de ciudades y recorridos maximos

    m.agregarCiudad(0,"Cordoba",7);
    m.agregarCiudad(1,"Mendoza",2);
    m.agregarCiudad(2,"CABS",5);
    m.agregarCiudad(3,"Rosario",6);
    m.agregarCiudad(4,"Carlos Paz",9);

    m.agregarCamino(0,1,728);
    m.agregarCamino(1,0,728);
    m.agregarCamino(1,2,1245);
    m.agregarCamino(2,1,1245);
    m.agregarCamino(0,3,45);
    m.agregarCamino(3,0,45);
    m.agregarCamino(3,4,405);
    m.agregarCamino(4,3,405);

    //m.mostrarCaminos();

    //m.mostrarCiudades();

    m.Distancia(0,1);

    m.Distancia(3,4);
}