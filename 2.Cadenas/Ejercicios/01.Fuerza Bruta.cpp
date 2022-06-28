#include<iostream>

using namespace std;

int buscar(string texto, string patron){
    int n = texto.size();
    int m = patron.size();

    int i=0;
    int j=0;

    while(i < n){
        if(texto[i] == patron[j]){
            i++;
            j++;
            if(j == m){
                cout<<"Hay una ocurrencia en: "<<i-m<<endl;
                j = 0;
                i = i - m + 1;
            }
        }
        else{
            i = i - j + 1;
            j=0;
        }
    }

    return -1;
}

int main(){
    string texto = "AABBAAACCBAABABAABA";
    string patron = "ABA";

    buscar(texto,patron);

    return 0;
}