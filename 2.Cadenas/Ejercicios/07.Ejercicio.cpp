#include<iostream>

using namespace std;

void buscar(string texto){
    int n = texto.size();
    int i=0;

    cout<<"Texto antes de modificar: "<<endl;
    for(int k=0;k<n;k++)
        cout<<texto[k];

    while(i < n){
        for(int j=i+1;j<n;j++){
            if(texto[i]==texto[j] && texto[i] != '_' && texto[i] != ' '){
                texto[j] = '_';
            }
        }
        i++;
    }

    cout<<"\n\nTexto modificado: "<<endl;
    for(int k=0;k<n;k++)
        cout<<texto[k];

    return;
}

int main(){
    string texto = "universidad blas pascal";

    buscar(texto);

    return 0;
}