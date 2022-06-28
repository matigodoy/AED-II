#include<iostream>
#include"listag.h"
using namespace std;

int main(){
lista l;
int opc,opc2,inicio,final,peso,vertice;
char cont;
do{
system("cls");cout<<"\nMENU:\n\n1- Utilizar Grafo Pre-guardado\n2- Crear Grafo\n3- Crear Matriz de Adyacencia\n4- Crear Matriz de Caminos\n5- Mostar Lista de Nodos Adyacencentes\n6- Recorrido En Profundidad\n7- Recorrido En Anchura\n8- Mostar Matriz de Floyd\n9- Mostar Matriz de Warshall\n10- Salir\n\n Ingrese la opcion: ";cin>>opc;
switch(opc){
	case 1:
         system("cls");
		l.Insertarv(5);
		l.Insertarv(8);
		l.Insertarv(6);
		l.Insertarv(11);
		l.Insertarv(19);
		l.Insertarv(15);
		l.creararco(5,6,4);
		l.creararco(5,15,13);
		l.creararco(5,19,2);
		l.creararco(15,8,5);
		l.creararco(15,6,13);
		l.creararco(8,19,21);
		l.creararco(8,11,4);
		l.creararco(19,11,4);
		l.creararco(6,11,5);
		l.creararco(11,8,15);
	break;
	case 2:do{system("cls");cout<<"\nMENU:\n1- Nuevo Vertice\n2- Crear Arco\n\nIngrse la opcion: ";cin>>opc2;}while(opc2<1||opc>2);
		switch(opc2){
		case 1:system("cls");
			if(opc==1){
				l.BorrarListav();
			}
			do{system("cls");cont=' ';
                cout<<"\nIngrese el vertice: ";cin>>vertice;
                l.Insertarv(vertice);
                cout<<"\n\nDesea Ingresar Otro Vertice (S/N): ";cin>>cont;
			}while(cont!='n'&&cont!='N');break;
		break;
		case 2:
			do{
				cont=' ';
				system("cls");fflush(stdin);
				cout<<"\nIngrse el vertice de inicio: ";cin>>inicio;
				cout<<"\nIngrse el vertice de fin: ";cin>>final;
				cout<<"\nIngrse el peso: ";cin>>peso;
				l.creararco(inicio,final,peso);
				fflush(stdin);
				cout<<"\n\nDesea crear otro arco (S/N): ";cin>>cont;
			}while(cont!='n'&&cont!='N');break;
		}
	break;
	case 3:system("cls");
		if(l.ListavVacia()){cout<<"\n\nGrafo Vacio\n\n";}else{
		cout<<"\n\nMatriz de adyacencia"<<"\n\n";
		l.CrearMatrizAdyacencia();
		l.mostrarmatriz();}
	break;
	case 4:system("cls");
		if(l.ListavVacia()){cout<<"\n\nGrafo Vacio\n\n";}else{
		cout<<"\n\nMatriz de caminos\n\n";
		l.CrearMatrizCaminos();
		l.MostrarMatrizCaminos();}
	break;
	case 5:system("cls");
		if(l.ListavVacia()){cout<<"\n\nGrafo Vacio\n\n";}else{
		cout<<"\n\nVertices Adyacentes\n\n";
		l.Mostrarv();}
	break;
	case 6:system("cls");
		if(l.ListavVacia()){cout<<"\n\nGrafo Vacio\n\n";}else{
		cout<<"\n\nRecorrido Profundidad\n\n";
		l.RecorridoProfundidad();}
	break;
	case 7:system("cls");
		if(l.ListavVacia()){cout<<"\n\nGrafo Vacio\n\n";}else{
         cout<<"\n\nRecorrido Anchura\n\n";
		 l.RecorridoAnchura();}
    break;
	case 8:system("cls");
		if(l.ListavVacia()){cout<<"\n\nGrafo Vacio\n\n";}else{
		cout<<"\n\nFloyd\n\n";
		l.Floyd();}
	break;
	case 9:system("cls");
		if(l.ListavVacia()){cout<<"\n\nGrafo Vacio\n\n";}else{
		cout<<"\n\nWarshall\n\n";
		l.Warshall();break;}
}
cout<<"\n\n";system("pause");
}while(opc!=10);
return 0;
}
