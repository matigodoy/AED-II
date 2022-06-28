#include<iostream>
using namespace std;

int suma(int** a,int n,int m){
    int s=0;
    for(int i = 0;i<n;i++){
        for(int j = 0; j<m; j++){
            s=a[i][j]+s;
        }
    }
    return s;
}

int main(){
    int n=0,m=0;
    cout<<"Ingrese la cantidad de filas: ";
    cin>>n;
    cout<<"Ingrese la cantidad de columnas: ";
    cin>>m;
    
    //crear
    int** a = new int*[n];
    for(int i = 0; i< n; i++){
        a[i]=new int[m];
    }

    //ingresar
    for(int i = 0;i<n;i++){
        for(int j = 0; j<m; j++){
            cout<<"Ingrese el elemento ["<<i<<"]["<<j<<"]: ";
            cin>>a[i][j];
        }
    }

    //imprimir
    for(int i = 0;i<n;i++){
        for(int j = 0; j<m; j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"La suma de los elementos es: "<<suma(a,n,m)<<endl;

    //borrar
    for(int i=0;i<n;i++){
        delete[] a[i];
    }
    delete[] a;
}