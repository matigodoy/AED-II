#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Grafo{
    private:
        int v;
        int** distancia;
        string** calle;
    public:
        Grafo();
        void agregar(int,int,int,string);
        void guardar();
};

Grafo::Grafo(){
    this->v = 15; //cantidad de nodos
    distancia = new int*[v];
    calle = new string*[v];
    for(int i = 0; i< v; i++){
        distancia[i]=new int[v];
        calle[i]=new string[v];
        for(int j=0;j<v;j++){
            distancia[i][j] = -1;
            calle[i][j] = "-1";
        }
    }
}

//agregamos los nodos a las matrices
void Grafo::agregar(int origen,int destino,int longitud,string nombre){
    if(origen >= 0 && origen < v && destino >=0 && destino <v){
        distancia[origen][destino] = longitud;
        distancia[destino][origen] = longitud;
        calle[origen][destino] = nombre;
        calle[destino][origen] = nombre;
    }
}

//guardamos las matrices en los .txt
void Grafo::guardar(){
    ofstream archivo1;
    archivo1.open("grafo.txt",ios::out);
    for(int i = 0;i<v;i++){
        for(int j = 0; j<v; j++){
            archivo1<<distancia[i][j]<<endl;
        }
    }
    archivo1.close();
    ofstream archivo2;
    archivo2.open("calles.txt",ios::out);
    for(int i = 0;i<v;i++){
        for(int j = 0; j<v; j++){
            archivo2<<calle[i][j]<<endl;
        }
    }
    archivo2.close();
}

int main(){
    Grafo g;
    //int origen,int destino,int distancia, string nombre
    g.agregar(0,1,200,"Los_Eslovenos");
    g.agregar(0,2,200,"Los_Eslovenos");
    g.agregar(0,7,100,"Calle_D");
    g.agregar(1,3,100,"Calle_F");
    g.agregar(2,13,100,"Calle_A");
    g.agregar(3,4,100,"Calle_F");
    g.agregar(3,5,100,"Los_Ingleses");
    g.agregar(4,6,100,"Los_Libaneses");
    g.agregar(5,6,100,"Calle_E");
    g.agregar(5,7,100,"Los_Ingleses");
    g.agregar(6,8,100,"Los_Libaneses");
    g.agregar(7,8,100,"Calle_D");
    g.agregar(7,9,100,"Los_Ingleses");
    g.agregar(8,10,100,"Los_Libaneses");
    g.agregar(9,10,100,"Calle_C");
    g.agregar(9,11,100,"Los_Ingleses");
    g.agregar(10,12,100,"Los_Libaneses");
    g.agregar(11,12,100,"Calle_B");
    g.agregar(11,13,100,"Los_Ingleses");
    g.agregar(12,14,100,"Los_Libaneses");
    g.agregar(13,14,100,"Calle_A"); 

    g.guardar();
}