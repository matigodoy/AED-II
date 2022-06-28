#include <iostream>
#include <climits>

using namespace std;

const int INFINITO = 99999;

class Grafo {
	private:
		int v; 
		int **a;
		int **sp; // Matriz de caminos mínimos
		void FloydWarshall();
	public:
		Grafo(int);
		~Grafo();
		void AgregarArista(int,int,int);
		void Mostrar();
		void MostrarFloydWarshall();
		
};

Grafo::Grafo(int v){
	this->v = v;
	this->a = new int* [v];
	for (int i = 0; i < v; i++){
		a[i] = new int[v];
		for (int j = 0; j < v; j++){
			a[i][j] = 0;
		}
	}
	
	this->sp = new int* [v];
	for (int i = 0; i < v; i++){
		sp[i] = new int[v];
		for (int j = 0; j < v; j++){
			sp[i][j] = 0;
		}
	}
}

Grafo::~Grafo(){
	for (int i = 0; i < v; i++)	{
		delete[] a[i];
		delete[] sp[i];
	}
	delete[] a;
	delete[] sp;
}

void Grafo::AgregarArista(int origen, int destino, int peso){
	if (origen > -1 && destino > -1 && origen < v && destino < v){
		a[origen][destino] = peso;
	} 
}

void Grafo::Mostrar(){
	cout << "Matriz de Adyacencia" << endl;
	for (int i = 0; i < v; i++){
		for (int j = 0; j < v; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;	
}

void Grafo::MostrarFloydWarshall(){
	FloydWarshall();
	cout << "Caminos Minimos" << endl;
	for (int i = 0; i < v; i++){
		for (int j = 0; j < v; j++){
			if (sp[i][j] == INFINITO)
				cout<<"- ";
			else
				cout<<sp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void Grafo::FloydWarshall(){
	for (int i = 0; i < v; i++){
		for (int j = 0; j < v; j++){
			if (a[i][j] > 0){
				sp[i][j] = a[i][j];
			}
			else{
				sp[i][j] = INFINITO;
			}
		}
	}

	for (int k = 0; k < v; k++){
		for (int i = 0; i < v; i++){
			for (int j = 0; j < v; j++){
				if (sp[i][k] + sp[k][j] < sp[i][j])
                    sp[i][j] = sp[i][k] + sp[k][j];
			}
		}
	}
}

int main(){
	Grafo g(6);
	g.AgregarArista(0,1,2);
    g.AgregarArista(0,2,4);
    g.AgregarArista(1,2,1);
    g.AgregarArista(1,3,7);
    g.AgregarArista(2,4,3);
    g.AgregarArista(3,5,1);
    g.AgregarArista(4,3,2);
    g.AgregarArista(4,5,5);

    	
	g.Mostrar();
	g.MostrarFloydWarshall();
	
	return 0;
}